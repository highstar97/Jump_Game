#pragma once

#include "GameFramework/Actor.h"
#include "MainFloor.generated.h"

class UBoxComponent;

UCLASS()
class JUMP_GAME_API AMainFloor : public AActor
{
	GENERATED_BODY()

public:
	AMainFloor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

private:
	UFUNCTION()
		void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	float CurrentTime;
	float TargetTime;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Trigger")
	UBoxComponent* Trigger;
};