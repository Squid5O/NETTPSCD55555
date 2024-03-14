// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */
UCLASS()
class NETTPSCD_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	UPROPERTY()
	class UNetGameInstance* gi;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	class UEditableText* edit_roomName;

	UPROPERTY( EditAnywhere , meta = (BindWidget) )
	class USlider* slider_maxPlayer;

	UPROPERTY( EditAnywhere , meta = (BindWidget) )
	class UTextBlock* text_maxPlayer;

	UPROPERTY( EditAnywhere , meta = (BindWidget) )
	class UButton* btn_doCreateRoom;

	//slider_maxPlayer를 이동시키면 text_maxPlater의 값도 바뀌게 하고싶다.
	//버튼을 누르면 UNetGameInstance::CreateRoom 을 호출하고 싶다.

	UFUNCTION()
	void onMyClicked_doCreateRoom();

	UFUNCTION()
	void OnMyValueChange_maxPlayer( float value );
};
