// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpiritFrequencyCharacter.h"

#ifdef SPIRITFREQUENCY_SpiritFrequencyCharacter_generated_h
#error "SpiritFrequencyCharacter.generated.h already included, missing '#pragma once' in SpiritFrequencyCharacter.h"
#endif
#define SPIRITFREQUENCY_SpiritFrequencyCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ASpiritFrequencyCharacter ************************************************
#define FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCharacter_NoRegister();

#define FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpiritFrequencyCharacter(); \
	friend struct Z_Construct_UClass_ASpiritFrequencyCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SPIRITFREQUENCY_API UClass* Z_Construct_UClass_ASpiritFrequencyCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ASpiritFrequencyCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpiritFrequency"), Z_Construct_UClass_ASpiritFrequencyCharacter_NoRegister) \
	DECLARE_SERIALIZER(ASpiritFrequencyCharacter)


#define FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASpiritFrequencyCharacter(ASpiritFrequencyCharacter&&) = delete; \
	ASpiritFrequencyCharacter(const ASpiritFrequencyCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpiritFrequencyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpiritFrequencyCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ASpiritFrequencyCharacter) \
	NO_API virtual ~ASpiritFrequencyCharacter();


#define FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_21_PROLOG
#define FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASpiritFrequencyCharacter;

// ********** End Class ASpiritFrequencyCharacter **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_SpiritFrequency_Source_SpiritFrequency_SpiritFrequencyCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
