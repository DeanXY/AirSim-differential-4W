// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "vehicles/car/api/CarApiBase.hpp"
#include "DS_VehicleMovementComponent.h"
#include "physics/Kinematics.hpp"
#include "DifferentialCarPawn.h"

/**
 * 
 */
class AIRSIM_API DifferentialCarPawnApi
{
public:
	typedef msr::airlib::ImageCaptureBase ImageCaptureBase;

	DifferentialCarPawnApi(ADifferentialCarPawn* pawn, const msr::airlib::Kinematics::State* pawn_kinematics,
		msr::airlib::CarApiBase* vehicle_api);

	void updateMovement(const msr::airlib::CarApiBase::DifferentialCarControls& controls);

	msr::airlib::CarApiBase::DifferentialCarState getDifferentialCarState() const;

	void reset();
	void update();

	virtual ~DifferentialCarPawnApi();

private:
	UDS_VehicleMovementComponent* movement_;
	msr::airlib::CarApiBase::DifferentialCarControls last_controls_;
	ADifferentialCarPawn* pawn_;
	const msr::airlib::Kinematics::State* pawn_kinematics_;
	msr::airlib::CarApiBase* vehicle_api_;
};
