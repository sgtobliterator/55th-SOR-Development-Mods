//////////////////////////
/////////////////
// Register CBA setting

["infinite_ammo_suppress_setting", "CHECKBOX", ["Infinite Ammo", "Determines if units will have infinite ammo while suppressing."], "Zeus enhancement: Target Position", true] call CBA_fnc_addSetting;

// Register CBA keys
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
["Zeus enhancement: Target Position", "open_tactical_menu", ["Tactical Menu", "Open the Zeus Tactical Menu"], {
    _this call jac_fn_open_tactical_menu
}, {
    _this call jac_fn_close_tactical_menu
}, [DIK_T, [false, false, false]]] call CBA_fnc_addKeybind;

["Zeus enhancement: Target Position", "draw_tactical_ruler", ["Tactical Ruler", "Draw tactical ruler"], {
    _this call {draw_ruler= true;}
}, {
    _this call {draw_ruler= false;}
}, [DIK_LSHIFT, [true, false, false]]] call CBA_fnc_addKeybind;


///// VARIABLES
z_mod=0;
pos_mod=0;
ruler_number=0; 
draw_ruler= false;
doOpenTacticalMenu=false;
tactical_menuID=-1;
mod_tactical_menu=0;
ai_feature_check=false;
is_in_range=false;
doOpenTacticalMenu=false;
suppressMaxRange=90000;

group_list= [];
group_control= [];
collision_line=[]; 
mouse_pos=[]; 
mouse_pos_og=[];
leader_pos= [];
tacticalMenu_mouse_pos= [];


////////// FUNCTIONS

//OPEN T MENU

jac_fn_open_tactical_menu = 
{
 unit_control_check= curatorSelected select 0;

 tacticalMenu_mouse_pos= (screenToWorld getMousePosition);
 tacticalMenu_mouse_pos= (AGLToASL tacticalMenu_mouse_pos);
	  
 _collision_line= lineIntersectsSurfaces [getPosASL curatorCamera, tacticalMenu_mouse_pos, objNull, objNull, true, 1, "VIEW", "FIRE"] # 0;
 if (count _collision_line !=0) then {tacticalMenu_mouse_pos= _collision_line # 0};
 
 mod_tactical_menu=1;
 tactical_menudata= []; 
 tactical_menudata= [["cancel"], ["suppress"]];

 ctrlTacticalMenuList= [];
  
 tactical_menuopen=false; 
 
 tactical_menuW=0.25; 
 tactical_menuH=0.038;
  
 tactical_menuID=-1;
 tMenuRow=0;
 mouse_pos= getMousePosition;  
 
  {   
  _ctrl = findDisplay 312 ctrlCreate ["RscButton", -1];
  
  ctrlTacticalMenuList pushBack _ctrl;
  
  _ctrl ctrlSetPosition [mouse_pos # 0,(((mouse_pos # 1) + 0.001) + ((0.038+0.0015)*tMenuRow)),tactical_menuW,tactical_menuH];
  
  _ctrl ctrlCommit 0;
  
  _ctrl ctrlSetText _x # 0;
  
  tMenuRow=tMenuRow+1;
  _ctrl ctrlAddEventHandler ["MouseEnter", {_t = (ctrlTacticalMenuList findIf {_x == _this # 0}); tactical_menuID = _t;}];
  _ctrl ctrlAddEventHandler ["MouseExit", {_t = (ctrlTacticalMenuList findIf {_x == _this # 0}); if (tactical_menuID == _t) then {tactical_menuID=-1};}];
  
  } forEach tactical_menudata;
};



//CLOSE TACTICAL MENU FUNCTION

jac_fn_close_tactical_menu = 
{

switch (tactical_menuID) do {

case 0: 
{
 unit_control_check= curatorSelected select 0; 
 
 { 
 group_control_check= group _x; 
 group_list pushBack group_control_check;   
 }forEach unit_control_check; 
  
  group_control = group_list arrayIntersect group_list; 
  group_list deleteRange [0, count group_list]; 
  { 
  hint "STOP!"; 
  commandStop  units _x; 
  
  _WPsupress_trigger = _x getVariable 'trigger_suppress_wp';
  _WPsupress_trigger setVariable ['delete_suppress_wp',true];
  
   _x spawn  
   { 
	for "_i" from count waypoints _this - 1 to 0 step -1 do
	{
	deleteWaypoint [_this, _i];
	};
   _my_wp= _this addWaypoint [getPosASL (leader _this), -1];
   _my_wp setWaypointDescription "delete_this";
   
   if (_this getVariable ['my_og_combat_mode_do_change',true]) then {
   _this setVariable ['my_og_combat_mode_do_change',false];
   _this setVariable ['my_og_combat_mode',(CombatMode _this)];
   _this setCombatMode "BLUE";   
   };
   
   sleep 1;
   _this setCombatMode (_this getVariable ['my_og_combat_mode',"YELLOW"]);
   _this setVariable ['my_og_combat_mode_do_change',true];
   
   units _this doFollow leader _this;   
   _i=(currentWaypoint _this);
   _my_wp=[_this,_i];
   if (waypointDescription _my_wp == "delete_this") then {deleteWaypoint _my_wp};
   }; 
  }forEach group_control;
};

case 1: 
{
 unit_control_check= curatorSelected select 0;
 
 {
 group_control_check= group _x;
 group_list pushBack group_control_check;
 }forEach unit_control_check;
 group_control = group_list arrayIntersect group_list;
 group_list deleteRange [0, count group_list];
 
 pos_mod=tacticalMenu_mouse_pos select 2;
 pos_mod=pos_mod+z_mod;
 tacticalMenu_mouse_pos set [2,pos_mod];
 tacticalMenu_mouse_pos_og= +tacticalMenu_mouse_pos;
 
 if (count group_control >0)  then
 {
 hintSilent "SUPRESSIVE FIRE!";
 };

  {
  leader_pos=eyePos leader _x;
  pos_mod=leader_pos select 2;
  pos_mod=pos_mod;
  leader_pos set [2,pos_mod];
  
  collision_line= lineIntersectsSurfaces 
  [leader_pos, tacticalMenu_mouse_pos, leader _x, vehicle (leader _x), true, 1, "VIEW", "NONE", true] select 0;
  if (count collision_line !=0) then
  {
  pos_mod=collision_line select 0 select 2;
  pos_mod=pos_mod+z_mod;
  tacticalMenu_mouse_pos set [0, collision_line select 0 select 0];
  tacticalMenu_mouse_pos set [1, collision_line select 0 select 1];
  tacticalMenu_mouse_pos set [2, pos_mod];  
  }
  else
  {
  tacticalMenu_mouse_pos= +tacticalMenu_mouse_pos_og;
  };
  
  _grp=_x;
  _wp = _grp addWaypoint [tacticalMenu_mouse_pos, -1, (count (waypoints _grp))+1, "SUPRESSIVE FIRE"];
  _wp setWaypointType "SCRIPTED";
  _wp setWaypointStatements [wp_SUPPRESScond,wp_SUPPRESSscript];
  _wp setWaypointDescription "SUPRESSIVE FIRE";
  
  _WPsupress_trigger = _grp getVariable 'trigger_suppress_wp';
  _WPsupress_trigger setVariable ['delete_suppress_wp',true];
  
	_x spawn {
		if (_this getVariable ['my_og_combat_mode_do_change',true]) then {
		_this setVariable ['my_og_combat_mode_do_change',false];
		_this setVariable ['my_og_combat_mode',(CombatMode _this)];
		_this setCombatMode "BLUE";   
		};
   
		sleep 1;
		_this setCombatMode (_this getVariable ['my_og_combat_mode',"YELLOW"]);
		_this setVariable ['my_og_combat_mode_do_change',true];
	};
  
  }forEach group_control;
};

};

// close tactical menu
mod_tactical_menu=0;
{
ctrlDelete _x;
} forEach ctrlTacticalMenuList;

};


/////// WP arguments

wp_SUPPRESScond=" 

_p1=(group this);  
_target_g= getWPPos [_p1,(currentWaypoint _p1)]; 
_p1 setVariable ['suppress_target_wp',_target_g]; 
(this distance (_target_g) <= suppressMaxRange); 
 
"; 

wp_SUPPRESSscript="  
  
  _grp= group this; 
  _target_g= _grp getVariable 'suppress_target_wp'; 
  
  _azimuth = (leader _grp) getDir _target_g;
  _grp setFormDir _azimuth;
	
  _supress_target= 'Land_TacticalBacon_F' createVehicle _target_g;
  _supress_target setPos _target_g; 
  _supress_target enablesimulation false; 
  _supress_target hideObject true;

    [   
		[_supress_target],   
		{
		_supress_target_arg= (_this # 0);
		{_x addCuratorEditableObjects [[_supress_target_arg],true]} forEach allCurators;
		}
    ] remoteExecCall ['call', 2];
   
  _WPsupress_trigger= createTrigger ['EmptyDetector', [0,0]];
  _WPsupress_trigger setVariable ['delete_suppress_wp',false];
  _WPsupress_trigger setVariable ['suppress_target_wp_grp',_grp];
  _WPsupress_trigger setVariable ['suppress_target_wp_obj',_supress_target];
  _WPsupress_trigger setTriggerStatements [wp_SUPPRESStrigger, '', ''];
   
  _grp setVariable ['trigger_suppress_wp',_WPsupress_trigger];

"; 

wp_SUPPRESStrigger=" 

_grp= thisTrigger getVariable 'suppress_target_wp_grp'; 
if ((thisTrigger getVariable ['delete_suppress_wp',false]) or ({alive _x} count units _grp) == 0) then {  
 [   
   [thisTrigger],   
   { 
    deleteVehicle ((_this # 0) getVariable 'suppress_target_wp_obj'); 
    deleteVehicle (_this # 0);
   }  
 ] remoteExecCall ['call', 0];
};

{ 
	if ((alive _x) and (currentCommand _x != 'Suppress') and (unitCombatMode _x != 'BLUE')) then
    {
		_temp_my_vehicle= (vehicle _x);
		_temp_my_vehicle setEffectiveCommander (gunner _temp_my_vehicle);
		_target_g= thisTrigger getVariable 'suppress_target_wp_obj'; 
		if (infinite_ammo_suppress_setting) then {_temp_my_vehicle setVehicleAmmo 1};
		_x doSuppressiveFire _target_g;
	};
} forEach units _grp;

";



/////////////// DRAW TACTICAL RULER

addMissionEventHandler ["Draw3D",  
{
 if (draw_ruler) then 
 {
 _handled = true; 
 ruler_number=0; 
 _ruler_distance=0; 
  
 unit_control_check= curatorSelected select 0; 
  
 { 
 group_control_check= group _x;
 group_list pushBack group_control_check; 
 }forEach unit_control_check; 
 group_control = group_list arrayIntersect group_list; 
 group_list deleteRange [0, count group_list]; 
  
 mouse_pos= screenToWorld getMousePosition;
 mouse_pos= AGLToASL mouse_pos;
	  
 _collision_line= lineIntersectsSurfaces [getPosASL curatorCamera, mouse_pos, objNull, objNull, true, 1, "VIEW", "FIRE"] # 0;
 if (count _collision_line !=0) then {mouse_pos= _collision_line # 0};
 
 pos_mod=mouse_pos select 2; 
 pos_mod=pos_mod+z_mod;
 mouse_pos set [2,pos_mod];
 mouse_pos_og= +mouse_pos;
  
  { 
  if (ruler_number == 8) exitWith{_handled}; 
 
  leader_pos=eyePos leader _x;
  pos_mod=leader_pos select 2;
  pos_mod=pos_mod;
  leader_pos set [2,pos_mod];
   
  collision_line= lineIntersectsSurfaces
  [leader_pos, mouse_pos, leader _x, vehicle (leader _x), true, 1, "VIEW", "NONE", true] select 0; 
  if (count collision_line !=0) then 
  { 
  pos_mod=collision_line select 0 select 2; 
  pos_mod=pos_mod+z_mod; 
  mouse_pos set [0, collision_line select 0 select 0]; 
  mouse_pos set [1, collision_line select 0 select 1]; 
  mouse_pos set [2, pos_mod];   
  } 
  else 
  { 
  mouse_pos= +mouse_pos_og; 
  }; 
   
  mod_group= units _x; 
   { 
     if (_forEachIndex == 0) then 
  { 
  _ruler_distance=ceil (ASLToAGL leader_pos distance ASLToAGL mouse_pos); 
   
  drawIcon3D ["\A3\ui_f\data\map\markers\military\destroy_CA.paa", [1,0,0,1], ASLToAGL mouse_pos, 1, 1, 1, format [" %1",_ruler_distance] , 1, 0.05, "PuristaMedium"];
  drawLine3D [ASLToAGL leader_pos, ASLToAGL mouse_pos, [1,0,0,1]]; 
     }; 
   }forEach mod_group; 
  ruler_number=ruler_number+1;
  }forEach group_control; 
 }; 

_handled; 
}];































