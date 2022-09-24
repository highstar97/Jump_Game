#pragma once

#include "Blueprint/UserWidget.h"
#include "Jump_GameGameOverWidget.generated.h"

class AJump_GamePlayerState;
class UTextBlock;

UCLASS()
class JUMP_GAME_API UJump_GameGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindPlayerState(AJump_GamePlayerState* PlayerState);

protected:
	void UpdatePlayerState();

private:
	TWeakObjectPtr<AJump_GamePlayerState> CurrentPlayerState;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextScore;
};