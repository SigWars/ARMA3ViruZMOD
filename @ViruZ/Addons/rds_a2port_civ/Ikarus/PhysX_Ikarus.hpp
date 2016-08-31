		normalSpeedForwardCoef=0.7;

		enginePower=142;
		maxOmega=230.38;
		peakTorque=696;

		idleRPM=600;
		redRpm=2200;

		//terrainCoef=1.7;
		turnCoef=2.5;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=80;
		fuelCapacity=78;
		wheelCircumference=3.233;

		antiRollbarForceCoef=0.5;
		antiRollbarForceLimit=0.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;

		changeGearMinEffectivity[]={0.95,0.15,0.95,0.95,0.95,0.95,0.95};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-6.009,
				"N",
				0,
				"D1",
				5.81,
				"D2",
				2.98,
				"D3",
				1.992,
				"D4",
				1.438,
				"D5",
				1.0
			};
			TransmissionRatios[]=
			{
				"High",
				5.194
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};

		simulation="carx";
		dampersBumpCoef=2;
		differentialType="rear_limited";
		frontRearSplit=0.5;
		frontBias=1.5;
		rearBias=1.5;
		centreBias=1.3;
		clutchStrength=20;

		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=1.34999999;
		dampingRateZeroThrottleClutchDisengaged=0.34999999;
		torqueCurve[] = {
			{"0/2200" , "0/696"},
			{"581/2200" , "452/696"},
			{"1001/2200" , "621/696"},
			{"1300/2200" , "696/696"},
			{"1599/2200" , "691/696"},
			{"1901/2200" , "675/696"},
			{"2101/2200" , "654/696"},
			{"2299/2200" , "0/696"}
		};

		switchTime=0.31;
		latency=1;
		class Wheels
		{
			class LF
			{
				width = "0.45";
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				mass=50;
				MOI=12.7;
				dampingRate=0.1;
				maxBrakeTorque=4500;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.15;
				mMaxDroop=0.15;
				sprungMass=1985.5;
				springStrength=85025;
				springDamperRate=8700;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=12.5;
				latStiffY=180.0;
				frictionVsSlipGraph[]=
				{
					{0,1.2},
					{0.5,1.13},
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