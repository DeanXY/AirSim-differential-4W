// Fill out your copyright notice in the Description page of Project Settings.
//添加输出各个轮速的函数，只针对四轮
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "SimpleWheeledVehicleMovementComponent.h"

#include "DS_VehicleMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Physics), meta = (BlueprintSpawnableComponent), hidecategories = (PlanarMovement, "Components|Movement|Planar", Activation, "Components|Activation"))
class AIRSIM_API UDS_VehicleMovementComponent : public USimpleWheeledVehicleMovementComponent
{
	GENERATED_BODY()
public:
	/**Get current Front_Left wheel rotation speed,wheelindex=0**/
	//UFUNCTION(BlueprintCallable, Category = Vehicle)
	float GetFrontLfetWheelRotationSpeed_0() const;
    float GetFrontLfetWheelRotationSpeed_1() const;
	/**Get current Front_Right wheel rotation speed,wheelindex=1**/
	//UFUNCTION(BlueprintCallable, Category = Vehicle)
	float GetFrontRightWheelRotationSpeed_0() const;
    float GetFrontRightWheelRotationSpeed_1() const;

	/**Get current Rear_Left wheel rotation speed,wheelindex=2**/
	//UFUNCTION(BlueprintCallable, Category = Vehicle)
	float GetRearLeftWheelRotationSpeed_0() const;
    float GetRearLeftWheelRotationSpeed_1() const;

	/**Get current Rear_Right wheel rotation speed,wheelindex=3**/
	//UFUNCTION(BlueprintCallable, Category = Vehicle)
	float GetRearRightWheelRotationSpeed_0() const;
    float GetRearRightWheelRotationSpeed_1() const;
	
};
