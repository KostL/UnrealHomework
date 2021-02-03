// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabInteractActor.h"

// Sets default values
AGrabInteractActor::AGrabInteractActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent->SetSimulatePhysics(true);
	isGrabed = false;
}

// Called when the game starts or when spawned
void AGrabInteractActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGrabInteractActor::OnGrab_Implementation(USceneComponent* SceneObject)
{
	GrabComponent = SceneObject;
	auto strictRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, true);
	AttachToComponent(SceneObject, strictRules);
	isGrabed = true;
}

void AGrabInteractActor::OnRelease_Implementation()
{
	if (GrabComponent != nullptr) {
		FVector forward = GrabComponent->GetForwardVector();
		FVector velocity = GrabComponent->GetComponentVelocity();
		StaticMeshComponent->SetSimulatePhysics(true);
		GrabComponent = nullptr;
		auto rules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, true);
		DetachFromActor(rules);
		StaticMeshComponent->AddImpulseAtLocation(forward * velocity, FVector(0.0f, 0.0f, 0.0f), NAME_None);
		isGrabed = false;
	}

}

