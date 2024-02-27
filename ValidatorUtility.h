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

	// 2の累乗をチェックする
	UFUNCTION(CallInEditor)
	void CheckPowerOfTwo();

private:
	bool IsPowerOfTwo(int32 NumberToCheck);

	/**
	* スクリーンへのメッセージ表示
	* @param Message - メッセージ
	* @param Color - メッセージに使用する色
	**/
	void PrintToScreen(FString Message, FColor Color);

	/**
	* ユーザーへのフィードバック
	* @param Method - 使用されたメソッド
	* @param Counter - 変換されたアセット数
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
