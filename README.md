# NETTPSCD55555
NETTPSCD55555


//////3.13
실제게 임은 서버에만 저장된다?

캐시!

1. 플레이어 컨트롤러를 상속받은 클래스 생성
2. GameMode에 배치
3. UI에서 Retry를 하면
4. 플레이어 컨트롤러에서 현재폰을 기억하고 UnPossess하고 현재폰을 파괴
5. GameMode에게 재시작 하라고 하고 싶다.

C++ 기본

class A 
class B : public A 

A a ;
B* = Cast<B>(&a);
ㄴ 다운캐스트

캐스트
업캐스트
다운캐스트

다운캐스트 에러 잘 남. = nullpoint

비긴플레이 이후에 포제스(빙의)!

--캐릭터 생성
Pawn::beginPlay : GetController
Possess : GetController

관전자?

0----
언리얼 네트워크
방(RooM) - 세션

BatttleMap
LobbyMap 방생성/방찾기/방입장

방생성자- 호스트


게임인스턴스에 모'드 맵 다 들어감

"C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe" "C:\Projects\Lec\NetTPS\NetTPS.uproject" -game -ResX=640 -ResY=480 -WinX=200 -WinY=300 -log

batch 파일


--------------

스팀말고도 방법은 많음 - 네틐워크
.3.14

언리얼5 데디케이트 서버
ㄴ 포트나이트돌림

클라우드

포톤네트워크

데디케이트는 전용서보라 비용들어감. 언리얼소스코드 다운받아야함

호스트가 나가면 방이 깨짐

파인디파인

TSharedPtr  - 언리얼의 스마트포인터 

부바

------------03.18
3.20
R Value vs L Value

깊은 복사 , 얕은 복사

이동 시맨틱  = 이동 생성자

자료형, 변수, 포인터, 배열, 조건문, 반복문, 함수, 
클래스 : 생성자, 소멸자, 복사생성자, 이동생성자
Lvalue, Rvalue, 깊은 복사, 얕은 복사, 가상함수,
추상클래스, 인터페이스, 형변환 static_cast, dynamic_cast,
예외처리, 매트로, STL, 탬플릿
스마트포인터 : shard_ptr,  unique_ptr : weak_ptr
