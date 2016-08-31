		normalSpeedForwardCoef=0.90;

		enginePower=37.5;
		maxOmega=523.6;
		peakTorque=88;

		idleRPM=600;
		redRpm=5000;

		terrainCoef=1.1;
		turnCoef=2.0;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=115;
		fuelCapacity=50;
		wheelCircumference=2.02;

		antiRollbarForceCoef=13.6;
		antiRollbarForceLimit=40.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=90;

		changeGearMinEffectivity[]={0.95,0.15,0.95,0.95,0.95,0.95};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-5.61,
				"N",
				0,
				"D1",
				4.27,
				"D2",
				2.46,
				"D3",
				1.51,
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
		clutchStrength=45;

		dampingRateFullThrottle=0.08;
		dampingRateZeroThrottleClutchEngaged=1.35;
		dampingRateZeroThrottleClutchDisengaged=0.35;
		torqueCurve[] =
		{
			{"0/5000" , "0/88"},
			{"800/5000" , "57/88"},
			{"1400/5000" , "70/88"},
			{"2300/5000" , "81/88"},
			{"3000/5000" , "88/88"},
			{"3900/5000" , "85/88"},
			{"4600/5000" , "77/88"},
			{"5250/5000" , "0/88"}
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
				mass=23;
				MOI=51.0;
				dampingRate=0.1;
				maxBrakeTorque=2200;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.15;
				mMaxDroop=0.15;
				sprungMass=245.5;
				springStrength=42025;
				springDamperRate=5400;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=11.5;
				latStiffY=45.0;
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