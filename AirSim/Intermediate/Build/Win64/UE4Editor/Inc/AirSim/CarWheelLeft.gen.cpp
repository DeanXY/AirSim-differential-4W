// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Vehicles/DifferentialVehicles/CarWheelLeft.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarWheelLeft() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_UCarWheelLeft_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_UCarWheelLeft();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_AirSim();
// End Cross Module References
	void UCarWheelLeft::StaticRegisterNativesUCarWheelLeft()
	{
	}
	UClass* Z_Construct_UClass_UCarWheelLeft_NoRegister()
	{
		return UCarWheelLeft::StaticClass();
	}
	struct Z_Construct_UClass_UCarWheelLeft_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarWheelLeft_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarWheelLeft_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Vehicles/DifferentialVehicles/CarWheelLeft.h" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/CarWheelLeft.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarWheelLeft_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarWheelLeft>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarWheelLeft_Statics::ClassParams = {
		&UCarWheelLeft::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCarWheelLeft_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarWheelLeft_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarWheelLeft()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarWheelLeft_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarWheelLeft, 756996155);
	template<> AIRSIM_API UClass* StaticClass<UCarWheelLeft>()
	{
		return UCarWheelLeft::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarWheelLeft(Z_Construct_UClass_UCarWheelLeft, &UCarWheelLeft::StaticClass, TEXT("/Script/AirSim"), TEXT("UCarWheelLeft"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarWheelLeft);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
