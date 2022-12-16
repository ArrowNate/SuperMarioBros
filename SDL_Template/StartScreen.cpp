#include "StartScreen.h"

StartScreen::StartScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pLogo = new TextureGL("SuperMarioBrosLogo.jpg", 0, 0, 500, 221);
	m_pLogo->Parent(this);
	m_pLogo->Position(400.0f, 185.0f);

	m_pRights = new TextureGL("1985Nintendo.png", 0, 0, 300, 27);
	m_pRights->Parent(this);
	m_pRights->Position(502.0f, 309.0f);

	m_pMushroomCursor = new TextureGL("MushroomCursor.png", 0, 0, 40, 39);
	m_pMushroomCursor->Parent(this);
	m_pMushroomCursor->Position(100.0f, 100.0f);

	m_p1Player = new TextureGL("1PlayerGame.png", 0, 0, 300, 28);
	m_p1Player->Parent(this);
	m_p1Player->Position(400.0f, 365.0f);

	m_p2Player = new TextureGL("2PlayerGame.png", 0, 0, 300, 28);
	m_p2Player->Parent(this);
	m_p2Player->Position(400.0f, 410.0f);

	//m_pTopScore = new TextureGL("TOP 18891985", "SuperMarioBrosFont.ttf", 20, { 200,0,0 });
	m_pTopScore = new TextureGL("TOP - 18891985.png", 0, 0, 300, 28);
	m_pTopScore->Parent(this);
	m_pTopScore->Position(400.0f, 480.0f);
}

StartScreen::~StartScreen()
{
	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pRights;
	m_pRights = nullptr;

	delete m_pMushroomCursor;
	m_pMushroomCursor = nullptr;

	delete m_p1Player;
	m_p1Player = nullptr;

	delete m_p2Player;
	m_p2Player = nullptr;

	delete m_pTopScore;
	m_pTopScore = nullptr;
}

//void StartScreen::ChangeSelectedMode(int change)
//{
//}
//
//int StartScreen::SelectedMode()
//{
//	return 0;
//}

void StartScreen::Update()
{
	m_pLogo->Update();
	m_pRights->Update();
	m_pMushroomCursor->Update();
	m_p1Player->Update();
	m_p2Player->Update();
	m_pTopScore->Update();
}

void StartScreen::Render()
{
	m_pLogo->Render();
	m_pRights->Render();
	m_pMushroomCursor->Update();
	m_p1Player->Render();
	m_p2Player->Render();
	m_pTopScore->Render();
}