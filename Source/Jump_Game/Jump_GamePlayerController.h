#pragma once

#include "GameFramework/PlayerController.h"
#include "Jump_GamePlayerController.generated.h"

class UJump_GameHUDWidget;
class UJump_GameGameOverWidget;
class UAudioComponent;
class USoundCue;

UCLASS()
class JUMP_GAME_API AJump_GamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AJump_GamePlayerController();

protected:
	virtual void BeginPlay() override;

public:
	void AddScore();

	void HideAddScoreWidget();
	void ShowEndUI();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UUserWidget> AddScoreWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UJump_GameHUDWidget> HUDWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UJump_GameGameOverWidget> GameOverWidgetClass;

private:
	float AddScoreWidgetHideTime;

	FTimerHandle HideAddScoreWidgetTimerHandle = { };

	UPROPERTY()
	UUserWidget* AddScoreWidget;

	UPROPERTY()
	UJump_GameHUDWidget* HUDWidget;

	UPROPERTY()
	UJump_GameGameOverWidget* GameOverWidget;

	UPROPERTY()
	UAudioComponent* AddScoreAudioComponent;

	UPROPERTY()
	USoundCue* AddScoreSound;
};