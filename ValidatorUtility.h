// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "ValidatorUtility.generated.h"

/**
 * 
 */
UCLASS()
class VALIDATOR_PROJECT_API UValidatorUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:

	// 2�̗ݏ���`�F�b�N����
	UFUNCTION(CallInEditor)
	void CheckPowerOfTwo();

private:
	bool IsPowerOfTwo(int32 NumberToCheck);

	/**
	* �X�N���[���ւ̃��b�Z�[�W�\��
	* @param Message - ���b�Z�[�W
	* @param Color - ���b�Z�[�W�Ɏg�p����F
	**/
	void PrintToScreen(FString Message, FColor Color);

	/**
	* ���[�U�[�ւ̃t�B�[�h�o�b�N
	* @param Method - �g�p���ꂽ���\�b�h
	* @param Counter - �ϊ����ꂽ�A�Z�b�g��
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
