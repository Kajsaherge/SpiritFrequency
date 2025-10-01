// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpiritFrequencyGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSpiritFrequencyGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyGameMode();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpiritFrequency();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASpiritFrequencyGameMode *************************************************
void ASpiritFrequencyGameMode::StaticRegisterNativesASpiritFrequencyGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ASpiritFrequencyGameMode;
UClass* ASpiritFrequencyGameMode::GetPrivateStaticClass()
{
	using TClass = ASpiritFrequencyGameMode;
	if (!Z_Registration_Info_UClass_ASpiritFrequencyGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("SpiritFrequencyGameMode"),
			Z_Registration_Info_UClass_ASpiritFrequencyGameMode.InnerSingleton,
			StaticRegisterNativesASpiritFrequencyGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASpiritFrequencyGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ASpiritFrequencyGameMode_NoRegister()
{
	return ASpiritFrequencyGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASpiritFrequencyGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SpiritFrequencyGameMode.h" },
		{ "ModuleRelativePath", "SpiritFrequencyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpiritFrequencyGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SpiritFrequency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::ClassParams = {
	&ASpiritFrequencyGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpiritFrequencyGameMode()
{
	if (!Z_Registration_Info_UClass_ASpiritFrequencyGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpiritFrequencyGameMode.OuterSingleton, Z_Construct_UClass_ASpiritFrequencyGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpiritFrequencyGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpiritFrequencyGameMode);
ASpiritFrequencyGameMode::~ASpiritFrequencyGameMode() {}
// ********** End Class ASpiritFrequencyGameMode ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_kalj5019_Documents_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyGameMode_h__Script_SpiritFrequency_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpiritFrequencyGameMode, ASpiritFrequencyGameMode::StaticClass, TEXT("ASpiritFrequencyGameMode"), &Z_Registration_Info_UClass_ASpiritFrequencyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpiritFrequencyGameMode), 590461102U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kalj5019_Documents_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyGameMode_h__Script_SpiritFrequency_3023748971(TEXT("/Script/SpiritFrequency"),
	Z_CompiledInDeferFile_FID_Users_kalj5019_Documents_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyGameMode_h__Script_SpiritFrequency_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kalj5019_Documents_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyGameMode_h__Script_SpiritFrequency_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
