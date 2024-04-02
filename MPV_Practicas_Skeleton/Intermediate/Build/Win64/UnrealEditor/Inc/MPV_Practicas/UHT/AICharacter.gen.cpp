// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MPV_Practicas/AICharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAICharacter() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	MPV_PRACTICAS_API UClass* Z_Construct_UClass_AAICharacter();
	MPV_PRACTICAS_API UClass* Z_Construct_UClass_AAICharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MPV_Practicas();
// End Cross Module References
	DEFINE_FUNCTION(AAICharacter::execOnClickedRight)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_mousePosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnClickedRight(Z_Param_Out_mousePosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AAICharacter::execOnClickedLeft)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_mousePosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnClickedLeft(Z_Param_Out_mousePosition);
		P_NATIVE_END;
	}
	void AAICharacter::StaticRegisterNativesAAICharacter()
	{
		UClass* Class = AAICharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnClickedLeft", &AAICharacter::execOnClickedLeft },
			{ "OnClickedRight", &AAICharacter::execOnClickedRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics
	{
		struct AICharacter_eventOnClickedLeft_Parms
		{
			FVector mousePosition;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mousePosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_mousePosition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::NewProp_mousePosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::NewProp_mousePosition = { "mousePosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AICharacter_eventOnClickedLeft_Parms, mousePosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::NewProp_mousePosition_MetaData), Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::NewProp_mousePosition_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::NewProp_mousePosition,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::Function_MetaDataParams[] = {
		{ "Category", "AIFunctions" },
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAICharacter, nullptr, "OnClickedLeft", nullptr, nullptr, Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::AICharacter_eventOnClickedLeft_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::AICharacter_eventOnClickedLeft_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AAICharacter_OnClickedLeft()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAICharacter_OnClickedLeft_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics
	{
		struct AICharacter_eventOnClickedRight_Parms
		{
			FVector mousePosition;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mousePosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_mousePosition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::NewProp_mousePosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::NewProp_mousePosition = { "mousePosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AICharacter_eventOnClickedRight_Parms, mousePosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::NewProp_mousePosition_MetaData), Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::NewProp_mousePosition_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::NewProp_mousePosition,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::Function_MetaDataParams[] = {
		{ "Category", "AIFunctions" },
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAICharacter, nullptr, "OnClickedRight", nullptr, nullptr, Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::AICharacter_eventOnClickedRight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::AICharacter_eventOnClickedRight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AAICharacter_OnClickedRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAICharacter_OnClickedRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAICharacter);
	UClass* Z_Construct_UClass_AAICharacter_NoRegister()
	{
		return AAICharacter::StaticClass();
	}
	struct Z_Construct_UClass_AAICharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDoMovement_MetaData[];
#endif
		static void NewProp_bDoMovement_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDoMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_current_angle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_current_angle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PathMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAICharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_MPV_Practicas,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AAICharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAICharacter_OnClickedLeft, "OnClickedLeft" }, // 3670819960
		{ &Z_Construct_UFunction_AAICharacter_OnClickedRight, "OnClickedRight" }, // 4154429338
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAICharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AICharacter.h" },
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement_MetaData[] = {
		{ "Category", "AIChar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**  */" },
#endif
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
	void Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement_SetBit(void* Obj)
	{
		((AAICharacter*)Obj)->bDoMovement = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement = { "bDoMovement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(AAICharacter), &Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement_MetaData), Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAICharacter_Statics::NewProp_current_angle_MetaData[] = {
		{ "Category", "AIChar" },
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAICharacter_Statics::NewProp_current_angle = { "current_angle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAICharacter, current_angle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::NewProp_current_angle_MetaData), Z_Construct_UClass_AAICharacter_Statics::NewProp_current_angle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAICharacter_Statics::NewProp_PathMaterial_MetaData[] = {
		{ "Category", "AICharacter" },
		{ "ModuleRelativePath", "AICharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAICharacter_Statics::NewProp_PathMaterial = { "PathMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAICharacter, PathMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::NewProp_PathMaterial_MetaData), Z_Construct_UClass_AAICharacter_Statics::NewProp_PathMaterial_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAICharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAICharacter_Statics::NewProp_bDoMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAICharacter_Statics::NewProp_current_angle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAICharacter_Statics::NewProp_PathMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAICharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAICharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAICharacter_Statics::ClassParams = {
		&AAICharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAICharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AAICharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AAICharacter()
	{
		if (!Z_Registration_Info_UClass_AAICharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAICharacter.OuterSingleton, Z_Construct_UClass_AAICharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAICharacter.OuterSingleton;
	}
	template<> MPV_PRACTICAS_API UClass* StaticClass<AAICharacter>()
	{
		return AAICharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAICharacter);
	AAICharacter::~AAICharacter() {}
	struct Z_CompiledInDeferFile_FID_Users_gonzalo_valenti_Documents_MisCosas_IA_Utad_MPV_Practicas_Skeleton_Source_MPV_Practicas_AICharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gonzalo_valenti_Documents_MisCosas_IA_Utad_MPV_Practicas_Skeleton_Source_MPV_Practicas_AICharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAICharacter, AAICharacter::StaticClass, TEXT("AAICharacter"), &Z_Registration_Info_UClass_AAICharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAICharacter), 505971915U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gonzalo_valenti_Documents_MisCosas_IA_Utad_MPV_Practicas_Skeleton_Source_MPV_Practicas_AICharacter_h_77073351(TEXT("/Script/MPV_Practicas"),
		Z_CompiledInDeferFile_FID_Users_gonzalo_valenti_Documents_MisCosas_IA_Utad_MPV_Practicas_Skeleton_Source_MPV_Practicas_AICharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gonzalo_valenti_Documents_MisCosas_IA_Utad_MPV_Practicas_Skeleton_Source_MPV_Practicas_AICharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
