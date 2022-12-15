#include "StartScreen.h"


StartScreen::StartScreen() 
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pPlayerName = new TextureGL("MARIO", "emulogic.ttf", 20, {255, 255, 255 });
	m_pPlayerName->Parent(this);
	m_pPlayerName->Position(150.0f,30.0f);

	m_pPlayerScore = new TextureGL("000000", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pPlayerScore->Parent(this);
	m_pPlayerScore->Position(160.0f, 55.0f);

	m_pCoins = new AnimatedTexture("Coins.png", 0.0f, 0.0f, 14.0f, 18.0f, 2, 0.5f, AnimatedTexture::Horizontal);
	m_pCoins->Parent(this);
	m_pCoins->Position(450.0f, 55.0f);

	m_pNumberOfCoins = new TextureGL("x 00", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pNumberOfCoins->Parent(this);
	m_pNumberOfCoins->Position(500.0f, 55.0f);
	
	m_pWorld = new TextureGL("WORLD", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorld->Parent(this);
	m_pWorld->Position(800.0f, 30.0f);

	m_pWorldLevel = new TextureGL("1 - 1", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorldLevel->Parent(this);
	m_pWorldLevel->Position(800.0f, 55.0f);

	m_pTilesPosition = new GameEntity();
	m_pTilesPosition->Parent(this);
	m_pTilesPosition->Position(0.0f, 850.0f);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < GROUND_TILES; j++) {
			m_pGroundText[i] = new TextureGL("GrountTile_01.png", 0, 0, 32, 32);
			m_pGroundText[i]->Parent(m_pTilesPosition);
			m_pGroundText[i]->Position(32.0f * (i % 33), 20.5f * (i / 32));
		}
		
	}

	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < GROUND_TILES; j++) {
			m_pGroundText[2][32] = new TextureGL("GrountTile_01.png", 0, 0, 32, 32);
			m_pGroundText[2][32]->Parent(m_pTilesPosition);
			m_pGroundText[2][32]->Position(32.0f * (i % 33), 0.5f * (i / 32));
		}
	}*/
}

StartScreen::~StartScreen() 
{
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

	for (int i = 0; i < GROUND_TILES; i++) {
		for (int j = 0; j < GROUND_TILES; j++) {
			delete m_pGroundText[i];
			m_pGroundText[i] = nullptr;
		}

	}

}
void StartScreen::Update()
{
	m_pPlayerName->Update();
	m_pPlayerScore->Update();
	m_pCoins->Update();
	m_pNumberOfCoins->Update();
	m_pWorld->Update();
	m_pWorldLevel->Update();

	for (int i = 0; i < GROUND_TILES; i++) {
		for (int j = 0; j < GROUND_TILES; j++) {
			//m_pGroundText[i]->Update();
		}

	}

}

void StartScreen::Render()
{
	m_pPlayerName->Render();
	m_pPlayerScore->Render();
	m_pCoins->Render();
	m_pNumberOfCoins->Render();
	m_pWorld->Render();
	m_pWorldLevel->Render();

	for (int i = 0; i < GROUND_TILES; i++) {
		for (int j = 0; j < GROUND_TILES; j++) {
			//m_pGroundText[i]->Render();
		}

	}

}