// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InteractiveActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveBySize.generated.h"

UCLASS()
class EXP_API AInteractiveBySize : public AInteractiveActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AInteractiveBySize();
	UPROPERTY(EditAnywhere)
		FVector HoverScale;
	UPROPERTY(EditAnywhere)
		bool isRotate = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector CommonScale;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnClick_Implementation() override;
	virtual void OnHoverEnter_Implementation() override;
	virtual void OnHoverExit_Implementation() override;
};
