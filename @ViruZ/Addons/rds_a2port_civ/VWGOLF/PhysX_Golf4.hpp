	//24D
//	normalSpeedForwardCoef=0.95;

		enginePower=81;
		maxOmega=481.71;
		peakTorque=240;

		idleRPM=800;
		redRpm=4600;

		terrainCoef=6.5;
		turnCoef=2.5;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=216;
		fuelCapacity=50;
		wheelCircumference=2.04;

		latency=1;
		switchTime = 0.31;

		antiRollbarForceCoef=0.0;
		antiRollbarForceLimit=0.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;

		changeGearMinEffectivity[]={0.95,0.15,0.95,0.95,0.95,0.95,0.95};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3.778,
				"N",
				0,
				"D1",
				3.778,
				"D2",
				2.118,
				"D3",
				1.360,
				"D4",
				0.971,
				"D5",
				0.756
			};
			TransmissionRatios[]=
			{
				"High",
				3.389
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay = 0.01;
		};

		simulation="carx";
		dampersBumpCoef=0.5;
		differentialType="front_limited";
		frontRearSplit=0.5;
		frontBias=1.5;
		rearBias=1.3;
		centreBias=1.3;
		clutchStrength=85;

		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 0.35;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		torqueCurve[] = {
			{"0/4600" , "0/240"},
			{"800/4600" , "199/240"},
			{"1799/4600" , "240/240"},
			{"2401/4600" , "240/240"},
			{"3399/4600" , "209/240"},
			{"3901/4600" , "194/240"},
			{"4149/4600" , "187/240"},
			{"4901/4600" , "30/240"}
		};


		class Wheels
		{
			class LF
			{
				width = "0.1";
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				mass=13;
				MOI=14.0;
				dampingRate=0.1;
				maxBrakeTorque=1900;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.1;
				mMaxDroop=0.1;
				sprungMass=345.5;
				springStrength=45025;
				springDamperRate=4700;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=2.2;
				latStiffY=18.0;
				frictionVsSlipGraph[]=
				{
					{0,1.61},
					{0.5,1.41},
					{1,1}
				};
			};
			class LR: LF
			{
				boneName="wheel_1_2_damper";
				steering=0;
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
				maxHandBrakeTorque=3000;
			};
			class RF: LF
			{
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				steering=1;
				side="right";
			};
			class RR: RF
			{
				boneName="wheel_2_2_damper";
				steering=0;
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
				maxHandBrakeTorque=3000;
			};
		};