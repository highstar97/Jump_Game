#include "Jump_GamePlayerController.h"
#include "Jump_GameCharacter.h"
#include "Jump_GamePlayerState.h"
#include "Jump_GameHUDWidget.h"
#include "Components/WidgetComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"

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

	AddScoreAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("ADDSCOREAUDIOCOMPONENT"));

	static ConstructorHelpers::FObjectFinder<USoundCue> SOUND_ADDSCORE(TEXT("/Game/StarterContent/Audio/Starter_Music_Cue.Starter_Music_Cue"));
	if (SOUND_ADDSCORE.Succeeded())
	{
		AddScoreSound = SOUND_ADDSCORE.Object;
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
	AddScoreAudioComponent->SetSound(AddScoreSound);
	AddScoreAudioComponent->Play();
	GetWorld()->GetTimerManager().SetTimer(HideAddScoreWidgetTimerHandle, FTimerDelegate::CreateUObject(this, &AJump_GamePlayerController::HideAddScoreWidget), AddScoreWidgetHideTime, false);
	Cast<AJump_GamePlayerState>(PlayerState)->AddScore();
}

void AJump_GamePlayerController::HideAddScoreWidget()
{
	AddScoreWidget->RemoveFromParent();
	AddScoreAudioComponent->Stop();
}

void AJump_GamePlayerController::ShowEndUI()
{
	// 종료 화면 UI 띄우기
	UE_LOG(LogTemp, Warning, TEXT("Score is %d"), Cast<AJump_GamePlayerState>(PlayerState)->GetScore());
}