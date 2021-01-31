// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorActor.h"

// Sets default values
AColorActor::AColorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AColorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Color.R = isRed ? 1.0f : 0.0f;
	Color.G = isGreen ? 1.0f : 0.0f;
	Color.B = isBlue ? 1.0f : 0.0f;
	Color.A = Alpha;
	UMaterialInstanceDynamic* material = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);

	material->SetVectorParameterValue(FName("Color"), Color);
	StaticMeshComponent->SetMaterial(1, material);
}

