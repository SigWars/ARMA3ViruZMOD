		slowSpeedForwardCoef=0.50;
		normalSpeedForwardCoef=0.55;

		enginePower=47.5;
		maxOmega=261.80	;
		peakTorque=210;

		idleRPM=600;
		redRpm=2500;

		//terrainCoef=1.7;
		turnCoef=2.0;
		precision=10;
		brakeDistance=3;
		acceleration=15;
		fireResistance=5;
		thrustDelay=0.2;
		brakeIdleSpeed=1.78;
		maxSpeed=25;
		fuelCapacity=50;
		terrainCoef = 1;
		wheelCircumference = 3.768;

		antiRollbarForceCoef=0.0;
		antiRollbarForceLimit=0.5;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;

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
				2.27,
				"D2",
				1.86,
				"D3",
				1.21,
				"D4",
				1.0
			};
			TransmissionRatios[]=
			{
				"High",
				18.0
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
		frontRearSplit=0.6;
		frontBias=0.5;
		rearBias=1.5;
		centreBias=1.3;
		clutchStrength=45;

		dampingRateFullThrottle=0.08;
		dampingRateZeroThrottleClutchEngaged=1.35;
		dampingRateZeroThrottleClutchDisengaged=0.35;
		torqueCurve[] =
		{
			{"0/2460" , "0/210"},
			{"401/2460" , "157/210"},
			{"704/2460" , "183/210"},
			{"1154/2460" , "200/210"},
			{"1501/2460" , "210/210"},
			{"2199/2460" , "204/210"},
			{"2283/2460" , "157/210"},
			{"2809/2460" , "0/210"}
		};



		switchTime=0.31;
		latency=1;
		class Wheels
		{
			class LF
			{
				side="left";
				width = "0.05";
				steering=1;

				boneName="wheel_1_1_damper";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";

				mass=23;
				MOI=4.1;

				dampingRate=0.1;
				dampingRateDamaged = 1.0;
				dampingRateDestroyed = 1000.0;

				maxBrakeTorque=1200;
				maxHandBrakeTorque=0;

				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";

				maxCompression=0.24;
				mMaxDroop=0.24;

				sprungMass=845.5;
				springStrength=42025;
				springDamperRate=5400;

				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=11.5;
				latStiffY=25.0;
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
				MOI=3.1;
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
				MOI=3.1;
			};
		};