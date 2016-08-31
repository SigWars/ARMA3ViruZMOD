	//24D
//	normalSpeedForwardCoef=0.95;

		enginePower=125;
		maxOmega=523.6;
		peakTorque=350;

		idleRPM=800;
		redRpm=5000;

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
		wheelCircumference=2.135;

		latency=1;
		switchTime = 0.31;

		antiRollbarForceCoef=10.0;
		antiRollbarForceLimit=40.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=180;

		changeGearMinEffectivity[]={0.95,0.15,0.95,0.95,0.95,0.95,0.95,0.95};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.55,
				"N",
				0,
				"D1",
				3.77,
				"D2",
				1.96,
				"D3",
				1.26,
				"D4",
				0.87,
				"D5",
				0.86,
				"D6",
				0.72
			};
			TransmissionRatios[]=
			{
				"High",
				3.45
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
			{"0/5000" , "0/350"},
			{"800/5000" , "262/350"},
			{"1750/5000" , "350/350"},
			{"2750/5000" , "350/350"},
			{"3400/5000" , "329/350"},
			{"3900/5000" , "298/350"},
			{"4200/5000" , "284/350"},
			{"5300/5000" , "0/350"}
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
				maxBrakeTorque=2900;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.2;
				mMaxDroop=-0.2;
				sprungMass=345.5;
				springStrength=45025;
				springDamperRate=4700;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=31.2;
				latStiffY=180.0;
				frictionVsSlipGraph[] = {{0, 1}, {0.5, 1}, {1,1}};
				/*frictionVsSlipGraph[]=
				{
					{0,1.61},
					{0.5,1.41},
					{1,1}
				};*/
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