// FOD: Setup Ambush waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Uses taskEntrench with stealth/ambush mode enabled.
params ["_group", "_position"];
[_group, _position, 100, [], false, 0, true, false] spawn FOD_ZA_fnc_taskEntrench;
