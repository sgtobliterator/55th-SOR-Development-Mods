// Reserve/QRF waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Group holds at current position until enemy contact, then rushes.
params ["_group", "_position"];
[_group, 200] spawn FOD_ZA_fnc_taskReserve;
