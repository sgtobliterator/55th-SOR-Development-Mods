#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Scans CfgVehicles for editor-visible infantry and groups them by
 * (factionClass, vehicleClass) pair into "sub-factions". Each sub-faction
 * becomes one dropdown entry in a zone-settings dialog.
 *
 * Single scan, dual cache:
 *   - Military (side in {0,1,2}): blacklist + weapons > 2 + officer
 *     tracking. Stored in GVAR(subFactions).
 *   - Civilian (side == 3):       blacklist + weapons <= 2 (no
 *     paramilitary leakage). No officer tracking. Stored in
 *     GVAR(subFactionsCivilian).
 *
 * No filtering by vehicleClass -- every sub-group is exposed so the
 * mission maker can pick exactly the look they want (e.g. 3CB camo
 * variants, Combat Patrol DLC duplicates, story characters).
 *
 * Cache key: "factionClass:vehicleClass".
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Military sub-faction cache keyed by composite id <HASHMAP>
 *
 * Example:
 * [] call digii_ambient_factions_fnc_enumerateSubFactions
 *
 * Public: No
 */

private _start = diag_tickTime;
private _cfgVehicles = configFile >> "CfgVehicles";

private _allInfantry = "
    isClass _x &&
    {getNumber (_x >> 'scope') == 2} &&
    {(configName _x) isKindOf ['CAManBase', _cfgVehicles]}
" configClasses _cfgVehicles;

private _sideTable = [east, west, independent];
private _sideTags  = createHashMapFromArray [[east, "EAST"], [west, "WEST"], [independent, "GUER"], [civilian, "CIV"]];
private _officerBases = ["B_officer_F", "O_officer_F", "I_officer_F"];

private _map    = createHashMap;
private _civMap = createHashMap;

{
    private _cfg = _x;
    private _class = configName _cfg;

    private _factionClass = getText (_cfg >> "faction");
    if (_factionClass == "") then { continue };

    private _sideNum = getNumber (_cfg >> "side");
    if (!(_sideNum in [0, 1, 2, 3])) then { continue };
    private _isCivilian = _sideNum == 3;
    private _side = if (_isCivilian) then { civilian } else { _sideTable select _sideNum };

    // Skip story/VR/ghillie/diver/pilot/uav/unarmed/etc. — these are visual,
    // specialist, or unarmed variants that don't fit ambient-population use.
    // Mirrors ZEI's substring filter (script_component UNIT_CLASS_BLACKLIST).
    // Applied to both military and civilian classes as a safety net.
    private _classLower = toLower _class;
    private _blacklisted = false;
    {
        if (_classLower find _x >= 0) exitWith { _blacklisted = true };
    } forEach UNIT_CLASS_BLACKLIST;
    if (_blacklisted) then { continue };

    // Weapons filter — direction depends on kind. The weapons array always
    // carries "Throw" and "Put" as muzzle entries, so the meaningful threshold
    // is count vs 2.
    //   Military: count > 2  (at least one real primary/secondary/sidearm)
    //   Civilian: count <= 2 (no real weapons; keeps armed paramilitary
    //                        classes that some mods file under civilian
    //                        from leaking in)
    private _weaponsCount = count getArray (_cfg >> "weapons");
    if (_isCivilian) then {
        if (_weaponsCount > 2) then { continue };
    } else {
        if (_weaponsCount <= 2) then { continue };
    };

    // Prefer modern editorSubcategory (matches Eden); fall back to legacy vehicleClass
    private _subcategory = getText (_cfg >> "editorSubcategory");
    if (_subcategory == "") then { _subcategory = getText (_cfg >> "vehicleClass") };
    if (_subcategory == "") then { _subcategory = "Men" };

    private _id = format ["%1:%2", _factionClass, _subcategory];
    private _targetMap = if (_isCivilian) then { _civMap } else { _map };

    private _entry = _targetMap getOrDefault [
        _id,
        createHashMapFromArray [
            ["id", _id],
            ["factionClass", _factionClass],
            ["factionDisplay", getText (configFile >> "CfgFactionClasses" >> _factionClass >> "displayName")],
            ["subcategory", _subcategory],
            ["subcategoryDisplay", ""],
            ["side", _side],
            ["units", []],
            ["officers", []],
            ["label", ""]
        ],
        true
    ];

    (_entry get "units") pushBack _class;

    // Officer detection is military-only; civilians don't carry officers.
    if (!_isCivilian) then {
        private _isOfficer = (_officerBases findIf { _class isKindOf [_x, _cfgVehicles] }) > -1;
        if (!_isOfficer) then {
            private _dn = toLower getText (_cfg >> "displayName");
            if (("officer" in _dn) || {"leader" in _dn}) then {
                _isOfficer = true;
            };
        };
        if (_isOfficer) then {
            (_entry get "officers") pushBack _class;
        };
    };
} forEach _allInfantry;

// Pass 2: resolve subcategory displayName + pre-render labels. Same logic
// for both maps; iterate them together.
private _renderLabels = {
    params ["_targetMap", "_tags"];
    {
        private _entry = _y;

        private _factionDisp = _entry get "factionDisplay";
        if (_factionDisp == "") then { _factionDisp = _entry get "factionClass" };

        private _subcat = _entry get "subcategory";
        private _subcatDisp = getText (configFile >> "CfgEditorSubcategories" >> _subcat >> "displayName");
        if (_subcatDisp == "") then { _subcatDisp = getText (configFile >> "CfgVehicleClasses" >> _subcat >> "displayName") };
        if (_subcatDisp == "") then { _subcatDisp = _subcat };

        _entry set ["factionDisplay", _factionDisp];
        _entry set ["subcategoryDisplay", _subcatDisp];
        _entry set ["label", format [
            "[%1] %2 - %3",
            _tags getOrDefault [_entry get "side", "?"],
            _factionDisp,
            _subcatDisp
        ]];
    } forEach _targetMap;
};

[_map,    _sideTags] call _renderLabels;
[_civMap, _sideTags] call _renderLabels;

GVAR(subFactions)         = _map;
GVAR(subFactionsCivilian) = _civMap;

private _elapsed = round ((diag_tickTime - _start) * 1000);
INFO_3("Enumerated %1 military + %2 civilian sub-factions in %3 ms",count _map,count _civMap,_elapsed);

_map
