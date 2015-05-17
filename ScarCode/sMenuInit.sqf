///////////////////////////////////////////////////////
///////  ARMA 3 SERVERMENU SCRIPT BY IT07  ////////////
///////  VERSION: 03881_PATCH8  ///////////////////////
///////  SUPPORT: it07@scarcode.com  //////////////////
///////////////////////////////////////////////////////

SC_sMenu_getContent = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_getContent.sqf";
SC_sMenu_handleCtrlText = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_handleCtrlText.sqf";
SC_sMenu_getCfgSetting = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_getCfgSetting.sqf";
SC_sMenu_Open = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_Open.sqf";
SC_sMenu_liveStats = compileFinal preprocessFileLineNumbers "ScarCode\functions_SC\sMenu_liveStats.sqf";

_config = ["useScrollAction","keyToOpenMenu"] call SC_sMenu_getCfgSetting;

_evHandlerCheck = uiNamespace getVariable "SC_sMenuEH";
	if not (isNil "_evHandlerCheck") then
	{
		(findDisplay 46) displayRemoveEventHandler ["KeyDown", _evHandlerCheck];
		uiNamespace setVariable ["SC_sMenuEH", nil];
	};

waitUntil { sleep 0.1; isNull(findDisplay 46); (isNil "_evHandlerCheck"); (speed player > 0.1) };

_sMenuAddAction = ""; // A little scope workaround
if (typeName (_config select 0) == "SCALAR") then
{
	_sMenuAddAction = player addaction["<t color='#57877b'>{SC}</t> Server Info Menu", { createDialog'SC_sMenu' }, "", -1, false, true, "", ""];
	_sMenuRemoveAction = player addAction["  - Remove option", { player removeAction (_this select 2); player removeAction (_this select 3)}, _sMenuAddAction, -1, false, true, "", ""];
};

if (typeName (_config select 1) == "SCALAR") then
{
	_sMenuEH = (findDisplay 46) displayAddEventHandler ["KeyDown", "if(_this select 1 == "+str (_config select 1)+" and !dialog) then { createDialog'SC_sMenu' };false;"];
	uiNamespace setVariable ["SC_sMenuEH", _sMenuEH];
};

// Live uptime and players
_live = [] spawn
{
	_timeInit = ["UPT"] call SC_sMenu_liveStats;
	_playerInit = ["PLY"] call SC_sMenu_liveStats;

	while { true } do
	{
		if (!isNull(findDisplay 297)) then
		{
			_timeCheck = ["UPT"] call SC_sMenu_liveStats;
			_playerCheck = ["PLY"] call SC_sMenu_liveStats;
			if !(_playerCheck isEqualTo _playerInit) then
			{
				_playerInit = ["PLY"] call SC_sMenu_liveStats;
				["SLOT_USAGE"] call SC_sMenu_handleCtrlText;
			};
			if !(_timeCheck isEqualTo _timeInit) then
			{
				_timeInit = ["UPT"] call SC_sMenu_liveStats;
				["UPTIME"] call SC_sMenu_handleCtrlText;
			};
		};
		sleep 1;
	};
};