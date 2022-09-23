#include "Jump_GamePlayerController.h"
#include "Jump_GamePlayerState.h"
#include "Jump_GameHUDWidget.h"

AJump_GamePlayerController::AJump_GamePlayerController()
{
	static ConstructorHelpers::FClassFinder<UJump_GameHUDWidget> UI_HUD_C(TEXT("/Game/Blueprint/Jump_GameHUDWidget.Jump_GameHUDWidget_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

void AJump_GamePlayerController::BeginPlay()
{
	HUDWidget = CreateWidget<UJump_GameHUDWidget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();

	AJump_GamePlayerState* Jump_GamePlayerState = Cast<AJump_GamePlayerState>(PlayerState);
	if (nullptr != Jump_GamePlayerState)
	{
		HUDWidget->BindPlayerState(Jump_GamePlayerState);
		Jump_GamePlayerState->OnPlayerStateChanged.Broadcast();
	}
}

void AJump_GamePlayerController::ShowEndUI()
{
	// 종료 화면 UI 띄우기
	UE_LOG(LogTemp, Warning, TEXT("Score is %d"), Cast<AJump_GamePlayerState>(PlayerState)->GetScore());
}