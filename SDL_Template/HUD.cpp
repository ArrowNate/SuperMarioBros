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

	m_pPlayerScore = new TextureGL("000000", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pPlayerScore->Parent(m_pHUDbackground);
	m_pPlayerScore->Position(-18.0f, 33.0f);

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

	mSetTime = 400;
}

HUD::~HUD () {

	delete m_pHUDbackground;
	m_pHUDbackground = nullptr;

	delete m_pPlayerName;
	m_pPlayerName = nullptr;

	delete m_pPlayerScore;
	m_pPlayerScore = nullptr;

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
}

void HUD::TimeCount(int time) {

	mSetTime = time;
	//time += -0.1 * m_pTimer->DeltaTime();
	std::cout << mSetTime << std::endl;
}
void HUD::Countdown() {
	if (mSetTime > 400)
		mSetTime -= (1.0f * m_pTimer->DeltaTime());
	std::stringstream timeString;
	timeString << static_cast<int>(mSetTime);
	m_pTimeText->Text(timeString.str());
}

void HUD::Update() {

	m_pHUDbackground->Update();
	m_pPlayerName->Update();
	m_pPlayerScore->Update();
	m_pCoins->Update();
	m_pMultiply->Update();
	m_pNumberOfCoins->Update();
	m_pWorld->Update();
	m_pWorldLevel->Update();
	m_pTime->Update();
	//m_pTimeText->Update();
}

void HUD::Render() {
	//m_pHUDbackground->Render();
	m_pPlayerName->Render();
	m_pPlayerScore->Render();
	m_pCoins->Render();
	m_pMultiply->Render();
	m_pNumberOfCoins->Render();
	m_pWorld->Render();
	m_pWorldLevel->Render();
	m_pTime->Render();
	//m_pTimeText->Render();
	
}