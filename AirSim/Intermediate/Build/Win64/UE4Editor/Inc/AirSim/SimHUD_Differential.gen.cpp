// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/SimHUD/SimHUD_Differential.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimHUD_Differential() {}
// Cross Module References
	AIRSIM_API UClass* Z_Construct_UClass_ASimHUD_Differential_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_ASimHUD_Differential();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_AirSim();
	AIRSIM_API UClass* Z_Construct_UClass_ASimModeBase_NoRegister();
	AIRSIM_API UClass* Z_Construct_UClass_USimHUDWidget_NoRegister();
// End Cross Module References
	void ASimHUD_Differential::StaticRegisterNativesASimHUD_Differential()
	{
	}
	UClass* Z_Construct_UClass_ASimHUD_Differential_NoRegister()
	{
		return ASimHUD_Differential::StaticClass();
	}
	struct Z_Construct_UClass_ASimHUD_Differential_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_simmode__MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_simmode_;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_widget__MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_widget_;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASimHUD_Differential_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_AirSim,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimHUD_Differential_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n *///UENUM(BlueprintType)\n//enum class ESimulatorMode : uint8\n//{\n//\x09SIM_MODE_HIL UMETA(DisplayName = \"Hardware-in-loop\")\n//};\n" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "SimHUD/SimHUD_Differential.h" },
		{ "ModuleRelativePath", "SimHUD/SimHUD_Differential.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "//UENUM(BlueprintType)\n//enum class ESimulatorMode : uint8\n//{\n//     SIM_MODE_HIL UMETA(DisplayName = \"Hardware-in-loop\")\n//};" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_simmode__MetaData[] = {
		{ "ModuleRelativePath", "SimHUD/SimHUD_Differential.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_simmode_ = { "simmode_", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASimHUD_Differential, simmode_), Z_Construct_UClass_ASimModeBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_simmode__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_simmode__MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_widget__MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SimHUD/SimHUD_Differential.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_widget_ = { "widget_", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASimHUD_Differential, widget_), Z_Construct_UClass_USimHUDWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_widget__MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_widget__MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASimHUD_Differential_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_simmode_,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimHUD_Differential_Statics::NewProp_widget_,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASimHUD_Differential_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASimHUD_Differential>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASimHUD_Differential_Statics::ClassParams = {
		&ASimHUD_Differential::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASimHUD_Differential_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASimHUD_Differential_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASimHUD_Differential_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASimHUD_Differential_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASimHUD_Differential()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASimHUD_Differential_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASimHUD_Differential, 2663942458);
	template<> AIRSIM_API UClass* StaticClass<ASimHUD_Differential>()
	{
		return ASimHUD_Differential::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASimHUD_Differential(Z_Construct_UClass_ASimHUD_Differential, &ASimHUD_Differential::StaticClass, TEXT("/Script/AirSim"), TEXT("ASimHUD_Differential"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASimHUD_Differential);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
