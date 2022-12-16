#include "StartScreen.h"


StartScreen::StartScreen() 
{

	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pHUD = new HUD();
	m_pHUD->Parent(this);
	m_pHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_pBackgrounfRef = new TextureGL("backgropundRef.png", 0, 0, 800, 600);
	m_pBackgrounfRef->Parent(this);
	m_pBackgrounfRef->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	/*m_pTiles = new TextureGL("BottomTiles.png", 0, 0, 800, 72);
	m_pTiles->Parent(this);
	m_pTiles->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9439f)*/;

	m_pTiles = new TextureGL("MainBackground.png", 0, 0, 800, 600);
	m_pTiles->Parent(this);
	m_pTiles->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

}

StartScreen::~StartScreen() 
{
	m_pHUD = nullptr;
	delete m_pBackgrounfRef;
	m_pBackgrounfRef = nullptr;

	delete m_pTiles;
	m_pTiles = nullptr;

}
void StartScreen::Update()
{
	m_pBackgrounfRef->Update();
	m_pHUD->Update();
	m_pTiles->Update();

}

void StartScreen::Render()
{
	//m_pBackgrounfRef->Render();
	m_pHUD->Render();
	m_pTiles->Render();

}