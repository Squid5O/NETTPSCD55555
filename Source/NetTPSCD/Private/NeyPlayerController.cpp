// Fill out your copyright notice in the Description page of Project Settings.


#include "NeyPlayerController.h"

#include "BattleGameMode.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpectatorPawn.h"

void ANeyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//태어날떄 내가 서버라면 게임모드를 기억하고싶다.
	if(HasAuthority())
	{
		gm = Cast<ABattleGameMode>( GetWorld()->GetAuthGameMode() );
	}
}

void ANeyPlayerController::ServerRetrySpector_Implementation()
{
	//재시작 요청을 하면 서버RPC로 관전자를 생성해서 빙의 하라고 한다.
	//관전자를 생성하고
	auto player = GetCharacter();

	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	auto spectator = GetWorld()->SpawnActor<ASpectatorPawn>(gm->SpectatorClass, params );
	//관전자로 빙의 
	Possess( spectator );
	player->Destroy();
//5초후에 다시 원래 플레이어로 시작하도록 처리하고 싶다.
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer( handle , [&]()
	{
		ServerRetry_Implementation();
	} , 5 , false );
}

//이곳은 서버에서 호출되는 함수이다. 
void ANeyPlayerController::ServerRetry_Implementation()
{
	//서버에게 현재 플레이어를 기억하고
	auto character = this->GetCharacter();
	//UnPissess 하고
	UnPossess();
	//기억한 플레이어를 파괴하고,
	character->Destroy();

	//게임모드에게 재시작 하라고 하고싶다.
	check( gm );

	if(gm)
	{
		gm->RestartPlayer( this );
	}
}
