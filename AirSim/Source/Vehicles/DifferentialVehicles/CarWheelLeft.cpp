// Fill out your copyright notice in the Description page of Project Settings.


#include "CarWheelLeft.h"
#include "TireConfig.h"
#include "UObject/ConstructorHelpers.h"

UCarWheelLeft::UCarWheelLeft()
{
	ShapeRadius = 18.f;
	ShapeWidth = 15.0f;
	Mass = 20.0f;
	DampingRate = 0.25f;
	bAffectedByHandbrake = false;
	SteerAngle = 40.f;

	// Setup suspension forces
	SuspensionForceOffset = 0.0f;
	SuspensionMaxRaise = 10.0f;
	SuspensionMaxDrop = 10.0f;
	SuspensionNaturalFrequency = 9.0f;
	SuspensionDampingRatio = 1.05f;

	// Find the tire object and set the data for it
	static ConstructorHelpers::FObjectFinder<UTireConfig> TireData(TEXT("/AirSim/VehicleAdv/Vehicle/WheelData/Vehicle_FrontTireConfig.Vehicle_FrontTireConfig"));
	TireConfig = TireData.Object;
}
