/*
	Author: IT07

	Description:
	Configuration and resource file for server menu. Should be used to adjust the content of menu.
*/

class SC_sMenuConfig
{
	class menuConfig
	{
		/////////////////////////////////////////////////////////
		///////  General config for the menu  ///////////////////
		///////  Please adjust these below to your needs  ///////
		/////////////////////////////////////////////////////////
		
		keyToOpenMenu = 0x43; // Change to false to disable. Works with useScrollAction. DEFAULT: 0x43 = F9 key. https://community.bistudio.com/wiki/DIK_KeyCodes
		useScrollAction = 1; // Change to false to disable. Can use any number to enable. Can be used in combo with keyToOpenMenu
		menuCategories[] = {"General info","Rules","Donating","Scripts and Credits"}; // Try to keep amount as low as possible for optimal speed/load
		shortServerName = "[CLAN] Epoch Server #1 UK"; // Will be put in the title of the menu. Keep it as short as possible.
		serverIPandPort = "123.456.789:2302"; // Speaks for itself
		maxPlayers = 100; // This should be exactly the same as the maximum slot count of your server
		restartInterval = 4; // Number of hours your server will be online before it automatically restarts. Set to 0 if you use a restart schedule.
		serverAH = "infiSTAR, BattlEye and Epoch built-in"; // Put your antihack(s) here
		serverManagedBy = "NameOfAdmin1234"; // Put name of the server manager here. Max 16 characters 
		serverHostLogo = "ScarCode\menuLogos\hosting\exampleHosted.jpg"; // Size: 280x85. Have to specify image. Can not be disabled anymore
		serverSquadLogo = "ScarCode\menuLogos\exampleManaged.jpg"; // Size: 128x128. Use "" if you do not want to show a squad logo
		gametrackerURL = "http://gametracker.com/";
		#define TITLEBACKGROUND { 1,0,0.749,1 } // In format R,G,B,A | (A = opacity) | color will be given to title bars | tool to convert from HTML color codes: http://killzonekid.com/hex-2-arma-gui-colour-converter/
		#define TITLETEXT { 0,0,0,1 } // Same format as above. Color will be given to the text of the title bars.
		
		/////////////////////////////////////////////////////////
		///////  End of general config  /////////////////////////
		/////////////////////////////////////////////////////////
	};
	class configContent
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////  Config for the content of each menu category  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////  == Instructions for editing the content ==  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////  step 1: Adjust the amount of class items (below) to the amount of categories you have set in _menuCategories  ///////////////////////////////////////////////////////////
		///////  step 2: Configure contentArray. Please look at the examples to see how to do it. contentArray is used to divide the text into pieces for easier configuration  //////////
		///////  step 2b: it does not matter how you name the items in contentArray. They just have to match the actual item names that are defined in contentArray[]  ///////////////////
		///////  step 3: go nuts! :)  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////  NOTE 1: Do not put the title in contentArray because the title is already put into the title bar automatically  /////////////////////////////////////////////////////////
		///////  NOTE 2: Less items in contentArray[] is faster  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////  NOTE 3: <br /> is a linebreak, <img image'path\to\Image.jpg' /> is an image and <a href='url'>this is a link</a>  ///////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		class 1 // First in _menuCategories
 		{
			contentArray[] = {"txtOne","txtTwo","txtThree","txtFour","txtFive"};
			txtOne = "<t size='1.5'>EXAMPLE TITLE</t> <br /><br /> <img image='ScarCode\menuLogos\example.jpg' size='7' /> <br /><br />";
			txtTwo = "<t size='1.5'>SERVER FEATURES</t> <br /> - Feature 1 <br /> - Feature 2 <br /> - Feature 3 <br /> - Feature 4 <br /> - Feature 5 <br /> - Feature 6 <br /> - Feature 7 <br /><br />";
			txtThree = "<t size='1.5'>WEBSITE</t> <br /><a href='url'>url</a><br /><br />";
			txtFour = "<t size='1.5'>VOICE SERVER</t> <br />We have a public TeamSpeak/Ventrilo/Razer Comms/RaidCall/Vivox/Xfire/Mumble server available at 1.2.3.4.5:1234 or <a href='url' color='#D13B3B'>voice.yourwebsite.com</a> <br /><br />";
			txtFive = "<t size='1.5'>SERVER ADMINS</t> <br /> - AdminName [title and function] <br /> - AnotherAdmin [title and function]";
		};
		class 2 // Second in _menuCategories
		{
			contentArray[] = {"txtOne","txtTwo","txtThree","txtFour","txtFive","txtSix","txtSeven"};
			txtOne = "<t size='1.5'>RULE #1</t> <br /> - No racism/profanity/flaming <br />  <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a (temporary/permanent) ban.</t> <br /><br />";
			txtTwo = "<t size='1.5'>RULE #2</t> <br /> - No voice over side/radio channel <br /> <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a kick or (temporary/permanent) ban.</t> <br /><br />";
			txtThree = "<t size='1.5'>RULE #3</t> <br /> - No use/placement of explosives <br /> <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a (temporary/permanent) ban.</t> <br /><br />";
			txtFour = "<t size='1.5'>RULE #4</t> <br /> - No disrespect towards other player(s) and or Admins <br /> <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a kick / (temporary/permanent) ban.</t> <br /><br />";
			txtFive = "<t size='1.5'>RULE #5</t> <br /> - No cheating/glitching or bug abuse/exploiting <br /> <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a (temporary/permanent) ban.</t> <br /><br />";
			txtSix = "<t size='1.5'>RULE #6</t> <br /> - No spawn killing <br /> <t size='0.75' color='#c2c2c2'>Breaking of this rule will result in a (temporary/permanent) ban.</t> <br /><br />";
			txtSeven = "<t size='1.5'>RULE #7</t> <br /> - No excuses such as: I did not read the rules. <br /> <t size='0.75' color='#c2c2c2'>This will be considered very stupid.</t> <br /><br />";
		};
		class 3 // Third in _menuCategories
		{
			contentArray[] = {"txtOne","txtTwo"};
			txtOne = "<t size='1.5'>PLEASE DONATE</t> <br />If you play on and enjoy this server, please consider a donation to keep the high server costs down. <br /><br />";
			txtTwo = "This server costs $80 p/month so we could really use any kind of donation. <a href='url' color='#D13B3B'>click here to donate</a> <br /><br />";
		};
		class 4 // Fourth in _menuCategories
		{
			contentArray[] = {"txtOne"};
			txtOne = " - {ScarCode} Server info menu by IT07 <a color='#D13B3B' href='http://scarcode.com'>http://scarcode.com</a> <br /> - Some other script <br /> - Another script <br /> - A script";
		};
	};
};

////////////////////////////////////////////////////////
/////// Do not change anything below this line  ////////
////////////////////////////////////////////////////////
#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)

class SC_sMenu
{
	idd = 297;
	onLoad = "[] spawn SC_sMenu_Open";
	movingEnable = 1;
	class controls
	{
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by IT07, v1.063, #Qivany)
////////////////////////////////////////////////////////

class sMenuTitle: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1000;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 0 * GUI_GRID_H + GUI_GRID_Y;
	w = 30 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuContentSelector: RscCombo
{
	onLBSelChanged = _this call SC_sMenu_getContent;

	idc = 2100;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 14.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuLogoHostedBy: RscPicture
{
	style = 48;

	idc = 1201;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 9.5 * GUI_GRID_W;
	h = 2.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuSquadLogo: RscPicture
{
	style = 2096;

	idc = 1200;
	x = -3.5 * GUI_GRID_W + GUI_GRID_X;
	y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 3 * GUI_GRID_W;
	h = 2.5 * GUI_GRID_H;
};
class sMenuContentBg: IGUIBack
{
	idc = 2200;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 30 * GUI_GRID_W;
	h = 12.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class contentGroup: RscControlsGroup
{
	idc = 2300;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 30 * GUI_GRID_W;
	h = 12.5 * GUI_GRID_H;
	class controls
	{
		class sMenuContentTxt: RscStructuredText
		{
			idc = 1100;
			x = 0.5 * GUI_GRID_W;
			y = 1 * GUI_GRID_H;
			w = 23.5 * GUI_GRID_W;
			h = 0.25 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0};
		};
	};
};
class sMenuClose: RscButton
{
	action = closeDialog 0;

	idc = 1600;
	text = "CLOSE"; //--- ToDo: Localize;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 22 * GUI_GRID_H + GUI_GRID_Y;
	w = 3.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuOutputBg: IGUIBack
{
	idc = 2202;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 19.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 40 * GUI_GRID_W;
	h = 2 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuEdit: RscEdit
{
	idc = 1400;
	x = 0.5 * GUI_GRID_W + GUI_GRID_X;
	y = 20 * GUI_GRID_H + GUI_GRID_Y;
	w = 12.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorText[] = {1,1,1,0.8};
	tooltip = "Ctrl+C to copy, Ctrl+V to paste"; //--- ToDo: Localize;
};
class sMenuTitleSLOTCOUNT: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1005;
	text = "SLOT USAGE (live)"; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 0 * GUI_GRID_H + GUI_GRID_Y;
	w = 8.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuTitleUPTIME: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1001;
	text = "UPTIME (live)"; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 3 * GUI_GRID_H + GUI_GRID_Y;
	w = 6 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuTxtPLAYERS: RscText
{
	sizeEx = 0.07;

	idc = 1002;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 1 * GUI_GRID_H + GUI_GRID_Y;
	w = 9 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTxtUPTIME: RscText
{
	sizeEx = 0.07;

	idc = 1004;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 4 * GUI_GRID_H + GUI_GRID_Y;
	w = 8.5 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleIP: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1006;
	text = "IP:PORT"; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 9 * GUI_GRID_H + GUI_GRID_Y;
	w = 4 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuTxtIPPORT: RscText
{
	sizeEx = 0.05;

	idc = 1007;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 10 * GUI_GRID_H + GUI_GRID_Y;
	w = 11 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleRESTARTINTV: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1008;
	text = "REST. INTV."; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 6 * GUI_GRID_H + GUI_GRID_Y;
	w = 5.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class RscText_1009: RscText
{
	sizeEx = 0.07;

	idc = 1009;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 7 * GUI_GRID_H + GUI_GRID_Y;
	w = 8 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleHOSTEDBY: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1010;
	text = "HOSTED BY"; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 15.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 5.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuTxtDevBy: RscText
{
	sizeEx = 0.03;
	style = 1;

	idc = 1003;
	text = "Server Info Menu (v03881_PATCH8) developed by IT07"; //--- ToDo: Localize;
	x = 4 * GUI_GRID_W + GUI_GRID_X;
	y = 22 * GUI_GRID_H + GUI_GRID_Y;
	w = 36 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleCopyPasteData: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1011;
	text = "COPY+PASTE DATA"; //--- ToDo: Localize;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 18.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 9 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class RscEdit_1401: RscEdit
{
	idc = 1401;
	x = 14 * GUI_GRID_W + GUI_GRID_X;
	y = 20 * GUI_GRID_H + GUI_GRID_Y;
	w = 12 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorText[] = {1,1,1,0.8};
	tooltip = "Ctrl+C to copy, Ctrl+V to paste"; //--- ToDo: Localize;
};
class sMenuTxtManagedBy: RscText
{
	sizeEx = 0.05;

	idc = 1012;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 13 * GUI_GRID_H + GUI_GRID_Y;
	w = 12.5 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleManagedBy: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1013;
	text = "MANAGED BY"; //--- ToDo: Localize;
	x = 30.5 * GUI_GRID_W + GUI_GRID_X;
	y = 12 * GUI_GRID_H + GUI_GRID_Y;
	w = 7 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class sMenuTxtAH: RscText
{
	sizeEx = 0.05;

	idc = 1014;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 30 * GUI_GRID_W;
	h = 1.5 * GUI_GRID_H;
	colorBackground[] = {0,0,0,0.8};
};
class sMenuTitleAH: RscText
{
	colorBackground[] = TITLEBACKGROUND;
	shadow = 0;
	colorText[] = TITLETEXT;

	idc = 1015;
	text = "ANTIHACK BY"; //--- ToDo: Localize;
	x = 0 * GUI_GRID_W + GUI_GRID_X;
	y = 15.5 * GUI_GRID_H + GUI_GRID_Y;
	w = 7 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class RscEdit_1402: RscEdit
{
	idc = 1402;
	x = 27 * GUI_GRID_W + GUI_GRID_X;
	y = 20 * GUI_GRID_H + GUI_GRID_Y;
	w = 12.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	colorText[] = {1,1,1,0.8};
	tooltip = "Ctrl+C to copy, Ctrl+V to paste"; //--- ToDo: Localize;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

	};
};