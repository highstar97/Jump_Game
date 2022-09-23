#include "Floor.h"
#include "Components/BoxComponent.h"
#include "Math/UnrealMathUtility.h"

AFloor::AFloor()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerIsUsed = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("MESH"));
	Trigger = CreateDefaultSubobject<UBoxComponent> (TEXT("TRIGGER"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FLOOR(TEXT("/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400"));
	if (FLOOR.Succeeded())
	{
		Mesh->SetStaticMesh(FLOOR.Object);
	}

	RootComponent = Mesh;
	Trigger->SetupAttachment(Mesh);

	Trigger->SetRelativeLocation(FVector(200.0f, 200.0f, 0.0f));

	Mesh->SetRelativeScale3D(FVector(0.4f, 0.8f, 1.0f));
	Trigger->SetRelativeScale3D(FVector(6.3f, 4.0f, 0.6f));

	Trigger->SetCollisionProfileName(TEXT("FloorTrigger"));
}

void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFloor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFloor::OnCharacterOverlap);
}

// OncompenentBeginOverlap의 Parameter를 넘겨주기 위해서 필요
void AFloor::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!TriggerIsUsed)
	{
		SpawnFloor();
		TriggerIsUsed = true;
	}
}

void AFloor::SpawnFloor()
{
	//Floor 크기 162cm, 320cm, 18cm

	FVector NextLocation = Mesh->GetRelativeTransform().GetLocation();

	// Y : -320 - 350 ~ -320 || 320 ~ 320 + 350
	// Z : 70 ~ 140

	bool Positive = FMath::RandRange(1, 2) % 2 == 0;
	float RandomNumberForY = FMath::RandRange(320.0f, 670.0f);
	float RandomNumberForZ = FMath::RandRange(70.0f, 140.0f);

	if (Positive)
	{
		NextLocation.Y += RandomNumberForY;
	}
	else
	{
		NextLocation.Y -= RandomNumberForY;
	}

	NextLocation.Z += RandomNumberForZ;

	GetWorld()->SpawnActor<AFloor>(NextLocation, FRotator::ZeroRotator);
}