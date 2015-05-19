/*
	Author: IT07
	Description: returns uptime or player amount
*/
_return = "meh";
switch(_this select 0) do
{
	case "UPT":
	{
		_mode = serverTime; // Use serverTime for live use
		_hours = _mode / 3600;
		_minutes = (_hours - floor _hours);
		_return = format["%1h %2m", floor(_hours), floor(_minutes * 60)];
	};
	case "PLY":
	{
		_option = ["maxPlayers"] call SC_sMenu_getCfgSetting;
		_return = format["%1/%2", playersNumber west + playersNumber east + playersNumber independent + playersNumber civilian, _option select 0];
	};
};
_return
