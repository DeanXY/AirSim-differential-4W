// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Vehicles/DifferentialVehicles/SimModeDifferentialCar.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimModeDifferentialCar() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_ASimModeDifferentialCar_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_ASimModeDifferentialCar();
	AIRSIM_API UClass* Z_Construct_UClass_ASimModeBase();
	UPackage* Z_Construct_UPackage__Script_AirSim();
// End Cross Module References
	void ASimModeDifferentialCar::StaticRegisterNativesASimModeDifferentialCar()
	{
	}
	UClass* Z_Construct_UClass_ASimModeDifferentialCar_NoRegister()
	{
		return ASimModeDifferentialCar::StaticClass();
	}
	struct Z_Construct_UClass_ASimModeDifferentialCar_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASimModeDifferentialCar_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASimModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimModeDifferentialCar_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Vehicles/DifferentialVehicles/SimModeDifferentialCar.h" },
		{ "ModuleRelativePath", "Vehicles/DifferentialVehicles/SimModeDifferentialCar.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASimModeDifferentialCar_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASimModeDifferentialCar>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASimModeDifferentialCar_Statics::ClassParams = {
		&ASimModeDifferentialCar::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASimModeDifferentialCar_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASimModeDifferentialCar_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASimModeDifferentialCar()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASimModeDifferentialCar_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASimModeDifferentialCar, 2695604146);
	template<> AIRSIM_API UClass* StaticClass<ASimModeDifferentialCar>()
	{
		return ASimModeDifferentialCar::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASimModeDifferentialCar(Z_Construct_UClass_ASimModeDifferentialCar, &ASimModeDifferentialCar::StaticClass, TEXT("/Script/AirSim"), TEXT("ASimModeDifferentialCar"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASimModeDifferentialCar);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
