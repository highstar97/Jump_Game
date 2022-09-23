#include "Jump_GameHUDWidget.h"
#include "Jump_GamePlayerState.h"
#include "Components/TextBlock.h"

void UJump_GameHUDWidget::BindPlayerState(AJump_GamePlayerState* PlayerState)
{
	if (nullptr != PlayerState)
	{
		CurrentPlayerState = PlayerState;
		PlayerState->OnPlayerStateChanged.AddUObject(this, &UJump_GameHUDWidget::UpdatePlayerState);
	}
}

void UJump_GameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UJump_GameHUDWidget::UpdatePlayerState()
{
	Score->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetScore())));
}