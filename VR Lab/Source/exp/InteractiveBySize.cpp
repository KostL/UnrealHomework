// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBySize.h"

// Sets default values
AInteractiveBySize::AInteractiveBySize()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractiveBySize::BeginPlay()
{
	Super::BeginPlay();
	CommonScale = GetActorScale3D();
}

// Called every frame
void AInteractiveBySize::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isRotate)
	{
		StaticMeshComponent->AddRelativeRotation(FRotator(0.f, 0.f, 1.f));
	}
}

void AInteractiveBySize::OnClick_Implementation()
{
	isRotate = !isRotate;
}
void AInteractiveBySize::OnHoverEnter_Implementation()
{
	SetActorScale3D(CommonScale+HoverScale);
}
void AInteractiveBySize::OnHoverExit_Implementation()
{
	SetActorScale3D(CommonScale);
}