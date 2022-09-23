#pragma once

#include "GameFramework/PlayerController.h"
#include "Jump_GamePlayerController.generated.h"

UCLASS()
class JUMP_GAME_API AJump_GamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AJump_GamePlayerController();

public:
	void ShowEndUI();
};