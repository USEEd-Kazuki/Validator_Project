// Fill out your copyright notice in the Description page of Project Settings.


#include "ValidatorUtility.h"
#include "EditorUtilityLibrary.h"

#pragma region CheckPowerOfTwo
void UValidatorUtility::CheckPowerOfTwo()
{
	// �I�����ꂽ�S�ẴA�Z�b�g���擾����
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

	uint32 Counter = 0;

	for (UObject* SelectedObject : SelectedObjects) 
	{
		if (ensure(SelectedObject))
		{
			UTexture* Texture = dynamic_cast<UTexture*>(SelectedObject);
			if (ensure(Texture))
			{
				// �e�N�X�`���̕��ƍ������擾����
				int32 Width = static_cast<int32>(Texture->GetSurfaceWidth());
				int32 Height = static_cast<int32>(Texture->GetSurfaceWidth());
				
				// ���܂��͍�����2�̗ݏ�łȂ��ꍇ�͌x�����o�͂���
				if (!IsPowerOfTwo(Width) || !IsPowerOfTwo(Height)) {
					PrintToScreen(SelectedObject->GetPathName() + " is not a power of 2 texture", FColor::Red);
				}
				else
				{
					++Counter;
				}
			}
			else
			{
				PrintToScreen(SelectedObject->GetName() + " is not a texture", FColor::Red);
			}
		}
	}

	GiveFeedback("Power of two", Counter);
}


// ���l��2�̗ݏ�ł��邩�𔻒�
bool UValidatorUtility::IsPowerOfTwo(int32 NumberToCheck)
{
	if (NumberToCheck == 0) 
	{
		return false;
	}
	return (NumberToCheck & (NumberToCheck -1)) == 0;
}

void UValidatorUtility::PrintToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

void UValidatorUtility::GiveFeedback(FString Method, uint32 Counter)
{
	FString Message = FString("No matching files found");
	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0)
	{
		Message = Method.AppendChar(' ');
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
	}
	PrintToScreen(Message, Color);
}

#pragma endregion
