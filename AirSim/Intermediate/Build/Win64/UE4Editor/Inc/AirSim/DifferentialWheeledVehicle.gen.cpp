// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Vehicles/DifferentialVehicles/DifferentialWheeledVehicle.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDifferentialWheeledVehicle() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_ADifferentialWheeledVehicle_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_ADifferentialWheeledVehicle();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_AirSim();
	AIRSIM_API UClass* Z_Construct_UClass_UDS_VehicleMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void ADifferentialWheeledVehicle::StaticRegisterNativesADifferentialWheeledVehicle()
	{
	}
	UClass* Z_Construct_UClass_ADifferentialWheeledVehicle_NoRegister()
	{
		return ADifferentialWheeledVehicle::StaticClass();
	}
	struct Z_Construct_UClass_ADifferentialWheeledVehicle_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VehicleMovement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VehicleMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Vehicles/DifferentialVehicles/DifferentialWheeledVehicle.h" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/DifferentialWheeledVehicle.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_VehicleMovement_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Vehicle" },
		{ "Comment", "/** vehicle simulation component */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/DifferentialWheeledVehicle.h" },
		{ "ToolTip", "vehicle simulation component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_VehicleMovement = { "VehicleMovement", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADifferentialWheeledVehicle, VehicleMovement), Z_Construct_UClass_UDS_VehicleMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_VehicleMovement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_VehicleMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Vehicle" },
		{ "Comment", "/**  The main skeletal mesh associated with this Vehicle */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/DifferentialWheeledVehicle.h" },
		{ "ToolTip", "The main skeletal mesh associated with this Vehicle" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADifferentialWheeledVehicle, Mesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_VehicleMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADifferentialWheeledVehicle>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::ClassParams = {
		&ADifferentialWheeledVehicle::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::PropPointers),
		0,
		0x009000A5u,
		METADATA_PARAMS(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADifferentialWheeledVehicle()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADifferentialWheeledVehicle_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADifferentialWheeledVehicle, 3525797433);
	template<> AIRSIM_API UClass* StaticClass<ADifferentialWheeledVehicle>()
	{
		return ADifferentialWheeledVehicle::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADifferentialWheeledVehicle(Z_Construct_UClass_ADifferentialWheeledVehicle, &ADifferentialWheeledVehicle::StaticClass, TEXT("/Script/AirSim"), TEXT("ADifferentialWheeledVehicle"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADifferentialWheeledVehicle);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
