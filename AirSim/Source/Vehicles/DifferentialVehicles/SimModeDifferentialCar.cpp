// Fill out your copyright notice in the Description page of Project Settings.


#include "SimModeDifferentialCar.h"
#include "UObject/ConstructorHelpers.h"

#include "AirBlueprintLib.h"
#include "common/AirSimSettings.hpp"
#include "DifferentialCarPawnSimApi.h"
#include "AirBlueprintLib.h"
#include "common/Common.hpp"
#include "common/EarthUtils.hpp"
#include "vehicles/car/api/CarRpcLibServer.hpp"

extern CORE_API uint32 GFrameNumber;

void ASimModeDifferentialCar::BeginPlay()
{
	Super::BeginPlay();

	initializePauseState();
}

void ASimModeDifferentialCar::initializePauseState()
{
	pause_period_ = 0;
	pause_period_start_ = 0;
	pause(false);
}

bool ASimModeDifferentialCar::isPaused() const
{
	return current_clockspeed_ == 0;
}

void ASimModeDifferentialCar::pause(bool is_paused)
{
	if (is_paused)
		current_clockspeed_ = 0;
	else
		current_clockspeed_ = getSettings().clock_speed;

	UAirBlueprintLib::setUnrealClockSpeed(this, current_clockspeed_);
}

void ASimModeDifferentialCar::continueForTime(double seconds)
{
	pause_period_start_ = ClockFactory::get()->nowNanos();
	pause_period_ = seconds;
	pause(false);
}

void ASimModeDifferentialCar::continueForFrames(uint32_t frames)
{
	targetFrameNumber_ = GFrameNumber + frames;
	frame_countdown_enabled_ = true;
	pause(false);
}

void ASimModeDifferentialCar::setupClockSpeed()
{
	current_clockspeed_ = getSettings().clock_speed;

	//setup clock in PhysX
	UAirBlueprintLib::setUnrealClockSpeed(this, current_clockspeed_);
	UAirBlueprintLib::LogMessageString("Clock Speed: ", std::to_string(current_clockspeed_), LogDebugLevel::Informational);
}


void ASimModeDifferentialCar::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (pause_period_start_ > 0) {
		if (ClockFactory::get()->elapsedSince(pause_period_start_) >= pause_period_) {
			if (!isPaused())
				pause(true);

			pause_period_start_ = 0;
		}
	}

	if (frame_countdown_enabled_) {
		if (targetFrameNumber_ <= GFrameNumber) {
			if (!isPaused())
				pause(true);

			frame_countdown_enabled_ = false;
		}
	}
}

//-------------------------------- overrides -----------------------------------------------//
std::unique_ptr<msr::airlib::ApiServerBase> ASimModeDifferentialCar::createApiServer() const
{
#ifdef AIRLIB_NO_RPC
	return ASimModeBase::createApiServer();
#else
	return std::unique_ptr<msr::airlib::ApiServerBase>(new msr::airlib::DifferentialCarRpcLibServer(
		getApiProvider(), getSettings().api_server_address, getSettings().api_port));
#endif
}

void ASimModeDifferentialCar::getExistingVehiclePawns(TArray<AActor*>& pawns) const
{
	UAirBlueprintLib::FindAllActor<TVehiclePawn>(this, pawns);
}

bool ASimModeDifferentialCar::isVehicleTypeSupported(const std::string& vehicle_type) const
{
	return ((vehicle_type == AirSimSettings::kVehicleTypePhysXCar) ||
		(vehicle_type == AirSimSettings::kVehicleTypeArduRover));
}

std::string ASimModeDifferentialCar::getVehiclePawnPathName(const AirSimSettings::VehicleSetting& vehicle_setting) const
{
	//decide which derived BP to use
	std::string pawn_path = vehicle_setting.pawn_path;
	if (pawn_path == "")
		pawn_path = "DefaultCar";

	return pawn_path;
}

PawnEvents* ASimModeDifferentialCar::getVehiclePawnEvents(APawn* pawn) const
{
	return static_cast<TVehiclePawn*>(pawn)->getPawnEvents();
}
const common_utils::UniqueValueMap<std::string, APIPCamera*> ASimModeDifferentialCar::getVehiclePawnCameras(
	APawn* pawn) const
{
	return (static_cast<const TVehiclePawn*>(pawn))->getCameras();
}
void ASimModeDifferentialCar::initializeVehiclePawn(APawn* pawn)
{
	auto vehicle_pawn = static_cast<TVehiclePawn*>(pawn);
	vehicle_pawn->initializeForBeginPlay(getSettings().engine_sound);
}
std::unique_ptr<PawnSimApi> ASimModeDifferentialCar::createVehicleSimApi(
	const PawnSimApi::Params& pawn_sim_api_params) const
{
	auto vehicle_pawn = static_cast<TVehiclePawn*>(pawn_sim_api_params.pawn);
	auto vehicle_sim_api = std::unique_ptr<PawnSimApi>(new DifferentialCarPawnSimApi(pawn_sim_api_params,
		vehicle_pawn->getKeyBoardControls(),
		vehicle_pawn->getVehicleMovementComponent()));
	vehicle_sim_api->initialize();
	vehicle_sim_api->reset();
	return vehicle_sim_api;
}
msr::airlib::VehicleApiBase* ASimModeDifferentialCar::getVehicleApi(const PawnSimApi::Params& pawn_sim_api_params,
	const PawnSimApi* sim_api) const
{
	const auto car_sim_api = static_cast<const DifferentialCarPawnSimApi*>(sim_api);
	return car_sim_api->getVehicleApi();
}