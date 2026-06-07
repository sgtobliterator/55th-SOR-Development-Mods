disableserialization;
params[["_obj", objNull], ["_point", objNull], ["_types", ["Auto"]], ["_sides", ["ALL"]], ["_range", 10], ["_marker", false], ["_script", ""]];

_pointName = format ["%1", _point];
// systemChat str _pointName;
missionNamespace setVariable [format["Garage_Script_%1", _pointName], _script];

_arrayGround = ["Car", "Tank", "Helicopter", "Plane", "StaticWeapon"];


// === Garage Modes ===
// 0 = Vanilla BI list
// 1 = Whitelist mode (only in _whitelist)
// 2 = Blacklist mode (all except _blacklist)
private _garageMode = GPs_useListType;

// Whitelist array
private _whitelist = GPs_vehicleList_All;

// Blacklist array
private _blacklist = GPs_vehicleList_All;


//If Auto, set array depending on the point's surface.
switch (_types select 0) do {
  case "Auto": {
    _types = [_arrayGround, ["Ship"]] select (surfaceIsWater (getPos _point));
  };
  case "Ground": {
    _types = _arrayGround;
  };
  case "All": {
    _types = ["Car", "Tank", "Helicopter", "Plane", "Ship", "StaticWeapon"];
  };
};



if (_marker) then {

  //Change icon
  _markerDesign = "respawn_unknown";
  if (count _types == 1) then {
    _markerDesign = switch (_types select 0) do {
      case "Car": {
        "respawn_motor";
      };
      case "Tank": {
        "respawn_armor";
      };
      case "Helicopter": {
        "respawn_air";
      };
      case "Plane": {
        "respawn_plane";
      };
      case "Ship": {
        "respawn_naval";
      };
      default {
        "respawn_unknown";
      };
    };
  };

    //Set markers
    _markerRange = createMarker [format["Marker_%1_Range", _pointName], _point];
    _markerRange setMarkerShape "ELLIPSE";
    _markerRange setMarkerSize [20,20];

    _markerPointName = ((_pointName splitString "_")-["GP"]) joinString " ";
    _markerName = createMarker [format["Marker_%1_Name", _pointName], _point];
    _markerName setMarkerText _markerPointName;
    _markerName setMarkerType _markerDesign;

};

// Wrap addActions in remoteExec to ensure all clients get them (and JIP)
[[_obj, _point, _types, _sides, _range, _marker], {
    params [["_obj", objNull], ["_point", objNull], ["_types", ["Auto"]], ["_sides", ["ALL"]], ["_range", 10], ["_marker", false]];

    // Open Garage action
    if (isNil {_obj getVariable "KBF_garageOpenActionID"}) then {
        private _garageOpenActionID = _obj addAction [
            "<img size='2' image='a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacegarage_ca.paa'/> <t size='2' >Open Garage</t>",
            {
                _params = _this select 3;
                _sides = _params select 2;

                _sideText = switch (side player) do {
                    case west; case blufor : {"BLUFOR"};
                    case east; case opfor : {"OPFOR"};
                    case independent; case resistance : {"INDEP"};
                    case civilian : {"CIV"};
                    default {"NONE"};
                };

                if ((_sides select 0) == "ALL" || _sideText in _sides) then {
                    [_params select 0, _params select 1] call kbf_fnc_garageLoad;
                } else {
                    ["this spawner is Disabled on your side."] call BIS_fnc_guiMessage;
                };
            },
            [_point, _types, _sides],
            1.5,
            true,
            true,
            "",
            "true",
            _range
        ];
        _obj setVariable ["KBF_garageOpenActionID", _garageOpenActionID, false];
    };

    // Delete Vehicles action
    if (isNil {_obj getVariable "KBF_garageDeleteActionID"}) then {
        private _garageDeleteActionID = _obj addAction [
            "<img size='2' image='a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa'/> <t size='2' >Delete Vehicles</t>",
            {
                _vehicles = ((_this select 3) nearObjects ["AllVehicles", 20]) + ((_this select 3) nearObjects ["#particlesource", 20]);
                {
                    _nowvehicle = _x;
                    _vehVarName = vehicleVarName _nowvehicle;
                    _defaultVeh = "DFV" in (_vehVarName splitString "_");
                    if (!(_x isKindOf "Man") && !_defaultVeh) then {
                        {_nowvehicle deleteVehicleCrew _x} forEach crew _nowvehicle;
                        deleteVehicle _x;
                    };
                } forEach _vehicles;
            },
            _point,
            1.5,
            true,
            true,
            "",
            "true",
            _range
        ];
        _obj setVariable ["KBF_garageDeleteActionID", _garageDeleteActionID, false];
    };

    // Reset Garage Flag action
    if (isNil {_obj getVariable "KBF_garageResetActionID"}) then {
        private _garageResetActionID = _obj addAction [
            "<img size='2' image='x\zen\addons\inventory\ui\reset_ca.paa'/> <t color='#00FF00' size='2' >Reset Garage Flag</t>",
            {
                _marker = vehicleVarName (_this select 3);
                missionNamespace setVariable [format ["Open_Garage_%1", _marker], false, true];
            },
            _point,
            1.5,
            true,
            true,
            "",
            "true",
            _range
        ];
        _obj setVariable ["KBF_garageResetActionID", _garageResetActionID, false];
    };
}] remoteExec ['spawn', 0, true]; // 0 = all clients, true = JIP
