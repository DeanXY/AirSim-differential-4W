// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Vehicles/DifferentialVehicles/CarWheelRight.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarWheelRight() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_UCarWheelRight_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_UCarWheelRight();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_AirSim();
// End Cross Module References
	void UCarWheelRight::StaticRegisterNativesUCarWheelRight()
	{
	}
	UClass* Z_Construct_UClass_UCarWheelRight_NoRegister()
	{
		return UCarWheelRight::StaticClass();
	}
	struct Z_Construct_UClass_UCarWheelRight_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarWheelRight_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarWheelRight_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Vehicles/DifferentialVehicles/CarWheelRight.h" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/CarWheelRight.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarWheelRight_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarWheelRight>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarWheelRight_Statics::ClassParams = {
		&UCarWheelRight::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCarWheelRight_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarWheelRight_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarWheelRight()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarWheelRight_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarWheelRight, 1191413146);
	template<> AIRSIM_API UClass* StaticClass<UCarWheelRight>()
	{
		return UCarWheelRight::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarWheelRight(Z_Construct_UClass_UCarWheelRight, &UCarWheelRight::StaticClass, TEXT("/Script/AirSim"), TEXT("UCarWheelRight"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarWheelRight);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
