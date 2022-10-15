// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Vehicles/DifferentialVehicles/DS_VehicleMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDS_VehicleMovementComponent() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_UDS_VehicleMovementComponent_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_UDS_VehicleMovementComponent();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_USimpleWheeledVehicleMovementComponent();
	UPackage* Z_Construct_UPackage__Script_AirSim();
// End Cross Module References
	void UDS_VehicleMovementComponent::StaticRegisterNativesUDS_VehicleMovementComponent()
	{
	}
	UClass* Z_Construct_UClass_UDS_VehicleMovementComponent_NoRegister()
	{
		return UDS_VehicleMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDS_VehicleMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USimpleWheeledVehicleMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Physics" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "PlanarMovement Components|Movement|Planar Activation Components|Activation PlanarMovement Components|Movement|Planar Activation Components|Activation PlanarMovement Components|Movement|Planar Activation Components|Activation" },
		{ "IncludePath", "Vehicles/DifferentialVehicles/DS_VehicleMovementComponent.h" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/DS_VehicleMovementComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDS_VehicleMovementComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::ClassParams = {
		&UDS_VehicleMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDS_VehicleMovementComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDS_VehicleMovementComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDS_VehicleMovementComponent, 464741908);
	template<> AIRSIM_API UClass* StaticClass<UDS_VehicleMovementComponent>()
	{
		return UDS_VehicleMovementComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDS_VehicleMovementComponent(Z_Construct_UClass_UDS_VehicleMovementComponent, &UDS_VehicleMovementComponent::StaticClass, TEXT("/Script/AirSim"), TEXT("UDS_VehicleMovementComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDS_VehicleMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
