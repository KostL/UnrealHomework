// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorActor.generated.h"

UENUM(Blueprintable, Meta = (Bitflags))
enum class EColorBitMask:uint8
{
	RED,
	GREEN,
	BLUE
};

UCLASS()
class EXP_API AColorActor : public AActor
{
	GENERATED_BODY()

	
	
public:	

	// Sets default values for this actor's properties
	AColorActor();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Bitmask, BitmaskEnum = "EColorBitMask"))
	uint8  color;
	UPROPERTY(EditAnywhere)
	float Alpha =  1.0f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
