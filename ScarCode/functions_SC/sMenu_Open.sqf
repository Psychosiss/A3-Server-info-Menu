/*
	Author: IT07

	Description:
	Opens and loads content for server menu

	Params: Optional.
*/

if (!dialog and isNull(findDisplay 297)) then
{
	_settings = ["menuCategories","serverHostLogo","serverSquadLogo"] call SC_sMenu_getCfgSetting;
	createDialog "SC_sMenu";
	disableSerialization; // Needed when handling controls

	// Load menuCategories into comboBox
	_control = (findDisplay 297) displayCtrl 2100;
	lnbClear _control; // Clear the lb first to prevent list duplicates when called again
	{
		_control lbAdd _x;
	} forEach (_settings select 0);
	_control lbSetCurSel 0;

	["sideBarInfo"] call SC_sMenu_handleCtrlText;
	["serverStats"] call SC_sMenu_handleCtrlText;

	// Add host image if enabled
	_hostLogo = _settings select 1;
	if !(_hostLogo isEqualTo "") then
	{
		["serverHostLogo"] call SC_sMenu_handleCtrlText;
		["serverHostLogoTxt"] call SC_sMenu_handleCtrlText;
	};

	// Add squad logo if enabled
	_squadLogo = _settings select 2;
	if !(_squadLogo isEqualTo "") then
	{
		["serverSquadLogo"] call SC_sMenu_handleCtrlText;
	};

	if (isNil "_f5EventHandler") then
	{
		_sMenuF5 = (findDisplay 297) displayAddEventHandler ["KeyDown", "if(_this select 1 == 0x3F) then { ['serverStats'] call SC_sMenu_handleCtrlText; };false;"];
		uiNamespace setVariable ["SC_sMenuF5", _sMenuF5];
	};
};