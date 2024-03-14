// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "NetGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NETTPSCD_API UNetGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//시작할때 세션인페이스를 기억하고 싶다.
	virtual void Init() override;

	IOnlineSessionPtr sessionInterface;
	//세션 == 방(Room)
	//세션생성요청함수
	FString hostName = TEXT( "ohmo" );
	void CreateRoom(int32 maxPlayerCount, FString roomName);
	//세션생성응답함수
	void OnCreateRoomComplete( FName sessionName , bool bWasSuccessful );

	TSharedPtr<FOnlineSessionSearch> roomSearch;
	//세션검색요청
	void FindOtherRooms();
	//세션검색응답
	void OnMyFindOtherRoomsComplete( bool bWasSuccessful );
	
};
