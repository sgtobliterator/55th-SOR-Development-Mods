// Mobilize QRF waypoint script
// Called by ZEN when the waypoint is reached by a group.
// Group mounts its transport and rushes to the waypoint position, dismounting and splitting off vehicle crew on arrival.
params ["_group", "_position"];
[_group, _position, 30] spawn FOD_ZA_fnc_taskMobilizeQRF;
