#include "Jump_GamePlayerState.h"

AJump_GamePlayerState::AJump_GamePlayerState()
{
	Score = 0;
}

void AJump_GamePlayerState::AddScore()
{
	Score += 100;
	OnPlayerStateChanged.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Score : %d"), Score);
}