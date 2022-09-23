#include "MainFloor.h"
#include "Jump_GameGameMode.h"
#include "Components/BoxComponent.h"

AMainFloor::AMainFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	CurrentTime = 0.0f;
	TargetTime = 0.1f;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MAINFLOOR(TEXT("/Game/StarterContent/Architecture/MainFloor.MainFloor"));
	if (MAINFLOOR.Succeeded())
	{
		Mesh->SetStaticMesh(MAINFLOOR.Object);
	}

	RootComponent = Mesh;
	Trigger->SetupAttachment(Mesh);

	Mesh->SetRelativeLocation(FVector(-10000.0f, -5000.0f, 0.0f));
	Trigger->SetRelativeLocation(FVector(200.0f, 200.0f, -0.06f));

	Mesh->SetRelativeScale3D(FVector(50.0f, 25.0f, 500.0f));
	Trigger->SetRelativeScale3D(FVector(8.0f, 8.0f, 0.002f));

	Trigger->SetCollisionProfileName(TEXT("FloorTrigger"));
}

void AMainFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime;
	if (CurrentTime >= TargetTime)
	{
		CurrentTime -= TargetTime;
		this->SetActorLocation(this->GetActorLocation() + FVector(0.0f, 0.0f, 1.0f));
	}
}

void AMainFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainFloor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMainFloor::OnCharacterOverlap);
}

void AMainFloor::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 게임 종료
	UE_LOG(LogTemp, Warning, TEXT("Game End"));
	Cast<AJump_GameGameMode>(GetWorld()->GetAuthGameMode())->EndGame();
}