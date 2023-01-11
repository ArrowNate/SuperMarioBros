#include "HUD.h"

HUD::HUD() {
	m_pTimer = Timer::Instance();

	m_pHUDbackground = new TextureGL("Black.png");
	m_pHUDbackground->Parent(this);
	m_pHUDbackground->Scale(Vector2(13.0f, 1.0f));
	m_pHUDbackground->Position(0.5f,0.5f);

	m_pPlayerName = new TextureGL("MARIO", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pPlayerName->Parent(m_pHUDbackground);
	m_pPlayerName->Position(-18.8f, 14.0f);

	m_pMarioScore = new ScoreBoard();
	m_pMarioScore->Score(100000);
	m_pMarioScore->Parent(m_pHUDbackground);
	m_pMarioScore->Position(-13.5f, 33.0f);

	m_pCoins = new AnimatedTexture("Coins.png", 0.0f, 0.0f, 14.0f, 20.0f, 2, 0.5f, AnimatedTexture::Horizontal);
	m_pCoins->Parent(m_pHUDbackground);
	m_pCoins->Position(-9.0f, 32.0f);

	m_pMultiply = new TextureGL("Xmultiply.png", 0, 0, 15, 15);
	m_pMultiply->Parent(m_pHUDbackground);
	m_pMultiply->Position(-7.5f, 35.0f);

	m_pNumberOfCoins = new TextureGL("00", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pNumberOfCoins->Parent(m_pHUDbackground);
	m_pNumberOfCoins->Position(-5.0f, 33.0f);

	m_pWorld = new TextureGL("WORLD", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorld->Parent(m_pHUDbackground);
	m_pWorld->Position(7.2f, 14.0f);

	m_pWorldLevel = new TextureGL("1-1", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorldLevel->Parent(m_pHUDbackground);
	m_pWorldLevel->Position(7.2f, 33.0f);

	m_pTime = new TextureGL("Time", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pTime->Parent(m_pHUDbackground);
	m_pTime->Position(19.0f, 14.0f);

	m_pTimeText = new TextureGL("400", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pTimeText->Parent(m_pHUDbackground);
	m_pTimeText->Position(19.0f, 33.0f);

	m_pCountdownTimer = new CountdownTimer();
	m_pCountdownTimer->Time(400);
	m_pCountdownTimer->Parent(m_pHUDbackground);
	m_pCountdownTimer->Position(20.0f, 33.0f);

	mSetTime = 400;
}

HUD::~HUD () {

	delete m_pHUDbackground;
	m_pHUDbackground = nullptr;

	delete m_pPlayerName;
	m_pPlayerName = nullptr;

	delete m_pMarioScore;
	m_pMarioScore = nullptr;

	delete m_pCoins;
	m_pCoins = nullptr;

	delete m_pMultiply;
	m_pMultiply = nullptr;

	delete m_pNumberOfCoins;
	m_pNumberOfCoins = nullptr;

	delete m_pWorld;
	m_pWorld = nullptr;

	delete m_pWorldLevel;
	m_pWorldLevel = nullptr;

	delete m_pTime;
	m_pTime = nullptr;

	delete m_pTimeText;
	m_pTimeText = nullptr;

	delete m_pCountdownTimer;
	m_pCountdownTimer = nullptr;

}

//int HUD::TimeRemaining()
//{
//	return mSetTime;
//}
//
////void HUD::SubTime()
////{
////}
//
//void HUD::SetGameTime(int time) {
//
//	//mSetTime -= time;
//	mSetTime = time;
//	time += -0.1 * m_pTimer->DeltaTime();
//	std::cout << mSetTime << std::endl;
//	
//}

void HUD::SetPlayerScore(int score) {
	m_pMarioScore->Score(score);
}

void HUD::Update() {

	
	m_pHUDbackground->Update();
	m_pPlayerName->Update();
	m_pMarioScore->Update();
	m_pCoins->Update();
	m_pMultiply->Update();
	m_pNumberOfCoins->Update();
	m_pWorld->Update();
	m_pWorldLevel->Update();
	m_pTime->Update();
	m_pCountdownTimer->Update();
	
	//m_pTimeText->Update();
}

void HUD::Render() {
	//m_pHUDbackground->Render();
	
	m_pPlayerName->Render();
	m_pMarioScore->Render();
	m_pCoins->Render();
	m_pMultiply->Render();
	m_pNumberOfCoins->Render();
	m_pWorld->Render();
	m_pWorldLevel->Render();
	m_pTime->Render();
	m_pCountdownTimer->Render();

	//m_pTimeText->Render();
	
	