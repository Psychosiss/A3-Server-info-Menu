///////////////////////////////////////////////////////
///////  ARMA 3 SERVERMENU SCRIPT BY IT07  ////////////
///////  VERSION: 03880_PATCH7  ///////////////////////
///////  SUPPORT: it07@scarcode.com  //////////////////
///////////////////////////////////////////////////////

SC_sMenu_getContent = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_getContent.sqf";
SC_sMenu_handleCtrlText = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_handleCtrlText.sqf";
SC_sMenu_getCfgSetting = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_getCfgSetting.sqf";
SC_sMenu_Open = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_Open.sqf";

_config = ["useScrollAction","keyToOpenMenu"] call SC_sMenu_getCfgSetting;

_evHandlerCheck = uiNamespace getVariable "SC_sMenuEH";
	if not (isNil "_evHandlerCheck") then
	{
		(findDisplay 46) displayRemoveEventHandler ["KeyDown", _evHandlerCheck];
		uiNamespace setVariable ["SC_sMenuEH", nil];
	};

_f5EventHandler = uiNamespace getVariable "SC_sMenuF5";
	if not (isNil "_f5EventHandler") then
	{
		(findDisplay 297) displayRemoveEventHandler ["KeyDown", _f5EventHandler];
		uiNamespace setVariable ["SC_sMenuF5", nil];
	};

waitUntil { sleep 0.1; isNull(findDisplay 46); (isNil "_evHandlerCheck"); (speed player > 0.1) };

_sMenuAddAction = ""; // A little scope workaround
if (typeName (_config select 0) == "SCALAR") then
{
	_sMenuAddAction = player addaction["<t color='#57877b'>{SC}</t> Server Info Menu", { call SC_sMenu_Open }, "", -1, false, true, "", ""];
	_sMenuRemoveAction = player addAction["  - Remove option", { player removeAction (_this select 2); player removeAction (_this select 3)}, _sMenuAddAction, -1, false, true, "", ""];
};

if (typeName (_config select 1) == "SCALAR") then
{
	_sMenuEH = (findDisplay 46) displayAddEventHandler ["KeyDown", "if(_this select 1 == "+str (_config select 1)+" and !dialog) then { call SC_sMenu_Open };false;"];
	uiNamespace setVariable ["SC_sMenuEH", _sMenuEH];
};

// A little extra security
_ah = [] spawn
{
	waitUntil { sleep 0.1; !isNull(findDisplay 297) };
	while { true } do
	{
		if !(isNull(findDisplay 297)) then
		{
			if !(count allControls findDisplay 297 == 21) exitWith { closeDialog 297 };
		};
		sleep 0.1;
	};
};