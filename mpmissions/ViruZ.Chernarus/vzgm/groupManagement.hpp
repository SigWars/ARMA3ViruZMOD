class GroupManagement {

	idd = 55510;
	movingEnable = true;
	enableSimulation = true;
	
	class ControlsBackground {
				
		class MainBG : W_RscPicture {
			idc = -1;
			text = "vzgm\ui\ui_background_controlers_ca.paa";
			moving = true;
			x = .0; y = .1;
			w = 1.3; h = .65;
		};
		
		class MainTitle : W_RscStructuredText {
			idc = 700013;
			text = "Group Management";
			sizeEx = .05;
			shadow = 2;		
			x = 0;
			y = 0.12;
			w = 0.975;
			h = 0.04;
		};

		class InviteTitleText : W_RscText {
			idc = -1;
			text = "Players";
			sizeEx = .025;
			shadow = 2;		
			x = .0875; y = .155;
			w = .3; h = .050;
		};

		class GroupTitleText : W_RscText {
			idc = -1;
			text = "Your Group";
			sizeEx = .025;
			shadow = 2;		
			x = .5575; y = .155;
			w = .3; h = .050;
		};
		
		class InviteText: W_RscStructuredText
		{
			idc = 55520;
			text = "";
			size = .025;
			x = .255; y = .500;
			w = .235; h = .075;
		};
	
	};
	
	class controls {

		class PlayerListBox : W_RscList {
			idc = 55511;
			onLBSelChanged = "call playerSelectChange;";
			x = .020; y = .200;
			w = .235; h = .380;
		};
		
		class RefreshButton : W_RscButton {
			idc = -1;
			text = "Refresh";
			onButtonClick = "call updatePlayerList;";
			x = .08; y = .59;
			w = .125; h = .033 * safezoneH;
			color[] = {.1,.95,.1,1};
		};
		
		class GroupListBox : W_RscList {
			idc = 55512;
			onLBSelChanged = "call playerSelectChangeoff;";
			x = 0.4875;
			y = 0.2;
			w = 0.2375;
			h = 0.38;
		};

		class CloseButton : W_RscButton {
			idc = -1;
			text = "Close";
			onButtonClick = "closeDialog 0;groupManagmentActive = false;";
			x = .02; y = .68;
			w = .125; h = .033 * safezoneH;
			color[] = {.95,.1,.1,1};
		};

		class InviteButton : W_RscButton {
			idc = 55514;
			onButtonClick = "call inviteToGroup;";
			color[] = {0.1,0.95,0.1,1};

			text = "Clan Invite"; //--- ToDo: Localize;
			x = 0.775;
			y = 0.26;
			w = 0.125;
			h = 0.0600256;
		};

		class KickButton : W_RscButton {
			idc = 55515;
			onButtonClick = "call kickFromGroup;";
			color[] = {0.95,0.1,0.1,1};

			text = "Clan Kick"; //--- ToDo: Localize;
			x = 0.775;
			y = 0.34;
			w = 0.125;
			h = 0.0600256;
		};

		class DisbandButton : W_RscButton {
			idc = 55516;
			onButtonClick = "call disbandGroup;";
			color[] = {0.95,0.1,0.1,1};

			text = "Disband Clan"; //--- ToDo: Localize;
			x = 0.775;
			y = 0.42;
			w = 0.125;
			h = 0.0600256;
		};

		class LeaveButton : W_RscButton {
			idc = 55517;
			onButtonClick = "call leaveGroup;  closeDialog 0; groupManagmentActive = false;";
			color[] = {0.95,0.1,0.1,1};

			text = "Leave Clan"; //--- ToDo: Localize;
			x = 0.775;
			y = 0.52;
			w = 0.125;
			h = 0.06;
		};

		class AcceptInviteButton : W_RscButton {
			idc = 55518;
			text = "Accept";
			onButtonClick = "call acceptGroupInvite; closeDialog 0; groupManagmentActive = false;";
			x = .275; y = .625 - .0255 * safezoneH;
			w = .100; h = .033 * safezoneH;
			color[] = {.1,.95,.1,1};
		};

		class DeclineInviteButton : W_RscButton {
			idc = 55519;
			text = "Decline";
			onButtonClick = "call declineGroupInvite;";
			x = .375; y = .625 - .0255 * safezoneH;
			w = .100; h = .033 * safezoneH;
			color[] = {.95,.1,.1,1};
		};
		class GroupName: W_RscEdit
		{
			idc = 700001;

			text = "Type you Clan Name"; //--- ToDo: Localize;
			x = 0.3375;
			y = 0.68;
			w = 0.3;
			h = 0.05;
		};
		class cancelClanInvite: W_RscButton
		{
			idc = 700012;
			onButtonClick = "call cancelPendInvite;";
			color[] = {0.95,0.1,0.1,1};

			text = "Cancel Invite"; //--- ToDo: Localize;
			x = 0.3125;
			y = 0.5;
			w = 0.125;
			h = 0.06;
			tooltip = "If you select a player you will cancel only your invite, otherwise you will cancel all."; //--- ToDo: Localize;
		};
		//TEMP GROUP
		class TempInviteButton: W_RscButton
		{
			idc = 700002;
			onButtonClick = "call tempGroupInvite;";
			color[] = {0.1,0.95,0.1,1};

			text = "Group Invite"; //--- ToDo: Localize;
			x = 0.3125;
			y = 0.26;
			w = 0.125;
			h = 0.0600256;
			tooltip = "Invite the player to your group temporarily";
		};
		class TempKickButton: W_RscButton
		{
			idc = 700003;
			onButtonClick = "call tempGroupKick;";
			color[] = {0.95,0.1,0.1,1};

			text = "Group Kick"; //--- ToDo: Localize;
			x = 0.3125;
			y = 0.34;
			w = 0.125;
			h = 0.0600256;
			tooltip = "Kick the player of your group";
		};
		class TempLeaveButton: W_RscButton
		{
			idc = 700004;
			onButtonClick = "call tempGroupLeave;";
			color[] = {0.95,0.1,0.1,1};

			text = "Leave Group"; //--- ToDo: Localize;
			x = 0.3125;
			y = 0.42;
			w = 0.125;
			h = 0.06;
			tooltip = "It leaves the group but remains in the clan if there is one."; //--- ToDo: Localize;
		};
		class CreateClanButton: W_RscButton
		{
			idc = 700005;
			onButtonClick = "((findDisplay 55510) displayCtrl 700001) ctrlShow true; ((findDisplay 55510) displayCtrl 700006) ctrlShow true; ((findDisplay 55510) displayCtrl 700007) ctrlShow true;";
			color[] = {0.1,0.95,0.1,1};

			text = "Create Clan"; //--- ToDo: Localize;
			x = 0.1875;
			y = 0.68;
			w = 0.1125;
			h = 0.06;
			tooltip = "Create a definitive clan";
		};
		class CreateOk: W_RscButton
		{
			idc = 700006;
			onButtonClick = "call createClan; closeDialog 0;groupManagmentActive = false;";
			color[] = {0.1,0.95,0.1,1};

			text = "Ok"; //--- ToDo: Localize;
			x = 0.6375;
			y = 0.68;
			w = 0.1125;
			h = 0.06;
		};
		class CreateCancel: W_RscButton
		{
			idc = 700007;
			onButtonClick = "((findDisplay 55510) displayCtrl 700006) ctrlShow false; ((findDisplay 55510) displayCtrl 700007) ctrlShow false; ((findDisplay 55510) displayCtrl 700001) ctrlShow false;";
			color[] = {0.1,0.95,0.1,1};

			text = "Cancel"; //--- ToDo: Localize;
			x = 0.7625;
			y = 0.68;
			w = 0.1125;
			h = 0.06;
		};
		class AcceptTempInvite: W_RscButton
		{
			idc = 700008;
			onButtonClick = "call tempGroupAccept; closeDialog 0; groupManagmentActive = false;";
			color[] = {0.1,0.95,0.1,1};

			text = "Join"; //--- ToDo: Localize;
			x = 0.275;
			y = 0.58;
			w = 0.1;
			h = 0.0600256;
		};
		class DeclineTempInvite: W_RscButton
		{
			idc = 700009;
			onButtonClick = "call tempGroupDecline;";
			color[] = {0.95,0.1,0.1,1};

			text = "Decline"; //--- ToDo: Localize;
			x = 0.375;
			y = 0.58;
			w = 0.1;
			h = 0.0600256;
		};
		class GroupLevelBox: RscCombo
		{
			idc = 700010;

			x = 0.4875;
			y = 0.6;
			w = 0.2375;
			h = 0.04;
		};
		class applyButton: W_RscButton
		{
			idc = 700011;
			onButtonClick = "call setRankLevel; closeDialog 0; groupManagmentActive = false;";
			color[] = {0.1,0.95,0.1,1};

			text = "Apply"; //--- ToDo: Localize;
			x = 0.77675;
			y = 0.5904;
			w = 0.1125;
			h = 0.06;
		};
	};
};