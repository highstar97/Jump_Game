#include "Jump_GameGameOverWidget.h"
#include "Jump_GamePlayerState.h"
#include "Components/TextBlock.h"

void UJump_GameGameOverWidget::BindPlayerState(AJump_GamePlayerState* PlayerState)
{
	if (nullptr != PlayerState)
	{
		CurrentPlayerState = PlayerState;
		PlayerState->OnPlayerStateChanged.AddUObject(this, &UJump_GameGameOverWidget::UpdatePlayerState);
	}
}

void UJump_GameGameOverWidget::UpdatePlayerState()
{
	TextScore->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetScore())));
}