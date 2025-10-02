// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpiritFrequencyCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSpiritFrequencyCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCameraManager();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpiritFrequency();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASpiritFrequencyCameraManager ********************************************
void ASpiritFrequencyCameraManager::StaticRegisterNativesASpiritFrequencyCameraManager()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ASpiritFrequencyCameraManager;
UClass* ASpiritFrequencyCameraManager::GetPrivateStaticClass()
{
	using TClass = ASpiritFrequencyCameraManager;
	if (!Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("SpiritFrequencyCameraManager"),
			Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.InnerSingleton,
			StaticRegisterNativesASpiritFrequencyCameraManager,
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
	return Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_ASpiritFrequencyCameraManager_NoRegister()
{
	return ASpiritFrequencyCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "SpiritFrequencyCameraManager.h" },
		{ "ModuleRelativePath", "SpiritFrequencyCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpiritFrequencyCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_SpiritFrequency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::ClassParams = {
	&ASpiritFrequencyCameraManager::StaticClass,
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
	0x008003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpiritFrequencyCameraManager()
{
	if (!Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.OuterSingleton, Z_Construct_UClass_ASpiritFrequencyCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpiritFrequencyCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpiritFrequencyCameraManager);
ASpiritFrequencyCameraManager::~ASpiritFrequencyCameraManager() {}
// ********** End Class ASpiritFrequencyCameraManager **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCameraManager_h__Script_SpiritFrequency_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpiritFrequencyCameraManager, ASpiritFrequencyCameraManager::StaticClass, TEXT("ASpiritFrequencyCameraManager"), &Z_Registration_Info_UClass_ASpiritFrequencyCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpiritFrequencyCameraManager), 4032746876U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCameraManager_h__Script_SpiritFrequency_2933807078(TEXT("/Script/SpiritFrequency"),
	Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCameraManager_h__Script_SpiritFrequency_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCameraManager_h__Script_SpiritFrequency_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
