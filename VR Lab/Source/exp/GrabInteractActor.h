// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InteractiveActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrabInteractActor.generated.h"


UCLASS()
class EXP_API AGrabInteractActor : public AInteractiveActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabInteractActor();
	USceneComponent* GrabComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnGrab_Implementation(USceneComponent* SceneObject) override;
	virtual void OnRelease_Implementation() override;

};
