/*
	Author: IT07

	Description:
	Handle given text and put into given control

	Params:
	SYNTAX: ["nameOfConfigVar"] spawn/call SC_fnc_handleCtrlText;
	_this: array of config vars to get
*/

disableSerialization; // Needed for controls/displays
_display = 297;
_control = "set";
_type = "set";
_input = "set";
_setBg = false;
_setTxtHeight = false;

switch (_this select 0) do
{
	case "sideBarInfo":
	{
		_control = (findDisplay _display) displayCtrl 1101;
		_option = ["serverManagedBy","serverIPandPort","serverLocation","restartInterval","serverMission","serverMods","serverAllowedMods","serverMap","serverAH","serverGameType"] call SC_sMenu_getCfgSetting;
		_type = "strTxt";
		_interval = format["%1 (hours)", _option select 3];
		if (_option select 3 == 0) then
		{
			_interval = "None, schedule";
		};
		_input = format["%11MANAGED BY%13<br />%12%1%13<br />%11IP:PORT%13<br />%12%2%13<br />%11LOCATION%13<br />%12%3%13<br />%11RESTART INTERVAL%13<br />%12%4%13<br />%11MISSION:%13<br />%12%5%13<br />%11MODS%13<br />%12%6%13<br />%11ALLOWED MODS%13<br />%12%7%13<br />%11MAP%13<br />%12%8%13<br />%11ANTIHACK%13<br />%12%9%13<br />%11GAMETYPE%13<br />%12%10%13<br />", _option select 0, _option select 1, _option select 2, _interval, _option select 4, _option select 5, _option select 6, _option select 7, _option select 8, _option select 9, "<t size='0.8' color='#57877b'>", "<t size='0.75'>", "</t>"];
		_setTxtHeight = true;
	};
	case "serverStats":
	{
		_control = (findDisplay _display) displayCtrl 1006;
		_option = ["maxPlayers"] call SC_sMenu_getCfgSetting;
		_type = "txt";
		_mode = serverTime; // Use serverTime for live use

		_hours = _mode / 3600;
		_hourOrHours = "";
		if (floor(_hours) > 1 or floor(_hours) == 0) then
		{
			_hourOrHours = "s";
		};

		_minutes = (_hours - floor _hours);
		_minuteOrMinutes = "";
		if (floor(_minutes * 60) > 1 or floor(_minutes * 60) == 0) then
		{
			_minuteOrMinutes = "s";
		};
		_input = format["PLAYERS %1/%2 \nUPTIME %3hour%5 %4minute%6", playersNumber west + playersNumber east + playersNumber independent + playersNumber civilian, _option select 0, floor(_hours), floor(_minutes * 60), _hourOrHours, _minuteOrMinutes];
	};
	case "serverHostLogo":
	{
		_control = (findDisplay _display) displayCtrl 1201;
		_type = "txt";
		_option = ["serverHostLogo"] call SC_sMenu_getCfgSetting;
		_input = _option select 0;
	};
	case "serverHostLogoTxt":
	{
		_control = (findDisplay _display) displayCtrl 1004;
		_type = "txt";
		_input = "SERVER HOSTED BY";
		_setBg = true;
	};
	case "serverSquadLogo":
	{
		_control = (findDisplay _display) displayCtrl 1200;
		_type = "txt";
		_option = ["serverSquadLogo"] call SC_sMenu_getCfgSetting;
		_input = _option select 0;
	};
	case "copyIpPort":
	{
		_control = (findDisplay _display) displayCtrl 1400;
		_type = "txt";
		_option = ["serverIPandPort"] call SC_sMenu_getCfgSetting;
		_input = "Server IP and PORT: " + (_option select 0);
	};
	case "copyPlayerInfo":
	{
		_control = (findDisplay _display) displayCtrl 1400;
		_type = "txt";
		_input = format["%1's UID = %2", name player, getPlayerUID player];
	};
	default { };
};

switch (_type) do // Switch the given number for selecting setText or SetStrText
{
	case "txt": // ctrlSetText
	{
		_control ctrlSetText _input; // Set text to _control with given text
	};
	case "strTxt": // ctrlSetStructuredText
	{
		_control ctrlSetStructuredText parseText _input; // Set text to _control with given text
	};
	default { };
};

if (_setBg) then
{
	_control ctrlSetBackgroundColor [0.341,0.529,0.482,1]; // Set the background to targetControl if requested
};

if (_setTxtHeight) then
{
	_ctrlPosition = ctrlPosition _control;
	_h = ctrlTextHeight _control;
	_control ctrlSetPosition [_ctrlPosition select 0, _ctrlPosition select 1, _ctrlPosition select 2, _h];
	_control ctrlCommit 0;
};