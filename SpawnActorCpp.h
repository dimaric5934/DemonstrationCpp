// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/RandomStream.h"
#include "Math/UnitConversion.h"
#include "Containers/Array.h"
#include "GameFramework/Actor.h"
#include "SpawnActorCpp.generated.h"

UCLASS()
class CPP24RIDER_API ASpawnActorCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActorCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<float> Map_T;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<float> Map_Z;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float T;
	
	UFUNCTION(BlueprintCallable)
	void RandTCpp(int x, int y, int Step, float Z_Len);

	UFUNCTION(BlueprintCallable)
	void SmothTCpp(int x, int y);

	UFUNCTION(BlueprintCallable)
	void RandZCpp(int x, int y, int Step, float Z_Len);

	UFUNCTION(BlueprintCallable)
	void SmothZCpp(int x, int y);

	UFUNCTION(BlueprintCallable)
	void SpawnCpp(int x, int y);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
