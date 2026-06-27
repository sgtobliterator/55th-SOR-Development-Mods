/*
    Restricted Arsenal Classname Extractor  (Arma 3)
    -------------------------------------------------
    Reads every weapon, magazine, item, and backpack loaded into a
    storage container and copies the classnames to your clipboard as
    quoted entries separated by commas (no brackets, no dividers).

    USAGE
      1. Spawn / load the box (editor or live server).
      2. Open the Debug Console:  Esc  >  Debug Console.
      3. (Optional) edit the CONFIG block below.
      4. Press "LOCAL EXEC".
      5. Ctrl+V into your arsenal .sqf  (the result is on your clipboard).
*/

// ============================ CONFIG ============================
private _box      = cursorObject;   // or:  myArsenalBox   /   (missionNamespace getVariable "myBox")
private _sortList = true;           // alphabetical sort
// ================================================================

if (isNull _box) exitWith {
    hint "No container found.\nLook directly at the box, or set _box manually in the script.";
    systemChat "[Arsenal Extractor] _box is null - nothing copied.";
};

private _all = (weaponCargo _box) + (magazineCargo _box) + (itemCargo _box) + (backpackCargo _box);

private _unique = [];
{ _unique pushBackUnique _x } forEach _all;
if (_sortList) then { _unique sort true };

private _lines  = _unique apply { format ["""%1""", _x] };
private _output = _lines joinString ("," + endl);

copyToClipboard _output;

hint format ["Copied %1 unique classnames to your clipboard.", count _unique];
systemChat format ["[Arsenal Extractor] %1 unique classnames copied.", count _unique];
