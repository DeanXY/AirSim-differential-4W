// Fill out your copyright notice in the Description page of Project Settings.


#include "DifferentialCarPawn.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/Controller.h"
#include "Components/TextRenderComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "DS_VehicleMovementComponent.h"

#include "CarWheelLeft.h"
#include "CarWheelRight.h"

#include "AirBlueprintLib.h"
#include <vector>
#include "common/common_utils/Utils.hpp"
#include "common/ClockFactory.hpp"
#include "GenericPlatform/GenericPlatformMath.h"

#define LOCTEXT_NAMESPACE "VehiclePawn"

// Sets default values
ADifferentialCarPawn::ADifferentialCarPawn()
{
	//// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APIPCamera> pip_camera_class(TEXT("Blueprint'/AirSim/Blueprints/BP_PIPCamera'"));
	pip_camera_class_ = pip_camera_class.Succeeded() ? pip_camera_class.Class : nullptr;

	const auto& car_mesh_paths = AirSimSettings::singleton().pawn_paths["DefaultCar"];
	auto slippery_mat = Cast<UPhysicalMaterial>(
		UAirBlueprintLib::LoadObject(car_mesh_paths.slippery_mat));
	auto non_slippery_mat = Cast<UPhysicalMaterial>(
		UAirBlueprintLib::LoadObject(car_mesh_paths.non_slippery_mat));
	if (slippery_mat)
		slippery_mat_ = slippery_mat;
	else
		UAirBlueprintLib::LogMessageString("Failed to load Slippery physics material", "", LogDebugLevel::Failure);
	if (non_slippery_mat)
		non_slippery_mat_ = non_slippery_mat;
	else
		UAirBlueprintLib::LogMessageString("Failed to load NonSlippery physics material", "", LogDebugLevel::Failure);

	setupVehicleMovementComponent();

	// Create In-Car camera component
	camera_front_center_base_ = CreateDefaultSubobject<USceneComponent>(TEXT("camera_front_center_base_"));
	camera_front_center_base_->SetRelativeLocation(FVector(200, 0, 100)); //center
	camera_front_center_base_->SetupAttachment(GetMesh());
	camera_front_left_base_ = CreateDefaultSubobject<USceneComponent>(TEXT("camera_front_left_base_"));
	camera_front_left_base_->SetRelativeLocation(FVector(200, -12.5, 100)); //left
	camera_front_left_base_->SetupAttachment(GetMesh());
	camera_front_right_base_ = CreateDefaultSubobject<USceneComponent>(TEXT("camera_front_right_base_"));
	camera_front_right_base_->SetRelativeLocation(FVector(200, 12.5, 100)); //right
	camera_front_right_base_->SetupAttachment(GetMesh());
	camera_driver_base_ = CreateDefaultSubobject<USceneComponent>(TEXT("camera_driver_base_"));
	camera_driver_base_->SetRelativeLocation(FVector(0, -25, 125)); //driver
	camera_driver_base_->SetupAttachment(GetMesh());
	camera_back_center_base_ = CreateDefaultSubobject<USceneComponent>(TEXT("camera_back_center_base_"));
	camera_back_center_base_->SetRelativeLocation(FVector(-200, 0, 100)); //rear
	camera_back_center_base_->SetupAttachment(GetMesh());

	// In car HUD
	// Create text render component for in car speed display
	speed_text_render_ = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarSpeed"));
	speed_text_render_->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	speed_text_render_->SetRelativeLocation(FVector(35.0f, -6.0f, 20.0f));
	speed_text_render_->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	speed_text_render_->SetupAttachment(GetMesh());
	speed_text_render_->SetVisibility(true);

	//// Create text render component for in car gear display
	//gear_text_render_ = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
	//gear_text_render_->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	//gear_text_render_->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	//gear_text_render_->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	//gear_text_render_->SetupAttachment(GetMesh());
	//gear_text_render_->SetVisibility(true);

	// Setup the audio component and allocate it a sound cue
	ConstructorHelpers::FObjectFinder<USoundCue> SoundCue(TEXT("/AirSim/VehicleAdv/Sound/Engine_Loop_Cue.Engine_Loop_Cue"));
	engine_sound_audio_ = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineSound"));
	engine_sound_audio_->SetSound(SoundCue.Object);
	engine_sound_audio_->SetupAttachment(GetMesh());

	// Colors for the in-car gear display. One for normal one for reverse
	/*last_gear_display_reverse_color_ = FColor(255, 0, 0, 255);
	last_gear_display_color_ = FColor(255, 255, 255, 255);*/

	is_low_friction_ = true;

}

// Called when the game starts or when spawned
void ADifferentialCarPawn::BeginPlay()
{
	Super::BeginPlay();

	// Start an engine sound playing
	engine_sound_audio_->Play();

}

// Called every frame
void ADifferentialCarPawn::Tick(float Delta)
{
	Super::Tick(Delta);

	// update physics material
	updatePhysicsMaterial();

	// Update the strings used in the HUD (in-car and on-screen)
	updateHUDStrings();

	// Set the string in the in-car HUD
	updateInCarHUD();

	// Pass the engine RPM to the sound component
	float RPMToAudioScale = 2500.0f / GetVehicleMovement()->GetEngineMaxRotationSpeed();
	engine_sound_audio_->SetFloatParameter(FName("RPM"), GetVehicleMovement()->GetEngineRotationSpeed() * RPMToAudioScale);

	pawn_events_.getPawnTickSignal().emit(Delta);

}

//// Called to bind functionality to input
//void ADifferentialCarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

void ADifferentialCarPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	camera_front_center_ = nullptr;
	camera_front_left_ = nullptr;
	camera_front_right_ = nullptr;
	camera_driver_ = nullptr;
	camera_back_center_ = nullptr;

	camera_front_center_base_ = nullptr;
	camera_front_left_base_ = nullptr;
	camera_front_right_base_ = nullptr;
	camera_driver_base_ = nullptr;
	camera_back_center_base_ = nullptr;
}

void ADifferentialCarPawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	pawn_events_.getCollisionSignal().emit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

void ADifferentialCarPawn::initializeForBeginPlay(bool engine_sound)
{
	if (engine_sound)
		engine_sound_audio_->Activate();
	else
		engine_sound_audio_->Deactivate();

	//put camera little bit above vehicle
	FTransform camera_transform(FVector::ZeroVector);
	FActorSpawnParameters camera_spawn_params;
	camera_spawn_params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	camera_spawn_params.Name = FName(*(this->GetName() + "_camera_front_center"));
	camera_front_center_ = this->GetWorld()->SpawnActor<APIPCamera>(pip_camera_class_, camera_transform, camera_spawn_params);
	camera_front_center_->AttachToComponent(camera_front_center_base_, FAttachmentTransformRules::KeepRelativeTransform);

	camera_spawn_params.Name = FName(*(this->GetName() + "_camera_front_left"));
	camera_front_left_ = this->GetWorld()->SpawnActor<APIPCamera>(pip_camera_class_, camera_transform, camera_spawn_params);
	camera_front_left_->AttachToComponent(camera_front_left_base_, FAttachmentTransformRules::KeepRelativeTransform);

	camera_spawn_params.Name = FName(*(this->GetName() + "_camera_front_right"));
	camera_front_right_ = this->GetWorld()->SpawnActor<APIPCamera>(pip_camera_class_, camera_transform, camera_spawn_params);
	camera_front_right_->AttachToComponent(camera_front_right_base_, FAttachmentTransformRules::KeepRelativeTransform);

	camera_spawn_params.Name = FName(*(this->GetName() + "_camera_driver"));
	camera_driver_ = this->GetWorld()->SpawnActor<APIPCamera>(pip_camera_class_, camera_transform, camera_spawn_params);
	camera_driver_->AttachToComponent(camera_driver_base_, FAttachmentTransformRules::KeepRelativeTransform);

	camera_spawn_params.Name = FName(*(this->GetName() + "_camera_back_center"));
	camera_back_center_ = this->GetWorld()->SpawnActor<APIPCamera>(pip_camera_class_,
		FTransform(FRotator(0, -180, 0), FVector::ZeroVector),
		camera_spawn_params);
	camera_back_center_->AttachToComponent(camera_back_center_base_, FAttachmentTransformRules::KeepRelativeTransform);

	setupInputBindings();
}

const common_utils::UniqueValueMap<std::string, APIPCamera*> ADifferentialCarPawn::getCameras() const
{
	common_utils::UniqueValueMap<std::string, APIPCamera*> cameras;
	cameras.insert_or_assign("front_center", camera_front_center_);
	cameras.insert_or_assign("front_right", camera_front_right_);
	cameras.insert_or_assign("front_left", camera_front_left_);
	cameras.insert_or_assign("fpv", camera_driver_);
	cameras.insert_or_assign("back_center", camera_back_center_);

	cameras.insert_or_assign("0", camera_front_center_);
	cameras.insert_or_assign("1", camera_front_right_);
	cameras.insert_or_assign("2", camera_front_left_);
	cameras.insert_or_assign("3", camera_driver_);
	cameras.insert_or_assign("4", camera_back_center_);

	cameras.insert_or_assign("", camera_front_center_);

	return cameras;
}

UDS_VehicleMovementComponent* ADifferentialCarPawn::getVehicleMovementComponent() const
{
	return GetVehicleMovement();
}


//输出Gear需要进行调整
void ADifferentialCarPawn::updateHUDStrings()
{
	
	float speed_unit_factor = AirSimSettings::singleton().speed_unit_factor;
	FText speed_unit_label = FText::FromString(FString(AirSimSettings::singleton().speed_unit_label.c_str()));
	float vel = FMath::Abs(GetVehicleMovement()->GetForwardSpeed() / 100); //cm/s -> m/s
	float vel_rounded = FMath::FloorToInt(vel * 10 * speed_unit_factor) / 10.0f;
	//int32 Gear = GetVehicleMovement()->GetCurrentGear();

	// Using FText because this is display text that should be localizable
	last_speed_ = FText::Format(LOCTEXT("SpeedFormat", "{0} {1}"), FText::AsNumber(vel_rounded), speed_unit_label);

	/*if (GetVehicleMovement()->GetCurrentGear() < 0) {
		last_gear_ = FText(LOCTEXT("ReverseGear", "R"));
	}
	else {
		last_gear_ = (Gear == 0) ? LOCTEXT("N", "N") : FText::AsNumber(Gear);
	}*/

	UAirBlueprintLib::LogMessage(TEXT("Speed: "), last_speed_.ToString(), LogDebugLevel::Informational);
	UAirBlueprintLib::LogMessage(TEXT("Forward Speed: "), FText::AsNumber((GetVehicleMovement()->GetForwardSpeed())/100).ToString(), LogDebugLevel::Informational);
	//UAirBlueprintLib::LogMessage(TEXT("Gear: "), last_gear_.ToString(), LogDebugLevel::Informational);
	UAirBlueprintLib::LogMessage(TEXT("FL_RPM: "), FText::AsNumber(GetVehicleMovement()->GetFrontLfetWheelRotationSpeed_0()).ToString(), LogDebugLevel::Informational);
	UAirBlueprintLib::LogMessage(TEXT("FR_RPM: "), FText::AsNumber(GetVehicleMovement()->GetFrontRightWheelRotationSpeed_0()).ToString(), LogDebugLevel::Informational);
	UAirBlueprintLib::LogMessage(TEXT("RL_RPM: "), FText::AsNumber(GetVehicleMovement()->GetRearLeftWheelRotationSpeed_0()).ToString(), LogDebugLevel::Informational);
	UAirBlueprintLib::LogMessage(TEXT("RR_RPM: "), FText::AsNumber(GetVehicleMovement()->GetRearRightWheelRotationSpeed_0()).ToString(), LogDebugLevel::Informational);

}

void ADifferentialCarPawn::setupVehicleMovementComponent()
{
	UDS_VehicleMovementComponent* movement = CastChecked<UDS_VehicleMovementComponent>(getVehicleMovementComponent());
	//设定四轮
	movement->WheelSetups.AddDefaulted(8);

	movement->WheelSetups[0].WheelClass = UCarWheelLeft::StaticClass();
	movement->WheelSetups[0].BoneName = FName("WheelFL");
	movement->WheelSetups[0].AdditionalOffset = FVector(0.f, -8.f, 0.f);
	movement->WheelSetups[0].bDisableSteering=true;

	movement->WheelSetups[1].WheelClass = UCarWheelRight::StaticClass();
	movement->WheelSetups[1].BoneName = FName("WheelFR");
	movement->WheelSetups[1].AdditionalOffset = FVector(0.f, 8.f, 0.f);
	movement->WheelSetups[1].bDisableSteering = true;

	movement->WheelSetups[2].WheelClass = UCarWheelLeft::StaticClass();
	movement->WheelSetups[2].BoneName = FName("WheelBL");
	movement->WheelSetups[2].AdditionalOffset = FVector(0.f, -8.f, 0.f);
	movement->WheelSetups[2].bDisableSteering = true;

	movement->WheelSetups[3].WheelClass = UCarWheelRight::StaticClass();
	movement->WheelSetups[3].BoneName = FName("WheelBR");
	movement->WheelSetups[3].AdditionalOffset = FVector(0.f, 8.f, 0.f);
	movement->WheelSetups[3].bDisableSteering = true;

	movement->WheelSetups[4].WheelClass = UCarWheelLeft::StaticClass();
	movement->WheelSetups[4].BoneName = FName("WheelFL");
	movement->WheelSetups[4].AdditionalOffset = FVector(0.f, -8.f, 0.f);
	movement->WheelSetups[4].bDisableSteering=true;

	movement->WheelSetups[5].WheelClass = UCarWheelRight::StaticClass();
	movement->WheelSetups[5].BoneName = FName("WheelFR");
	movement->WheelSetups[5].AdditionalOffset = FVector(0.f, 8.f, 0.f);
	movement->WheelSetups[5].bDisableSteering = true;

	movement->WheelSetups[6].WheelClass = UCarWheelLeft::StaticClass();
	movement->WheelSetups[6].BoneName = FName("WheelBL");
	movement->WheelSetups[6].AdditionalOffset = FVector(0.f, -8.f, 0.f);
	movement->WheelSetups[6].bDisableSteering = true;

	movement->WheelSetups[7].WheelClass = UCarWheelRight::StaticClass();
	movement->WheelSetups[7].BoneName = FName("WheelBR");
	movement->WheelSetups[7].AdditionalOffset = FVector(0.f, 8.f, 0.f);
	movement->WheelSetups[7].bDisableSteering = true;

	// Adjust the tire loading
	movement->MinNormalizedTireLoad = 0.0f;
	movement->MinNormalizedTireLoadFiltered = 0.2308f;
	movement->MaxNormalizedTireLoad = 2.0f;
	movement->MaxNormalizedTireLoadFiltered = 2.0f;


	//注：simplewheeledvehiclemovementcomponent没有档位、扭矩曲线、转向曲线、四轮差速


	movement->bReverseAsBrake=false;

	// Physics settings
   // Adjust the center of mass - the buggy is quite low
	UPrimitiveComponent* primitive = Cast<UPrimitiveComponent>(movement->UpdatedComponent);
	if (primitive) {
		primitive->BodyInstance.COMNudge = FVector(8.0f, 0.0f, 0.0f);
	}

	// Set the inertia scale. This controls how the mass of the vehicle is distributed.
	movement->InertiaTensorScale = FVector(1.0f, 1.333f, 1.2f);
	movement->bDeprecatedSpringOffsetMode = true;
}

void ADifferentialCarPawn::updateInCarHUD()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if ((PlayerController != nullptr) && (speed_text_render_ != nullptr) && (gear_text_render_ != nullptr)) {
		// Setup the text render component strings
		speed_text_render_->SetText(last_speed_);
		//gear_text_render_->SetText(last_gear_);

		/*if (GetVehicleMovement()->GetCurrentGear() >= 0) {
			gear_text_render_->SetTextRenderColor(last_gear_display_color_);
		}
		else {
			gear_text_render_->SetTextRenderColor(last_gear_display_reverse_color_);
		}*/
	}
}

void ADifferentialCarPawn::updatePhysicsMaterial()
{
	if (GetActorUpVector().Z < 0) {
		if (is_low_friction_ == true) {
			GetMesh()->SetPhysMaterialOverride(non_slippery_mat_);
			is_low_friction_ = false;
		}
		else {
			GetMesh()->SetPhysMaterialOverride(slippery_mat_);
			is_low_friction_ = true;
		}
	}
}

void ADifferentialCarPawn::setupInputBindings()
{
	UAirBlueprintLib::EnableInput(this);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveForward", EKeys::Up, 1.0), this, this, &ADifferentialCarPawn::onMoveForward);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveForward", EKeys::Down, -1.0), this, this, &ADifferentialCarPawn::onMoveForward);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveRight", EKeys::Right, 1.0), this, this, &ADifferentialCarPawn::onMoveRight);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveRight", EKeys::Left, -1.0), this, this, &ADifferentialCarPawn::onMoveRight);



	UAirBlueprintLib::BindActionToKey("Handbrake", EKeys::End, this, &ADifferentialCarPawn::onHandbrakePressed, true);
	UAirBlueprintLib::BindActionToKey("Handbrake", EKeys::End, this, &ADifferentialCarPawn::onHandbrakeReleased, false);


	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Right", EKeys::D, 1.0), this, this, &ADifferentialCarPawn::onRight);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Right", EKeys::A, -1.0), this, this, &ADifferentialCarPawn::onRight);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Left", EKeys::W, 1.0), this, this, &ADifferentialCarPawn::onLeft);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Left", EKeys::S, -1.0), this, this, &ADifferentialCarPawn::onLeft);
	/*UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Footbrake", EKeys::SpaceBar, 1), this, this, &ADifferentialCarPawn::onFootBrake);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveRight", EKeys::Gamepad_LeftX, 1), this, this, &ADifferentialCarPawn::onMoveRight);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("MoveForward", EKeys::Gamepad_RightTriggerAxis, 1), this, this, &ADifferentialCarPawn::onMoveForward);

	UAirBlueprintLib::BindAxisToKey(FInputAxisKeyMapping("Footbrake", EKeys::Gamepad_LeftTriggerAxis, 1), this, this, &ADifferentialCarPawn::onFootBrake);*/

	//below is not needed
	//UAirBlueprintLib::BindActionToKey("Reverse", EKeys::Down, this, &ACarPawn::onReversePressed, true);
	//UAirBlueprintLib::BindActionToKey("Reverse", EKeys::Down, this, &ACarPawn::onReverseReleased, false);
}

void ADifferentialCarPawn::onMoveForward(float Val)
{

	//float torque_val=300.0f;//Nm
	keyboard_controls_.torque_FL = 600 * Val;
	keyboard_controls_.torque_FR = 600 * Val;
	keyboard_controls_.torque_RL = 600 * Val;
	keyboard_controls_.torque_RR = 600 * Val;
	/*GetVehicleMovement()->SetDriveTorque(keyboard_controls_.torque_FL, 0);
	GetVehicleMovement()->SetDriveTorque(keyboard_controls_.torque_FL, 1);
	GetVehicleMovement()->SetDriveTorque(keyboard_controls_.torque_FL, 2);
	GetVehicleMovement()->SetDriveTorque(keyboard_controls_.torque_FL, 3);*/
}

void ADifferentialCarPawn::onMoveRight(float Val)
{
	if (Val > 0)
	{
		keyboard_controls_.torque_FL = 600 * Val;
		keyboard_controls_.torque_FR = 600 * Val;
		keyboard_controls_.torque_RL = 600 * Val;
		keyboard_controls_.torque_RR = 600 * Val;
	}
	else
	{
		keyboard_controls_.torque_FL = -600 * Val;
		keyboard_controls_.torque_FR = -600 * Val;
		keyboard_controls_.torque_RL = 600 * Val;
		keyboard_controls_.torque_RR = 600 * Val;
	}
}

void ADifferentialCarPawn::onHandbrakePressed()
{
	keyboard_controls_.handbrake=true;
}

void ADifferentialCarPawn::onHandbrakeReleased()
{
	keyboard_controls_.handbrake=false;
}

void ADifferentialCarPawn::onRight(float Val)
{
	if (abs(Val) < 0.01)
	{
		keyboard_controls_.torque_FR = 0;
		keyboard_controls_.torque_RR = 0;

	}
	else
	{
		if (Val > 0)
		{
			keyboard_controls_.torque_FR = 800;
			keyboard_controls_.torque_RR = 800;
		}
		else
		{
			keyboard_controls_.torque_RR = -800;
			keyboard_controls_.torque_FR = -800;
		}
	}
	
}

void ADifferentialCarPawn::onLeft(float Val)
{
	if (abs(Val) < 0.01)
	{
		keyboard_controls_.torque_FL=0;
		keyboard_controls_.torque_RL=0;
	}
	else
	{
		if (Val > 0)
		{
			keyboard_controls_.torque_FL = 800;
			keyboard_controls_.torque_RL = 800;
		}
		else
		{
			keyboard_controls_.torque_FL = -800;
			keyboard_controls_.torque_RL = -800;
		}
	}
	
}
