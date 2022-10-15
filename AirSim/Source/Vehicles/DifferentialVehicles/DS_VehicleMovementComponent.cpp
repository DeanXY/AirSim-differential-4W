// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_VehicleMovementComponent.h"
#include "Components/PrimitiveComponent.h"

#if WITH_PHYSX
#include "PhysXPublic.h"
#include "PhysXVehicleManager.h"
#endif // WITH_PHYSX

float UDS_VehicleMovementComponent::GetFrontLfetWheelRotationSpeed_0() const
{
	float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
	if (PVehicle && WheelSetups.Num())
	{
		const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(0);
		WheelSpeedOutput = WheelSpeed;
	}
	return WheelSpeedOutput;
#endif // WITH_PHYSX
	return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetFrontLfetWheelRotationSpeed_1() const
{
    float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
    if (PVehicle && WheelSetups.Num()) {
        const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(2);
        WheelSpeedOutput = WheelSpeed;
    }
    return WheelSpeedOutput;
#endif // WITH_PHYSX
    return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetFrontRightWheelRotationSpeed_0() const
{
	float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
	if (PVehicle && WheelSetups.Num())
	{
		const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(1);
		WheelSpeedOutput = WheelSpeed;
	}
	return WheelSpeedOutput;
#endif // WITH_PHYSX
	return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetFrontRightWheelRotationSpeed_1() const
{
    float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
    if (PVehicle && WheelSetups.Num()) {
        const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(3);
        WheelSpeedOutput = WheelSpeed;
    }
    return WheelSpeedOutput;
#endif // WITH_PHYSX
    return WheelSpeedOutput;
}


float UDS_VehicleMovementComponent::GetRearLeftWheelRotationSpeed_0() const
{
	float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
	if (PVehicle && WheelSetups.Num())
	{
		const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(4);
		WheelSpeedOutput = WheelSpeed;
	}
	return WheelSpeedOutput;
#endif // WITH_PHYSX
	return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetRearLeftWheelRotationSpeed_1() const
{
    float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
    if (PVehicle && WheelSetups.Num()) {
        const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(6);
        WheelSpeedOutput = WheelSpeed;
    }
    return WheelSpeedOutput;
#endif // WITH_PHYSX
    return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetRearRightWheelRotationSpeed_0() const
{
	float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
	if (PVehicle && WheelSetups.Num())
	{
		const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(5);
		WheelSpeedOutput = WheelSpeed;
	}
	return WheelSpeedOutput;
#endif // WITH_PHYSX
	return WheelSpeedOutput;
}

float UDS_VehicleMovementComponent::GetRearRightWheelRotationSpeed_1() const
{
    float WheelSpeedOutput = 0.f;
#if WITH_PHYSX_VEHICLES
    if (PVehicle && WheelSetups.Num()) {
        const PxReal WheelSpeed = PVehicle->mWheelsDynData.getWheelRotationSpeed(7);
        WheelSpeedOutput = WheelSpeed;
    }
    return WheelSpeedOutput;
#endif // WITH_PHYSX
    return WheelSpeedOutput;
}


