// Fill out your copyright notice in the Description page of Project Settings.


#include "DifferentialWheeledVehicle.h"
#include "DS_VehicleMovementComponent.h"
#include "Engine/CollisionProfile.h"
#include "Components/SkeletalMeshComponent.h"
#include "DisplayDebugHelpers.h"

FName ADifferentialWheeledVehicle::VehicleMeshComponentName(TEXT("VehicleMesh"));
FName ADifferentialWheeledVehicle::VehicleMovementComponentName(TEXT("MovementComp"));

PRAGMA_DISABLE_DEPRECATION_WARNINGS

ADifferentialWheeledVehicle::ADifferentialWheeledVehicle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(VehicleMeshComponentName);
	Mesh->SetCollisionProfileName(UCollisionProfile::Vehicle_ProfileName);
	Mesh->BodyInstance.bSimulatePhysics = true;
	Mesh->BodyInstance.bNotifyRigidBodyCollision = true;
	Mesh->BodyInstance.bUseCCD = true;
	Mesh->bBlendPhysics = true;
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetCanEverAffectNavigation(false);
	RootComponent = Mesh;

	VehicleMovement = CreateDefaultSubobject<UDS_VehicleMovementComponent>(VehicleMovementComponentName);
	VehicleMovement->SetIsReplicated(true); // Enable replication by default
	VehicleMovement->UpdatedComponent = Mesh;

}

void ADifferentialWheeledVehicle::DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	static FName NAME_Vehicle = FName(TEXT("Vehicle"));

	Super::DisplayDebug(Canvas, DebugDisplay, YL, YPos);

	if (DebugDisplay.IsDisplayOn(NAME_Vehicle))
	{
#if WITH_PHYSX && PHYSICS_INTERFACE_PHYSX
		GetVehicleMovementComponent()->DrawDebug(Canvas, YL, YPos);
#endif // WITH_PHYSX
	}
}

class UDS_VehicleMovementComponent* ADifferentialWheeledVehicle::GetVehicleMovementComponent() const
{
	return VehicleMovement;
}

PRAGMA_ENABLE_DEPRECATION_WARNINGS



//// Called when the game starts or when spawned
//void ADifferentialWheeledVehicle::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

//// Called every frame
//void ADifferentialWheeledVehicle::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//// Called to bind functionality to input
//void ADifferentialWheeledVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

