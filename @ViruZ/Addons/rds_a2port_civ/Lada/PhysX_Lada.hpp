		normalSpeedForwardCoef=0.95;

		enginePower=56.7;
		maxOmega=628.32;
		peakTorque=106;

		idleRPM=600;
		redRpm=6000;

		terrainCoef=1.05;
		turnCoef=2.5;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=156;
		fuelCapacity=50;
		wheelCircumference=1.866;

		antiRollbarForceCoef=0.0;
		antiRollbarForceLimit=0.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;

		changeGearMinEffectivity[]={0.95,0.15,0.95,0.95,0.95,0.85};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3.87,
				"N",
				0,
				"D1",
				3.85,
				"D2",
				2.30,
				"D3",
				1.49,
				"D4",
				1.0
			};
			TransmissionRatios[]=
			{
				"High",
				3.994
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};

		simulation="carx";
		dampersBumpCoef=4;
		differentialType="rear_limited";
		frontRearSplit=0.5;
		frontBias=1.5;
		rearBias=3.5;
		centreBias=3.3;
		clutchStrength=85;

		dampingRateFullThrottle=0.08;
		dampingRateZeroThrottleClutchEngaged=1.35;
		dampingRateZeroThrottleClutchDisengaged=0.35;
		torqueCurve[] =
		{
			{"0/6000" , "0/106"},
			{"798/6000" , "89/106"},
			{"1398/6000" , "92/106"},
			{"2298/6000" , "98/106"},
			{"3402/6000" , "106/106"},
			{"4902/6000" , "103/106"},
			{"5598/6000" , "95/106"},
			{"6300/6000" , "0/106"}
		};


		switchTime=0.31;
		latency=1;
		class Wheels
		{
			class LF
			{
				width = "0.05";
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				mass=17;
				MOI=19.0;
				dampingRate=0.1;
				maxBrakeTorque=1200;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.15;
				mMaxDroop=0.15;
				sprungMass=185.5;
				springStrength=45025;
				springDamperRate=4700;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=1.5;
				latStiffY=15.0;
				frictionVsSlipGraph[]=
				{
					{0,1.11},
					{0.5,1.1},
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
				maxHandBrakeTorque=2000;
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
				maxHandBrakeTorque=2000;
			};
		};