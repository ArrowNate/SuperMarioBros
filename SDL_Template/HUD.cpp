#include "HUD.h"

HUD::HUD() {
	m_pTimer = Timer::Instance();

	m_pHUDbackground = new TextureGL("Black.png");
	m_pHUDbackground->Parent(this);
	m_pHUDbackground->Scale(Vector2(13.0f, 1.0f));
	m_pHUDbackground->Position(0.5f,0.5f);

	m_pPlayerName = new TextureGL("MARIO", "emulogic.ttf", 31, { 255, 255, 255 });
	m_pPlayerName->Parent(m_pHUDbackground);
	m_pPlayerName->Position(-21.0f, 15.0f);

	m_pPlayerScore = new TextureGL("000000", "emulogic.ttf", 31, { 255, 255, 255 });
	m_pPlayerScore->Parent(m_pHUDbackground);
	m_pPlayerScore->Position(-21.0f, 40.0f);

	m_pCoins = new AnimatedTexture("Coins.png", 0.0f, 0.0f, 14.0f, 18.0f, 2, 0.5f, AnimatedTexture::Horizontal);
	m_pCoins->Parent(m_pHUDbackground);
	m_pCoins->Position(-9.0f, 39.0f);

	m_pNumberOfCoins = new TextureGL("x 00", "emulogic.ttf", 27, { 255, 255, 255 });
	m_pNumberOfCoins->Parent(m_pHUDbackground);
	m_pNumberOfCoins->Position(-5.0f, 39.0f);

	m_pWorld = new TextureGL("WORLD", "emulogic.ttf", 31, { 255, 255, 255 });
	m_pWorld->Parent(m_pHUDbackground);
	m_pWorld->Position(8.0f, 15.0f);

	m_pWorldLevel = new TextureGL("1 - 1", "emulogic.ttf", 31, { 255, 255, 255 });
	m_pWorldLevel->Parent(m_pHUDbackground);
	m_pWorldLevel->Position(8.0f, 39.0f);

	m_pTime = new TextureGL("Time", "emulogic.ttf", 31, { 255, 255, 255 });
	m_pTime->Parent(m_pHUDbackground);
	m_pTime->Position(21.0f, 15.0f);
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

	delete m_pNumberOfCoins;
	m_pNumberOfCoins = nullptr;

	delete m_pWorld;
	m_pWorld = nullptr;

	delete m_pWorldLevel;
	m_pWorldLevel = nullptr;

	delete m_pTime;
	m_pTime = nullptr;
}

void HUD::Update() {
	m_pHUDbackground->Update();
	m_pPlayerName->Update();
	m_pPlayerScore->Update();
	m_pCoins->Update();
	m_pNumberOfCoins->Update();
	m_pWorld->Update();
	m_pWorldLevel->Update();
	m_pTime->Update();
}

void HUD::Render() {
	//m_pHUDbackground->Render();
	m_pPlayerName->Render();
	m_pPlayerScore->Render();
	m_pCoins->Render();
	m_pNumberOfCoins->Render();
	m_pWorld->Render();
	m_pWorldLevel->Render();
	m_pTime->Render();
}