// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NeyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NETTPSCD_API ANeyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//태어날 때 내가 서버리면 게임모드를 기억하고 싶다.
	UPROPERTY()
	class ABattleGameMode* gm;

	virtual void BeginPlay() override;

	//재시작 요청이 오면 서버RPC로 서버에게 현재 플레이어를 UnPossess하고 파괴하고, 게임 모드에게 재시작해라고 하고 싶다능
	UFUNCTION(Server, Reliable)
	void ServerRetry();
};
