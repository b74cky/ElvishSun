// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Setup attached input component
	void SetupInputComponent();

	// Find attached Physics Handle
	void FindPhysicsHandleComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();

	// Called when Grab is released
	void Release();
	
	// Returns current start and end of reach line
	FTwoVectors GetLineTracePoints() const;

};
