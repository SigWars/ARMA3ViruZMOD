#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define true	1
#define false	0

#define VSoft		0
#define VArmor		1
#define VAir		2

class CfgPatches {
	class DZ_Anims_Config_ZmbCrouch {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

#include "CfgMovesBasic.hpp"
#include "CfgMovesZombieCrouch.hpp"

#include "CfgGesturesMale.hpp"
#include "CfgGesturesZombieCrouch.hpp"
