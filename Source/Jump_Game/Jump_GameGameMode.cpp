#include "Jump_GameGameMode.h"
#include "Jump_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJump_GameGameMode::AJump_GameGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
