// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActorCpp.h"

#include "Engine/World.h"

// Sets default values
ASpawnActorCpp::ASpawnActorCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActorCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnActorCpp::RandTCpp(int x, int y, int Step, float Z_Len)
{
	FRandomStream RandomStream(FMath::Rand());
	int Step_X = Step - 1;
	int Step_Y = Step_X;
	int index = -1;
	TArray<float> Map_Local;
	Map_Local.SetNum(x*y);
	for (int i = 0; i < y; i++)
	{
		Step_Y++;
		if (Step_Y > Step)
		{
			Step_Y = 1;
		}
		for(int j = 0; j < x; j++)
		{
			index++;
			Step_X++;
			if (Step_X > Step)
			{
				Step_X = 1;
			}
			if ((Step_X == Step) && (Step_Y == Step))
			{
				Map_Local[index] = RandomStream.FRandRange(Z_Len * -1, Z_Len);
			}
			else
			{
				if (Step_Y != Step)
				{
					Map_Local[index] = (Map_Local[j+i*(y+1)-(y+1)]);
				}
				else
				{
					Map_Local[index] = (Map_Local[j+i*(y+1)-1]);
				}
			}
		}
		Step_X = 0;
	}

	if (Map_Local.Num() > Map_T.Num())
	{
		Map_T.SetNum(Map_Local.Num());
	}
	for (int i = 0; i < Map_Local.Num(); i++)
	{
		if ((Map_Local.IsValidIndex(i)) && (Map_T.IsValidIndex(i)))
		{
			Map_T[i] = Map_T[i] + Map_Local[i];
		}
	}
}

void ASpawnActorCpp::SmothTCpp(int x, int y)
{
	float Mid = 0;
	for (int i = 2; i < y-2; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Mid = (Map_T[j + i*(y+1)]+Map_T[j + i*(y+1)+1]+Map_T[j + i*(y+1)-1]+Map_T[j + i*(y+1)+y+1]+Map_T[j + i*(y+1)-y-1])/5.0;
			Map_T[j + i*(y+1)] = Mid;
			Map_T[j + i*(y+1)+1] = Mid;
			Map_T[j + i*(y+1)-1] = Mid;
			Map_T[j + i*(y+1)+y+1] = Mid;
			Map_T[j + i*(y+1)-y-1] = Mid;
		}
	}
}

void ASpawnActorCpp::RandZCpp(int x, int y, int Step, float Z_Len)
{
	FRandomStream RandomStream(FMath::Rand());
	int Step_X = Step - 1;
	int Step_Y = Step_X;
	int index = -1;
	TArray<float> Map_Local;
	Map_Local.SetNum(x*y);
	for (int i = 0; i < y; i++)
	{
		Step_Y++;
		if (Step_Y > Step)
		{
			Step_Y = 1;
		}
		for(int j = 0; j < x; j++)
		{
			index++;
			Step_X++;
			if (Step_X > Step)
			{
				Step_X = 1;
			}
			if ((Step_X == Step) && (Step_Y == Step))
			{
				Map_Local[index] = RandomStream.FRandRange(Z_Len * -1, Z_Len);
			}
			else
			{
				if (Step_Y != Step)
				{
					Map_Local[index] = (Map_Local[j+i*(y+1)-(y+1)]);
				}
				else
				{
					Map_Local[index] = (Map_Local[j+i*(y+1)-1]);
				}
			}
		}
		Step_X = 0;
	}

	if (Map_Local.Num() > Map_Z.Num())
	{
		Map_Z.SetNum(Map_Local.Num());
	}
	for (int i = 0; i < Map_Local.Num(); i++)
	{
		if ((Map_Local.IsValidIndex(i)) && (Map_Z.IsValidIndex(i)))
		{
			Map_Z[i] = Map_Z[i] + Map_Local[i];
		}
	}
}

void ASpawnActorCpp::SmothZCpp(int x, int y)
{
	float Mid = 0;
	for (int i = 2; i < y-2; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Mid = (Map_Z[j + i*(y+1)]+Map_Z[j + i*(y+1)+1]+Map_Z[j + i*(y+1)-1]+Map_Z[j + i*(y+1)+y+1]+Map_Z[j + i*(y+1)-y-1])/5.0;
			Map_Z[j + i*(y+1)] = Mid;
			Map_Z[j + i*(y+1)+1] = Mid;
			Map_Z[j + i*(y+1)-1] = Mid;
			Map_Z[j + i*(y+1)+y+1] = Mid;
			Map_Z[j + i*(y+1)-y-1] = Mid;
		}
	}
}

void ASpawnActorCpp::SpawnCpp(int x, int y)
{
	for (int i = 0; i < y-2; i++)
	{
		for (int j = 0; j < x; j++)
		{
			FVector Location(100*j,100*i,Map_Z[j+i*(y+1)]*400);
			FTransform Transform(Location);
			T = Map_T[j+i*(y+1)];
			auto bp_class = LoadObject<UClass>(nullptr, TEXT("/Game/Maps_Generator/Blueprints/Block.Block_C"));
			GetWorld()->SpawnActor<AActor>(bp_class , Transform);
		}
	}
}

// Called every frame
void ASpawnActorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

