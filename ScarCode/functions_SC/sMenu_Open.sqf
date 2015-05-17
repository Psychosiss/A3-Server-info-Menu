/*
	Author: IT07

	Description:
	Function called by onLoad for display 297

*/

if (count _this > 0) exitWith { closeDialog 297; }; // A script kid tried to call this function with params
if !(dialog and isNull(findDisplay 297)) then // Make sure the function only works when the menu is open
{
	_settings = ["menuCategories","serverHostLogo","serverSquadLogo"] call SC_sMenu_getCfgSetting;
	disableSerialization; // Needed when handling controls

	// Load menuCategories into comboBox
	_control = (findDisplay 297) displayCtrl 2100;
	lnbClear _control; // Clear the lb first to prevent list duplicates when called again
	{
		_control lbAdd _x;
	} forEach (_settings select 0);
	_control lbSetCurSel 0;

	// Fill menu
	["TITLE","SLOT_USAGE","UPTIME","IP_PORT","RESTARTINTV","MANAGEDBY","HOST_LOGO","SQUAD_LOGO","AH","GET_IP","GET_PLAYERINFO","GET_GTURL"] call SC_sMenu_handleCtrlText;
};