// Fill out your copyright notice in the Description page of Project Settings.


#include "AirsimGameMode_Differential.h"
#include "Misc/FileHelper.h"
#include "IImageWrapperModule.h"
#include "SimHUD/SimHUD_Differential.h"
#include "common/Common.hpp"
#include "AirBlueprintLib.h"

//class AUnrealLog : public msr::airlib::Utils::Logger
//{
//public:
//    virtual void log(int level, const std::string& message) override
//    {
//        size_t tab_pos;
//        static const std::string delim = ":\t";
//        if ((tab_pos = message.find(delim)) != std::string::npos) {
//            UAirBlueprintLib::LogMessageString(message.substr(0, tab_pos),
//                message.substr(tab_pos + delim.size(), std::string::npos),
//                LogDebugLevel::Informational);
//
//            return; //display only
//        }
//
//        if (level == msr::airlib::Utils::kLogLevelError) {
//            UE_LOG(LogTemp, Error, TEXT("%s"), *FString(message.c_str()));
//        }
//        else if (level == msr::airlib::Utils::kLogLevelWarn) {
//            UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(message.c_str()));
//        }
//        else {
//            UE_LOG(LogTemp, Log, TEXT("%s"), *FString(message.c_str()));
//        }
//
//        //#ifdef _MSC_VER
//        //        //print to VS output window
//        //        OutputDebugString(std::wstring(message.begin(), message.end()).c_str());
//        //#endif
//
//        //also do default logging
//        msr::airlib::Utils::Logger::log(level, message);
//    }
//};

//static AUnrealLog GlobalASimLog;

AAirsimGameMode_Differential::AAirsimGameMode_Differential(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    DefaultPawnClass = nullptr;
    HUDClass = ASimHUD_Differential::StaticClass();

    //common_utils::Utils::getSetLogger(&GlobalASimLog);

    //module loading is not allowed outside of the main thread, so we load the ImageWrapper module ahead of time.
    static IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
}

//UGameUserSettings* AAirSimGameMode::GetGameUserSettings()
//{
//    if (GEngine != nullptr)
//    {
//        return GEngine->GameUserSettings;
//    }
//    return nullptr;
//}

void AAirsimGameMode_Differential::StartPlay()
{
    Super::StartPlay();

    //UGameUserSettings* game_settings = GetGameUserSettings();
    //game_settings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
    //game_settings->ApplySettings(true);
}
