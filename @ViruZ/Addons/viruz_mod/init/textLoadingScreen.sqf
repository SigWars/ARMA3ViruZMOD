private["_display","_control1"];

disableSerialization;

_display = uiNameSpace getVariable "RscDisplayLoading";	
if (!isNil "_display") then {
	_control1 = _display displayctrl 1102;
	_control1 ctrlSetText format["%1",localize "STR_InitializingVIRUZMOD"];
};