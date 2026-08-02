// Support Vehicle waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Vehicle anchors onto the nearest allied group near the waypoint position and follows/supports it from a distance.
params ["_group", "_position"];
[_group, _position, 60] call FOD_ZA_fnc_taskSupportVehicleToggle;
