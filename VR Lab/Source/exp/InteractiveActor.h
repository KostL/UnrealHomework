// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveActor.generated.h"


UCLASS()
class EXP_API AInteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveActor();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractEvents")
	void OnClick();
	virtual void OnClick_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractEvents")
		void OnHoverEnter();
	virtual void OnHoverEnter_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractEvents")
		void OnHoverExit();
	virtual void OnHoverExit_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractEvents")
		void OnGrab(USceneComponent* SceneObjectd);
	virtual void OnGrab_Implementation(USceneComponent* SceneObject);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractEvents")
		void OnRelease();
	virtual void OnRelease_Implementation();
};
