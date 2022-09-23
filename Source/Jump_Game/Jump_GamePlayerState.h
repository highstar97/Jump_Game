#pragma once

#include "GameFramework/PlayerState.h"
#include "Jump_GamePlayerState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerStateChangedDelegate);

UCLASS()
class JUMP_GAME_API AJump_GamePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AJump_GamePlayerState();

	void AddScore();

	int32 GetScore() { return Score; }
	
public:
	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

private:
	int32 Score;
};