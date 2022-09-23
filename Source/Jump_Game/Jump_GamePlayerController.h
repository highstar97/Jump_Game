#pragma once

#include "GameFramework/PlayerController.h"
#include "Jump_GamePlayerController.generated.h"

class UJump_GameHUDWidget;

UCLASS()
class JUMP_GAME_API AJump_GamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AJump_GamePlayerController();

protected:
	virtual void BeginPlay() override;

public:
	void ShowEndUI();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UJump_GameHUDWidget> HUDWidgetClass;

private:
	UPROPERTY()
	UJump_GameHUDWidget* HUDWidget;
};