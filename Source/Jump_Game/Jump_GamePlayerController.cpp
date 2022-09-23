#include "Jump_GamePlayerController.h"
#include "Jump_GameCharacter.h"
#include "Jump_GamePlayerState.h"
#include "Components/WidgetComponent.h"
#include "Jump_GameHUDWidget.h"

AJump_GamePlayerController::AJump_GamePlayerController()
{
	AddScoreWidgetHideTime = 0.5f;

	static ConstructorHelpers::FClassFinder<UJump_GameHUDWidget> UI_HUD_C(TEXT("/Game/Blueprint/Jump_GameHUDWidget.Jump_GameHUDWidget_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> UI_ADDSCORE_C(TEXT("/Game/Blueprint/AddScoreWidget.AddScoreWidget_C"));
	if (UI_ADDSCORE_C.Succeeded())
	{
		AddScoreWidgetClass = UI_ADDSCORE_C.Class;
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

void AJump_GamePlayerController::AddScore()
{
	AddScoreWidget = CreateWidget<UUserWidget>(this, AddScoreWidgetClass);
	AddScoreWidget->AddToViewport();
	GetWorld()->GetTimerManager().SetTimer(HideAddScoreWidgetTimerHandle, FTimerDelegate::CreateUObject(this, &AJump_GamePlayerController::HideAddScoreWidget), AddScoreWidgetHideTime, false);
	Cast<AJump_GamePlayerState>(PlayerState)->AddScore();
}

void AJump_GamePlayerController::HideAddScoreWidget()
{
	AddScoreWidget->RemoveFromParent();
}

void AJump_GamePlayerController::ShowEndUI()
{
	// 종료 화면 UI 띄우기
	UE_LOG(LogTemp, Warning, TEXT("Score is %d"), Cast<AJump_GamePlayerState>(PlayerState)->GetScore());
}