// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpiritFrequencyCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSpiritFrequencyCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCharacter();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCharacter_NoRegister();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_UEMFComponent_NoRegister();
SPIRITFREQUENCY_API UClass* Z_Construct_UClass_UNavigationComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpiritFrequency();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASpiritFrequencyCharacter Function DoAim *********************************
struct Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics
{
	struct SpiritFrequencyCharacter_eventDoAim_Parms
	{
		float Yaw;
		float Pitch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles aim inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles aim inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pitch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::NewProp_Yaw = { "Yaw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpiritFrequencyCharacter_eventDoAim_Parms, Yaw), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::NewProp_Pitch = { "Pitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpiritFrequencyCharacter_eventDoAim_Parms, Pitch), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::NewProp_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::NewProp_Pitch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASpiritFrequencyCharacter, nullptr, "DoAim", Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::SpiritFrequencyCharacter_eventDoAim_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::SpiritFrequencyCharacter_eventDoAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpiritFrequencyCharacter::execDoAim)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Yaw);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Pitch);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoAim(Z_Param_Yaw,Z_Param_Pitch);
	P_NATIVE_END;
}
// ********** End Class ASpiritFrequencyCharacter Function DoAim ***********************************

// ********** Begin Class ASpiritFrequencyCharacter Function DoMove ********************************
struct Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics
{
	struct SpiritFrequencyCharacter_eventDoMove_Parms
	{
		float Right;
		float Forward;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles move inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles move inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Right;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Forward;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpiritFrequencyCharacter_eventDoMove_Parms, Right), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::NewProp_Forward = { "Forward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SpiritFrequencyCharacter_eventDoMove_Parms, Forward), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::NewProp_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::NewProp_Forward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASpiritFrequencyCharacter, nullptr, "DoMove", Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::SpiritFrequencyCharacter_eventDoMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::SpiritFrequencyCharacter_eventDoMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpiritFrequencyCharacter::execDoMove)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Right);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Forward);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoMove(Z_Param_Right,Z_Param_Forward);
	P_NATIVE_END;
}
// ********** End Class ASpiritFrequencyCharacter Function DoMove **********************************

// ********** Begin Class ASpiritFrequencyCharacter Function ToggleEMF *****************************
struct Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASpiritFrequencyCharacter, nullptr, "ToggleEMF", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASpiritFrequencyCharacter::execToggleEMF)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleEMF();
	P_NATIVE_END;
}
// ********** End Class ASpiritFrequencyCharacter Function ToggleEMF *******************************

// ********** Begin Class ASpiritFrequencyCharacter ************************************************
void ASpiritFrequencyCharacter::StaticRegisterNativesASpiritFrequencyCharacter()
{
	UClass* Class = ASpiritFrequencyCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DoAim", &ASpiritFrequencyCharacter::execDoAim },
		{ "DoMove", &ASpiritFrequencyCharacter::execDoMove },
		{ "ToggleEMF", &ASpiritFrequencyCharacter::execToggleEMF },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ASpiritFrequencyCharacter;
UClass* ASpiritFrequencyCharacter::GetPrivateStaticClass()
{
	using TClass = ASpiritFrequencyCharacter;
	if (!Z_Registration_Info_UClass_ASpiritFrequencyCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("SpiritFrequencyCharacter"),
			Z_Registration_Info_UClass_ASpiritFrequencyCharacter.InnerSingleton,
			StaticRegisterNativesASpiritFrequencyCharacter,
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
	return Z_Registration_Info_UClass_ASpiritFrequencyCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_ASpiritFrequencyCharacter_NoRegister()
{
	return ASpiritFrequencyCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASpiritFrequencyCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A basic first person character\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SpiritFrequencyCharacter.h" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A basic first person character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstPersonMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pawn mesh: first person view (arms; seen only by self) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pawn mesh: first person view (arms; seen only by self)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstPersonCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** First person camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "First person camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseLookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse Look Input Action */" },
#endif
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EMFToggleAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NavigationComponent_MetaData[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//** KOMPONENTER\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/ KOMPONENTER" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EMFComponent_MetaData[] = {
		{ "Category", "EMF" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// SpiritFrequencyCharacter.h\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpiritFrequencyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SpiritFrequencyCharacter.h" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstPersonMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstPersonCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseLookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EMFToggleAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NavigationComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EMFComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpiritFrequencyCharacter_DoAim, "DoAim" }, // 41579004
		{ &Z_Construct_UFunction_ASpiritFrequencyCharacter_DoMove, "DoMove" }, // 1849427295
		{ &Z_Construct_UFunction_ASpiritFrequencyCharacter_ToggleEMF, "ToggleEMF" }, // 3180715485
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpiritFrequencyCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_FirstPersonMesh = { "FirstPersonMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, FirstPersonMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstPersonMesh_MetaData), NewProp_FirstPersonMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_FirstPersonCameraComponent = { "FirstPersonCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, FirstPersonCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstPersonCameraComponent_MetaData), NewProp_FirstPersonCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_MouseLookAction = { "MouseLookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, MouseLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseLookAction_MetaData), NewProp_MouseLookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_EMFToggleAction = { "EMFToggleAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, EMFToggleAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EMFToggleAction_MetaData), NewProp_EMFToggleAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_NavigationComponent = { "NavigationComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, NavigationComponent), Z_Construct_UClass_UNavigationComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NavigationComponent_MetaData), NewProp_NavigationComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_EMFComponent = { "EMFComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpiritFrequencyCharacter, EMFComponent), Z_Construct_UClass_UEMFComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EMFComponent_MetaData), NewProp_EMFComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_FirstPersonMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_FirstPersonCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_MouseLookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_EMFToggleAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_NavigationComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::NewProp_EMFComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SpiritFrequency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::ClassParams = {
	&ASpiritFrequencyCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::PropPointers),
	0,
	0x008001A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpiritFrequencyCharacter()
{
	if (!Z_Registration_Info_UClass_ASpiritFrequencyCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpiritFrequencyCharacter.OuterSingleton, Z_Construct_UClass_ASpiritFrequencyCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpiritFrequencyCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpiritFrequencyCharacter);
ASpiritFrequencyCharacter::~ASpiritFrequencyCharacter() {}
// ********** End Class ASpiritFrequencyCharacter **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h__Script_SpiritFrequency_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpiritFrequencyCharacter, ASpiritFrequencyCharacter::StaticClass, TEXT("ASpiritFrequencyCharacter"), &Z_Registration_Info_UClass_ASpiritFrequencyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpiritFrequencyCharacter), 666539085U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h__Script_SpiritFrequency_3894745099(TEXT("/Script/SpiritFrequency"),
	Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h__Script_SpiritFrequency_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h__Script_SpiritFrequency_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
