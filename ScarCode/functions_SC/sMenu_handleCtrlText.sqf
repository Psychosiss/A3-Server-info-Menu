/*
	Author: IT07

	Description:
	Handle given text and put into given control

	Params:
	SYNTAX: [ARRAY] SC_fnc_handleCtrlText;
	_this: must be array of STRINGS that match a case in switch
*/

disableSerialization; // Needed for controls/displays
_display = 297;
_control = "set";
_type = "set";
_input = "set";
_setTxtHeight = false;

{
	switch _x do
	{
		case "TITLE":
		{
			_control = (findDisplay _display) displayCtrl 1000;
			_option = ["shortServerName"] call SC_sMenu_getCfgSetting;
			_type = "txt";
			_input = format ["SERVER INFO OF: %1", _option select 0];
		};
		case "SLOT_USAGE":
		{
			_control = (findDisplay _display) displayCtrl 1002;
			_type = "txt";
			_input = ["PLY"] call SC_sMenu_liveStats;
		};
		case "UPTIME":
		{
			_control = (findDisplay _display) displayCtrl 1004;
			_type = "txt";
			_input = ["UPT"] call SC_sMenu_liveStats;
		};
		case "IP_PORT":
		{
			_control = (findDisplay _display) displayCtrl 1007;
			_option = ["serverIPandPort"] call SC_sMenu_getCfgSetting;
			_type = "txt";
			_input = _option select 0;
		};
		case "RESTARTINTV":
		{
			_control = (findDisplay _display) displayCtrl 1009;
			_option = ["restartInterval"] call SC_sMenu_getCfgSetting;
			_type = "txt";
			_input = format["%1h", _option select 0];
		};
		case "MANAGEDBY":
		{
			_control = (findDisplay _display) displayCtrl 1012;
			_option = ["serverManagedBy"] call SC_sMenu_getCfgSetting;
			_type = "txt";
			_input = _option select 0;
		};
		case "HOST_LOGO":
		{
			_control = (findDisplay _display) displayCtrl 1201;
			_type = "txt";
			_option = ["serverHostLogo"] call SC_sMenu_getCfgSetting;
			_input = _option select 0;
		};
		case "SQUAD_LOGO":
		{
			_option = ["serverSquadLogo"] call SC_sMenu_getCfgSetting;
			if !(_option select 0 isEqualTo "") then
			{
				_control = (findDisplay _display) displayCtrl 1200;
				_type = "txt";
				_input = _option select 0;
			};
		};
		case "AH":
		{
			_control = (findDisplay _display) displayCtrl 1014;
			_type = "txt";
			_option = ["serverAH"] call SC_sMenu_getCfgSetting;
			_input = _option select 0;
		};
		case "GET_IP":
		{
			_control = (findDisplay _display) displayCtrl 1400;
			_type = "txt";
			_option = ["serverIPandPort"] call SC_sMenu_getCfgSetting;
			_input = "IP:PORT = " + (_option select 0);
		};
		case "GET_PLAYERINFO":
		{
			_control = (findDisplay _display) displayCtrl 1401;
			_type = "txt";
			_input = format["%1's UID = %2", name player, getPlayerUID player];
		};
		case "GET_GTURL":
		{
			_control = (findDisplay _display) displayCtrl 1402;
			_type = "txt";
			_option = ["gametrackerURL"] call SC_sMenu_getCfgSetting;
			_input = format["GameTracker: %1", _option select 0];
		};
		default { closeDialog 297; }; //A script kiddie tried to "hack" the function
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

	if (_setTxtHeight) then
	{
		_ctrlPosition = ctrlPosition _control;
		_h = ctrlTextHeight _control;
		_control ctrlSetPosition [_ctrlPosition select 0, _ctrlPosition select 1, _ctrlPosition select 2, _h];
		_control ctrlCommit 0;
	};
} forEach _this;