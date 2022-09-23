#include "Jump_GameGameMode.h"
#include "Jump_GameCharacter.h"
#include "Jump_GamePlayerController.h"
#include "Jump_GamePlayerState.h"
#include "UObject/ConstructorHelpers.h"

AJump_GameGameMode::AJump_GameGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AJump_GamePlayerController::StaticClass();
	PlayerStateClass = AJump_GamePlayerState::StaticClass();
}

void AJump_GameGameMode::EndGame()
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		const auto Jump_GamePlayerController = Cast<AJump_GamePlayerController>(It->Get());
		if (nullptr != Jump_GamePlayerController)
		{
			Jump_GamePlayerController->ShowEndUI();
		}
	}
}
