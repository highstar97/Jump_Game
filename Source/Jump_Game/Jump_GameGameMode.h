#pragma once

#include "GameFramework/GameModeBase.h"
#include "Jump_GameGameMode.generated.h"

UCLASS(minimalapi)
class AJump_GameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AJump_GameGameMode();

	void EndGame();
};