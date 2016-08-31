	//24D
//	normalSpeedForwardCoef=0.95;

		enginePower=69.9;
		maxOmega=513.13;
		peakTorque=186.3;

		idleRPM=600;
		redRpm=4900;

		terrainCoef=1.3;
		turnCoef=2.0;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=156;
		fuelCapacity=50;
		wheelCircumference=2.04;

		antiRollbarForceCoef=0.0;
		antiRollbarForceLimit=0.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;

		changeGearMinEffectivity[]={0.95,0.15,0.85,0.95,0.95,0.95};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3.54,
				"N",
				0,
				"D1",
				3.5,
				"D2",
				2.26,
				"D3",
				1.45,
				"D4",
				1.0
			};
			TransmissionRatios[]=
			{
				"High",
				4.1
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

		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=1.34999999;
		dampingRateZeroThrottleClutchDisengaged=0.34999999;
		torqueCurve[] =
		{
			{"0/4900" , "0/186"},
			{"799/4900" , "139/186"},
			{"1401/4900" , "162/186"},
			{"2298/4900" , "186/186"},
			{"3401/4900" , "175/186"},
			{"3900/4900" , "166/186"},
			{"4498/4900" , "147/186"},
			{"4998/4900" , "0/186"}
		};

		latency=1;
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
				mass=17;
				MOI=14.0;
				dampingRate=0.1;
				maxBrakeTorque=1300;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.5;
				mMaxDroop=0.5;
				sprungMass=345.5;
				springStrength=45025;
				springDamperRate=4700;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=1.7;
				latStiffY=16.0;
				frictionVsSlipGraph[]=
				{
					{0,1.41},
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