#include "StartScreen.h"

StartScreen::StartScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pLogo = new TextureGL("SuperMarioBrosLogo.jpg", 0, 0, 700, 310);
	m_pLogo->Parent(this);
	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f);

	m_pTopScore = new TextureGL("TOP 18891985" "SuperMarioBrosFont.ttf");

	m_pTopScore->Parent(this);

	m_pTopScore->Position(Vec2_Zero);
}

StartScreen::~StartScreen()
{
	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pTopScore;
	m_pTopScore = nullptr;
}

void StartScreen::Update()
{
	m_pLogo->Update();
	m_pTopScore->Update();
}

void StartScreen::Render()
{
	m_pLogo->Render();
	m_pTopScore->Render();
}