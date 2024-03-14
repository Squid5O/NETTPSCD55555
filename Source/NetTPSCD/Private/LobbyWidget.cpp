// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"

#include "NetGameInstance.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	gi = GetWorld()->GetGameInstance<UNetGameInstance>();

	btn_doCreateRoom->OnClicked.AddDynamic( this , &ULobbyWidget::onMyClicked_doCreateRoom );
	
	slider_maxPlayer->OnValueChanged.AddDynamic( this , &ULobbyWidget::OnMyValueChange_maxPlayer );

	text_maxPlayer->SetText(FText::AsNumber( slider_maxPlayer->GetValue() ));
	slider_maxPlayer->SetMinValue( 2 );
	slider_maxPlayer->SetMaxValue( 10 );
	slider_maxPlayer->SetStepSize( 1 );
	slider_maxPlayer->MouseUsesStep = true;
	//GetWorld()->GetFirstPlayerController()->SetShowMouseCursor( true ); lobbygame에 들어감
}

void ULobbyWidget::onMyClicked_doCreateRoom()
{
	//만약 방이름이 비어있ㄸ으면 함수를 종료하고 싶다.

	FString roomName = edit_roomName->GetText().ToString();
	if(roomName.TrimStartAndEnd().IsEmpty())
	{
		UE_LOG( LogTemp , Warning , TEXT( "방 이름을 안 적었어욯훃호홓ㅅ!!!!!!!!!!!!" ) );
		return;
	}

	TArray<FString> badWords;
	badWords.Add( TEXT( "바보" ) );
	badWords.Add( TEXT( "똥개" ) );
	for(int i = 0; i < badWords.Num(); i++)
	{
		if(roomName.Contains(badWords[i]))
		{
			UE_LOG( LogTemp , Warning , TEXT( "방 이름이 적절하지 않아횻!!" ) );
			return;
		}
	}


	//UNetGameInstance::CreateRoom 을 호출하고 싶다.
//auto gi = GetWorld()->GetGameInstance<UNetGameInstance>(); 헤에 추가하고 스트럭트에 나눠눔
	int32 maxPlayer = slider_maxPlayer->GetValue();
	gi->CreateRoom( maxPlayer , roomName );
}

void ULobbyWidget::OnMyValueChange_maxPlayer(float value)
{
	text_maxPlayer->SetText( FText::AsNumber( value ));
}
