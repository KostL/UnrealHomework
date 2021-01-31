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
	FLinearColor fcolor;
	fcolor.R = (((color) & (1 << static_cast<uint32>(EColorBitMask::RED))) > 0) ? 1.0f : 0.0f;
	fcolor.G = (((color) & (1 << static_cast<uint32>(EColorBitMask::GREEN))) > 0) ? 1.0f : 0.0f;
	fcolor.B = (((color) & (1 << static_cast<uint32>(EColorBitMask::BLUE))) > 0) ? 1.0f : 0.0f;
	fcolor.A = Alpha;
	UMaterialInstanceDynamic* material = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);

	material->SetVectorParameterValue(FName("Color"), fcolor);
	StaticMeshComponent->SetMaterial(1, material);
}

