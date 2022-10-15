// Fill out your copyright notice in the Description page of Project Settings.


#include "DifferentialCarPawnApi.h"
#include "AirBlueprintLib.h"

#include "PhysXVehicleManager.h"


DifferentialCarPawnApi::DifferentialCarPawnApi(ADifferentialCarPawn* pawn, const msr::airlib::Kinematics::State* pawn_kinematics, 
		msr::airlib::CarApiBase* vehicle_api)
		: pawn_(pawn), pawn_kinematics_(pawn_kinematics), vehicle_api_(vehicle_api)
{
	movement_ = pawn->GetVehicleMovement();
}

void DifferentialCarPawnApi::updateMovement(const msr::airlib::CarApiBase::DifferentialCarControls& controls)
{
	last_controls_ = controls;
	//去除档位的更新
	movement_->SetDriveTorque(controls.torque_FL, 0);
	movement_->SetDriveTorque(controls.torque_FL, 2);
	movement_->SetDriveTorque(controls.torque_FR, 1);
	movement_->SetDriveTorque(controls.torque_FR, 3);
	movement_->SetDriveTorque(controls.torque_RL, 4);
	movement_->SetDriveTorque(controls.torque_RL, 6);
	movement_->SetDriveTorque(controls.torque_RR, 5);
	movement_->SetDriveTorque(controls.torque_RR, 7);

	if (controls.handbrake)
	{
		movement_->SetBrakeTorque(controls.torque_brake, 0);
		movement_->SetBrakeTorque(controls.torque_brake, 1);
		movement_->SetBrakeTorque(controls.torque_brake, 2);
		movement_->SetBrakeTorque(controls.torque_brake, 3);
		movement_->SetBrakeTorque(controls.torque_brake, 4);
		movement_->SetBrakeTorque(controls.torque_brake, 5);
		movement_->SetBrakeTorque(controls.torque_brake, 6);
		movement_->SetBrakeTorque(controls.torque_brake, 7);
	}
	else
	{
		movement_->SetBrakeTorque(controls.brake_none, 0);
		movement_->SetBrakeTorque(controls.brake_none, 1);
		movement_->SetBrakeTorque(controls.brake_none, 2);
		movement_->SetBrakeTorque(controls.brake_none, 3);
		movement_->SetBrakeTorque(controls.brake_none, 4);
		movement_->SetBrakeTorque(controls.brake_none, 5);
		movement_->SetBrakeTorque(controls.brake_none, 6);
		movement_->SetBrakeTorque(controls.brake_none, 7);

	}
}

msr::airlib::CarApiBase::DifferentialCarState DifferentialCarPawnApi::getDifferentialCarState() const
{
	msr::airlib::CarApiBase::DifferentialCarState state(
	movement_->GetForwardSpeed()/100,//cm/s -> m/s
	movement_->GetFrontLfetWheelRotationSpeed_0(),
	movement_->GetFrontLfetWheelRotationSpeed_1(),
	movement_->GetFrontRightWheelRotationSpeed_0(),
	movement_->GetFrontRightWheelRotationSpeed_1(),
	movement_->GetRearLeftWheelRotationSpeed_0(),
	movement_->GetRearLeftWheelRotationSpeed_1(),
	movement_->GetRearRightWheelRotationSpeed_0(),
	movement_->GetRearRightWheelRotationSpeed_1(),
	movement_->GetEngineMaxRotationSpeed(),
	last_controls_.handbrake,
	*pawn_kinematics_,
	msr::airlib::ClockFactory::get()->nowNanos()
	);
	return state;
}

void DifferentialCarPawnApi::reset()
{
	vehicle_api_->reset();

	last_controls_ = msr::airlib::CarApiBase::DifferentialCarControls();
	auto phys_comps = UAirBlueprintLib::getPhysicsComponents(pawn_);
	UAirBlueprintLib::RunCommandOnGameThread([this, &phys_comps]() {
		for (auto* phys_comp : phys_comps) {
			phys_comp->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
			phys_comp->SetPhysicsLinearVelocity(FVector::ZeroVector);
			phys_comp->SetSimulatePhysics(false);
		}
		movement_->ResetMoveState();
		movement_->SetActive(false);
		movement_->SetActive(true, true);
		vehicle_api_->setDifferentialCarControls(msr::airlib::CarApiBase::DifferentialCarControls());
		updateMovement(msr::airlib::CarApiBase::DifferentialCarControls());

		auto pv = movement_->PVehicle;
		if (pv) {
			pv->mWheelsDynData.setToRestState();
		}
		auto pvd = movement_->PVehicleDrive;
		if (pvd) {
			pvd->mDriveDynData.setToRestState();
		}
		},
		true);

	UAirBlueprintLib::RunCommandOnGameThread([this, &phys_comps]() {
		for (auto* phys_comp : phys_comps)
			phys_comp->SetSimulatePhysics(true);
		},
		true);
}

void DifferentialCarPawnApi::update()
{
	vehicle_api_->updateDifferentialCarState(getDifferentialCarState());
	vehicle_api_->update();
}

DifferentialCarPawnApi::~DifferentialCarPawnApi() = default;