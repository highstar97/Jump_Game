#include "Jump_GamePlayerController.h"
#include "Jump_GamePlayerState.h"

AJump_GamePlayerController::AJump_GamePlayerController()
{

}

void AJump_GamePlayerController::ShowEndUI()
{
	// 종료 화면 UI 띄우기
	UE_LOG(LogTemp, Warning, TEXT("Score is %d"), Cast<AJump_GamePlayerState>(PlayerState)->GetScore());
}