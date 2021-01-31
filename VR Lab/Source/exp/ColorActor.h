// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorActor.generated.h"

UCLASS()
class EXP_API AColorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColorActor();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere)
		bool isRed;
	UPROPERTY(EditAnywhere)
		bool isBlue;
	UPROPERTY(EditAnywhere)
		bool isGreen;
	UPROPERTY(EditAnywhere)
		float Alpha;
	//UPROPERTY(EditAnywhere)
	FLinearColor Color;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
