// Hit & Run waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Group engages, breaks contact, retreats, and repeats indefinitely.
params ["_group", "_position"];
[_group, _position, 200] spawn FOD_ZA_fnc_taskHitAndRun;
