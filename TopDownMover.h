// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TopDownMover.generated.h"

// UENUM(BlueprintType) makes it visible in the Editor dropdowns
UENUM(BlueprintType)
enum class EMoveDirection : uint8
{
	Up      UMETA(DisplayName = "Arriba"),
	Down    UMETA(DisplayName = "Abajo"),
	Left    UMETA(DisplayName = "Izquierda"),
	Right   UMETA(DisplayName = "Derecha"),
	UpRight   UMETA(DisplayName = "Arriba Derecha"),
	UpLeft   UMETA(DisplayName = "Arriba Izquierda"),
	DownRight   UMETA(DisplayName = "Abajo Derecha"),
	DownLeft   UMETA(DisplayName = "Abajo Izquierda")

};

UCLASS()
class OBJECTMOVEMENT_API ATopDownMover : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATopDownMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// A visual mesh so we can actually see the object in the editor
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* MeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 2. Variables exposed to the Visual Editor
	UPROPERTY(EditAnywhere, Category = "Movement Settings")
		float Velocity;

	UPROPERTY(EditAnywhere, Category = "Movement Settings")
		EMoveDirection MoveDirection;
	UPROPERTY(EditAnywhere, Category = "Movement Settings")
		bool bIsMoving;

private:
	// 3. Boolean to control the action state
	//bool bIsMoving;

	// Function to listen to the Spacebar
	void ToggleMovement();
};
