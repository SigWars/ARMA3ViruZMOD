//dev branch door sounds thing
class CfgAnimationSourceSounds
{
	class RDS_Lada_Door
	{
		class DoorMovement {
			loop = 0;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak1", 1, 1, 20};
			sound1[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak2", 1, 1, 20};
			sound2[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak3", 1, 1, 20};
			sound3[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak4", 1, 1, 20};
			sound[] = {"sound0", 0.25, "sound1", 0.25, "sound2", 0.25, "sound3", 0.25};
		};
		class DoorOpen
		{
			loop = 0;
			terminate = 1;
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = {"\rds_a2port_civ\data\sounds\lada_door.wss",db+10,1,60};
			sound1[] = {"\rds_a2port_civ\data\sounds\lada_door.wss",db+10,1,60};
			sound[] = {"sound0",0.5,"sound1",0.5};
		};
		class Close
		{
			loop = 0;
			terminate = 1;
			trigger = "(1 - direction) * (phase factor[0.4,0.01])";
			sound0[] = {"\rds_a2port_civ\data\sounds\door_close.ogg",db+10,1,60};
			sound1[] = {"\rds_a2port_civ\data\sounds\door_close.ogg",db+10,1,60};
			sound[] = {"sound0",0.5,"sound1",0.5};
		};
	};
	class RDS_Golf_Door
	{
		class DoorMovement {
			loop = 0;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak1", 1, 1, 20};
			sound1[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak2", 1, 1, 20};
			sound2[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak3", 1, 1, 20};
			sound3[] = {"A3\Sounds_F\environment\structures\doors\GenericDoors\squeak4", 1, 1, 20};
			sound[] = {"sound0", 0.25, "sound1", 0.25, "sound2", 0.25, "sound3", 0.25};
		};
		class DoorOpen
		{
			loop = 0;
			terminate = 1;
			//trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = {"\rds_a2port_civ\data\sounds\GOLF\int\int-golf-getout.wss",db+10,1,60};
			sound1[] = {"\rds_a2port_civ\data\sounds\GOLF\int\int-golf-getout.wss",db+10,1,60};
			sound[] = {"sound0",0.5,"sound1",0.5};
		};
		class Close
		{
			loop = 0;
			terminate = 1;
			trigger = "(1 - direction) * (phase factor[0.4,0.01])";
			sound0[] = {"\rds_a2port_civ\data\sounds\door_close.ogg",db+10,1,60};
			sound1[] = {"\rds_a2port_civ\data\sounds\door_close.ogg",db+10,1,60};
			sound[] = {"sound0",0.5,"sound1",0.5};
		};
	};

	class RDS_Trunk
	{
		class DoorMovement {
			loop = 1;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_1", 2, 1, 20};
			sound1[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_2", 2, 1, 20};
			sound2[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_3", 2, 1, 20};
			sound3[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_4", 2, 1, 20};
			sound[] = {"sound0", 0.25, "sound1", 0.25, "sound2", 0.25, "sound3", 0.25};
		};
		class OpenTheDoor
		{
			loop = 0;
			terminate = 0;
			trigger = "direction";
			sound0[] = {"\rds_a2port_civ\data\sounds\trunk_open_1.ogg",db+12,1,40};
			sound1[] = {"\rds_a2port_civ\data\sounds\trunk_open_2.ogg",db+12,1,40};
			sound2[] = {"\rds_a2port_civ\data\sounds\trunk_open_3.ogg",db+12,1,40};
			sound3[] = {"\rds_a2port_civ\data\sounds\trunk_open_4.ogg",db+12,1,40};
			sound[] = {"sound0",.25,"sound1",.25,"sound2",.25,"sound3",.25};
		};
		class SlamTheDoor
		{
			loop = 0;
			terminate = 0;
			trigger = "(1 - direction)* (phase factor[0.2,0.09])";
			sound0[] = {"\rds_a2port_civ\data\sounds\trunk_close_1.ogg",db+12,1,40};
			sound1[] = {"\rds_a2port_civ\data\sounds\trunk_close_2.ogg",db+12,1,40};
			sound2[] = {"\rds_a2port_civ\data\sounds\trunk_close_3.ogg",db+12,1,40};
			sound[] = {"sound0",.33,"sound1",.33,"sound2",.33};
		};
	};
	class RDS_Tractor_Door
	{
		class DoorMovement {
			loop = 1;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_1", 2, 1, 20};
			sound1[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_2", 2, 1, 20};
			sound2[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_3", 2, 1, 20};
			sound3[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsSqueak_4", 2, 1, 20};
			sound[] = {"sound0", 0.25, "sound1", 0.25, "sound2", 0.25, "sound3", 0.25};
		};
		class OpenTheDoor {
			loop = 0;
			terminate = 0;
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = {"A3\Sounds_F\environment\structures\doors\GenericBigDoors\GenericBigDoorsKnob", 2, 1, 20};
			sound[] = {"sound0", 1};
		};
		class DoorMovementDone {
			loop = 0;
			terminate = 0;
			trigger = "(1 - direction) * (phase factor[0.1,0.09])";
			sound0[] = {"A3\Sounds_F\sfx\doors\GateDoors\GateSlam", 3, 1, 20};
			sound[] = {"sound0", 1};
		};
	};
	class RDS_Tractor_Cover
	{
		class DoorMovement {
			loop = 0;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"A3\Sounds_F\sfx\doors\FenceGateDoors\fenceGateSqueak_1", 3, 1, 20};
			sound1[] = {"A3\Sounds_F\sfx\doors\FenceGateDoors\fenceGateSqueak_2", 3, 1, 20};
			sound2[] = {"A3\Sounds_F\sfx\doors\FenceGateDoors\fenceGateSqueak_3", 3, 1, 20};
			sound3[] = {"A3\Sounds_F\sfx\doors\FenceGateDoors\fenceGateSqueak_4", 3, 1, 20};
			sound[] = {"sound0", 0.25, "sound1", 0.25, "sound2", 0.25, "sound3", 0.25};
		};
	};
	class RDS_Ikarus_Door1
	{
		class OpenTheDoor
		{
			loop = 0;
			terminate = 0;
			trigger = "direction";
			sound0[] = {"\rds_a2port_civ\data\sounds\d1opn_r",db+12,1,40};
			sound[] = {"sound0",1};
		};
		class SlamTheDoor
		{
			loop = 0;
			terminate = 0;
			trigger = "(1 - direction)";
			sound0[] = {"\rds_a2port_civ\data\sounds\d1cls_r",db+12,1,40};
			sound[] = {"sound0",1};
		};
	};
	class RDS_Ikarus_Door2: RDS_Ikarus_Door1
	{
		class OpenTheDoor: OpenTheDoor
		{
			sound0[] = {"\rds_a2port_civ\data\sounds\d2opn_r",db+12,1,40};
		};
		class SlamTheDoor: SlamTheDoor
		{
			sound0[] = {"\rds_a2port_civ\data\sounds\d3cls_r",db+12,1,40};
		};
	};
	class RDS_Ikarus_Door3: RDS_Ikarus_Door1
	{
		class OpenTheDoor: OpenTheDoor
		{
			sound0[] = {"\rds_a2port_civ\data\sounds\d3opn_r",db+12,1,40};
		};
		class SlamTheDoor: SlamTheDoor
		{
			sound0[] = {"\rds_a2port_civ\data\sounds\d3cls_r",db+12,1,40};
		};
	};

	class RDS_Blinker
	{
		class OpenTheDoor
		{
			loop = 1;
			terminate = 0;
			trigger = "direction";
			sound0[] = {"\rds_a2port_civ\data\sounds\blinker_on.ogg",db-1,1,40};
			sound[] = {"sound0",1};
		};
		class SlamTheDoor
		{
			loop = 1;
			terminate = 0;
			trigger = "(1 - direction)";
			sound0[] = {"\rds_a2port_civ\data\sounds\blinker_off.ogg",db-1,1,40};
			sound[] = {"sound0",1};
		};
	};

	class RDS_Gearbox
	{
		class GearMovement
		{
			loop = 0;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"\rds_a2port_civ\data\Gear_Change",db+26,1,60};
			sound[] = {"sound0",1};
		};
	};
	class RDS_Wipers
	{
		class DoorMovement
		{
			loop = 0;
			terminate = 1;
			trigger = "(phase factor[0.05,0.10]) * (phase factor[0.95,0.9])";
			sound0[] = {"\rds_a2port_civ\data\wipers.wss",db+8,1,60};
			sound[] = {"sound0",1};
		};
	};
};