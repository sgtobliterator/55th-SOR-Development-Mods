// Tactical Push waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Group bounds toward the waypoint position, taking cover and returning fire when shot at.
params ["_group", "_position"];
[_group, _position, 25, 40] spawn FOD_ZA_fnc_taskTacticalPush;
