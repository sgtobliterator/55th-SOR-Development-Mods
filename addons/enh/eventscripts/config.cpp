class CfgPatches
{
	class 3denEnhanced_EventScripts
	{
		author="R3vo";
		name="3den Enhanced - Event Scripts";
		requiredAddons[]=
		{
			"3denEnhanced"
		};
		requiredVersion=2.1800001;
		url="https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
		units[]={};
		weapons[]={};
	};
};
class Cfg3DEN
{
	class EventHandlers
	{
		class ENH_EventScripts
		{
			onBeforeMissionPreview="if (fileExists "".enh_eventScripts\onBeforeMissionPreview.sqf"") then {call compileScript ["".enh_eventScripts\onBeforeMissionPreview.sqf""]}";
			onConnectingEnd="if (fileExists "".enh_eventScripts\onConnectingEnd.sqf"") then {call compileScript ["".enh_eventScripts\onConnectingEnd.sqf""]}";
			onConnectingStart="if (fileExists "".enh_eventScripts\onConnectingStart.sqf"") then {call compileScript ["".enh_eventScripts\onConnectingStart.sqf""]}";
			onCopy="if (fileExists "".enh_eventScripts\onCopy.sqf"") then {call compileScript ["".enh_eventScripts\onCopy.sqf""]}";
			onCut="if (fileExists "".enh_eventScripts\onCut.sqf"") then {call compileScript ["".enh_eventScripts\onCut.sqf""]}";
			onDeleteUnits="if (fileExists "".enh_eventScripts\onDeleteUnits.sqf"") then {call compileScript ["".enh_eventScripts\onDeleteUnits.sqf""]}";
			onEditableEntityAdded="if (fileExists "".enh_eventScripts\onEditableEntityAdded.sqf"") then {call compileScript ["".enh_eventScripts\onEditableEntityAdded.sqf""]}";
			onEditableEntityRemoved="if (fileExists "".enh_eventScripts\onEditableEntityRemoved.sqf"") then {call compileScript ["".enh_eventScripts\onEditableEntityRemoved.sqf""]}";
			onEntityAttributeChanged="if (fileExists "".enh_eventScripts\onEntityAttributeChanged.sqf"") then {call compileScript ["".enh_eventScripts\onEntityAttributeChanged.sqf""]}";
			onEntityDragged="if (fileExists "".enh_eventScripts\onEntityDragged.sqf"") then {call compileScript ["".enh_eventScripts\onEntityDragged.sqf""]}";
			onEntityMenu="if (fileExists "".enh_eventScripts\onEntityMenu.sqf"") then {call compileScript ["".enh_eventScripts\onEntityMenu.sqf""]}";
			onEntityParentChanged="if (fileExists "".enh_eventScripts\onEntityParentChanged.sqf"") then {call compileScript ["".enh_eventScripts\onEntityParentChanged.sqf""]}";
			onGridChange="if (fileExists "".enh_eventScripts\onGridChange.sqf"") then {call compileScript ["".enh_eventScripts\onGridChange.sqf""]}";
			onHistoryChange="if (fileExists "".enh_eventScripts\onHistoryChange.sqf"") then {call compileScript ["".enh_eventScripts\onHistoryChange.sqf""]}";
			onMapClosed="if (fileExists "".enh_eventScripts\onMapClosed.sqf"") then {call compileScript ["".enh_eventScripts\onMapClosed.sqf""]}";
			onMapOpened="if (fileExists "".enh_eventScripts\onMapOpened.sqf"") then {call compileScript ["".enh_eventScripts\onMapOpened.sqf""]}";
			onMessage="if (fileExists "".enh_eventScripts\onMessage.sqf"") then {call compileScript ["".enh_eventScripts\onMessage.sqf""]}";
			onMissionAttributeChanged="if (fileExists "".enh_eventScripts\onMissionAttributeChanged.sqf"") then {call compileScript ["".enh_eventScripts\onMissionAttributeChanged.sqf""]}";
			onMissionAutosave="if (fileExists "".enh_eventScripts\onMissionAutosave.sqf"") then {call compileScript ["".enh_eventScripts\onMissionAutosave.sqf""]}";
			onMissionExportMP="if (fileExists "".enh_eventScripts\onMissionExportMP.sqf"") then {call compileScript ["".enh_eventScripts\onMissionExportMP.sqf""]}";
			onMissionExportSP="if (fileExists "".enh_eventScripts\onMissionExportSP.sqf"") then {call compileScript ["".enh_eventScripts\onMissionExportSP.sqf""]}";
			onMissionListChange="if (fileExists "".enh_eventScripts\onMissionListChange.sqf"") then {call compileScript ["".enh_eventScripts\onMissionListChange.sqf""]}";
			onMissionLoad="if (fileExists "".enh_eventScripts\onMissionLoad.sqf"") then {call compileScript ["".enh_eventScripts\onMissionLoad.sqf""]}";
			onMissionNew="if (fileExists "".enh_eventScripts\onMissionNew.sqf"") then {call compileScript ["".enh_eventScripts\onMissionNew.sqf""]}";
			onMissionPreview="if (fileExists "".enh_eventScripts\onMissionPreview.sqf"") then {call compileScript ["".enh_eventScripts\onMissionPreview.sqf""]}";
			onMissionPreviewEnd="if (fileExists "".enh_eventScripts\onMissionPreviewEnd.sqf"") then {call compileScript ["".enh_eventScripts\onMissionPreviewEnd.sqf""]}";
			onMissionSave="if (fileExists "".enh_eventScripts\onMissionSave.sqf"") then {call compileScript ["".enh_eventScripts\onMissionSave.sqf""]}";
			onMissionSaveAs="if (fileExists "".enh_eventScripts\onMissionSaveAs.sqf"") then {call compileScript ["".enh_eventScripts\onMissionSaveAs.sqf""]}";
			onModeChange="if (fileExists "".enh_eventScripts\onModeChange.sqf"") then {call compileScript ["".enh_eventScripts\onModeChange.sqf""]}";
			onMoveGridDecrease="if (fileExists "".enh_eventScripts\onMoveGridDecrease.sqf"") then {call compileScript ["".enh_eventScripts\onMoveGridDecrease.sqf""]}";
			onMoveGridIncrease="if (fileExists "".enh_eventScripts\onMoveGridIncrease.sqf"") then {call compileScript ["".enh_eventScripts\onMoveGridIncrease.sqf""]}";
			onMoveGridToggle="if (fileExists "".enh_eventScripts\onMoveGridToggle.sqf"") then {call compileScript ["".enh_eventScripts\onMoveGridToggle.sqf""]}";
			onPaste="if (fileExists "".enh_eventScripts\onPaste.sqf"") then {call compileScript ["".enh_eventScripts\onPaste.sqf""]}";
			onPasteUnitOrig="if (fileExists "".enh_eventScripts\onPasteUnitOrig.sqf"") then {call compileScript ["".enh_eventScripts\onPasteUnitOrig.sqf""]}";
			onRedo="if (fileExists "".enh_eventScripts\onRedo.sqf"") then {call compileScript ["".enh_eventScripts\onRedo.sqf""]}";
			onRotateGridDecrease="if (fileExists "".enh_eventScripts\onRotateGridDecrease.sqf"") then {call compileScript ["".enh_eventScripts\onRotateGridDecrease.sqf""]}";
			onRotateGridIncrease="if (fileExists "".enh_eventScripts\onRotateGridIncrease.sqf"") then {call compileScript ["".enh_eventScripts\onRotateGridIncrease.sqf""]}";
			onRotateGridToggle="if (fileExists "".enh_eventScripts\onRotateGridToggle.sqf"") then {call compileScript ["".enh_eventScripts\onRotateGridToggle.sqf""]}";
			onScaleGridToggle="if (fileExists "".enh_eventScripts\onScaleGridToggle.sqf"") then {call compileScript ["".enh_eventScripts\onScaleGridToggle.sqf""]}";
			onSearchCreate="if (fileExists "".enh_eventScripts\onSearchCreate.sqf"") then {call compileScript ["".enh_eventScripts\onSearchCreate.sqf""]}";
			onSearchEdit="if (fileExists "".enh_eventScripts\onSearchEdit.sqf"") then {call compileScript ["".enh_eventScripts\onSearchEdit.sqf""]}";
			onSelectionChange="if (fileExists "".enh_eventScripts\onSelectionChange.sqf"") then {call compileScript ["".enh_eventScripts\onSelectionChange.sqf""]}";
			onServerToggle="if (fileExists "".enh_eventScripts\onServerToggle.sqf"") then {call compileScript ["".enh_eventScripts\onServerToggle.sqf""]}";
			onSubmodeChange="if (fileExists "".enh_eventScripts\onSubmodeChange.sqf"") then {call compileScript ["".enh_eventScripts\onSubmodeChange.sqf""]}";
			onSurfaceSnapToggle="if (fileExists "".enh_eventScripts\onSurfaceSnapToggle.sqf"") then {call compileScript ["".enh_eventScripts\onSurfaceSnapToggle.sqf""]}";
			onTerrainNew="if (fileExists "".enh_eventScripts\onTerrainNew.sqf"") then {call compileScript ["".enh_eventScripts\onTerrainNew.sqf""]}";
			onToggleMapIDs="if (fileExists "".enh_eventScripts\onToggleMapIDs.sqf"") then {call compileScript ["".enh_eventScripts\onToggleMapIDs.sqf""]}";
			onToggleMapTextures="if (fileExists "".enh_eventScripts\onToggleMapTextures.sqf"") then {call compileScript ["".enh_eventScripts\onToggleMapTextures.sqf""]}";
			onTogglePlaceEmptyVehicle="if (fileExists "".enh_eventScripts\onTogglePlaceEmptyVehicle.sqf"") then {call compileScript ["".enh_eventScripts\onTogglePlaceEmptyVehicle.sqf""]}";
			onUndo="if (fileExists "".enh_eventScripts\onUndo.sqf"") then {call compileScript ["".enh_eventScripts\onUndo.sqf""]}";
			onVerticalToggle="if (fileExists "".enh_eventScripts\onVerticalToggle.sqf"") then {call compileScript ["".enh_eventScripts\onVerticalToggle.sqf""]}";
			onWidgetArea="if (fileExists "".enh_eventScripts\onWidgetArea.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetArea.sqf""]}";
			onWidgetNone="if (fileExists "".enh_eventScripts\onWidgetNone.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetNone.sqf""]}";
			onWidgetRotation="if (fileExists "".enh_eventScripts\onWidgetRotation.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetRotation.sqf""]}";
			onWidgetScale="if (fileExists "".enh_eventScripts\onWidgetScale.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetScale.sqf""]}";
			onWidgetToggle="if (fileExists "".enh_eventScripts\onWidgetToggle.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetToggle.sqf""]}";
			onWidgetTranslation="if (fileExists "".enh_eventScripts\onWidgetTranslation.sqf"") then {call compileScript ["".enh_eventScripts\onWidgetTranslation.sqf""]}";
			onWorkspacePartSwitch="if (fileExists "".enh_eventScripts\onWorkspacePartSwitch.sqf"") then {call compileScript ["".enh_eventScripts\onWorkspacePartSwitch.sqf""]}";
		};
	};
};
