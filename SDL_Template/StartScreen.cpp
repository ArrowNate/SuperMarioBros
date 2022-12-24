#include "StartScreen.h"


StartScreen::StartScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pHUD = new HUD();
	m_pHUD->Parent(this);
	m_pHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_pLogo = new TextureGL("SuperMarioBrosLogo.jpg", 0, 0, 500, 221);
	m_pLogo->Parent(this);
	m_pLogo->Position(400.0f, 185.0f);

	m_pRights = new TextureGL("©1985 Nintendo", "emulogic.ttf", 20, { 255,255,255 });
	m_pRights->Parent(this);
	m_pRights->Position(510.0f, 307.0f);

	m_pPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	m_p1Player = new TextureGL("1 Player Game", "emulogic.ttf", 20, { 255,255,255 });
	m_p2Player = new TextureGL("2 Player Game", "emulogic.ttf", 20, { 255,255,255 });
	m_pMushroomCursor = new TextureGL("MushroomCursor.png", 0, 0, 40, 40);

	m_pHUD = new HUD();
	m_pHUD->Parent(this);
	m_pHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_pMainBackground = new TextureGL("MainBackground.png", 0, 0, 800, 600);
	m_pMainBackground->Parent(this);
	m_pMainBackground->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pTopScore = new TextureGL("TOP- 000000", "emulogic.ttf", 20, { 255,255,255 });
	m_pTopScore->Parent(this);
	m_pTopScore->Position(400.0f, 480.0f);

	m_pPlayerModes->Parent(this);
	m_p1Player->Parent(m_pPlayerModes);
	m_p2Player->Parent(m_pPlayerModes);
	m_pMushroomCursor->Parent(m_pPlayerModes);

	m_p1Player->Position(0.0f, -40.0f);
	m_p2Player->Position(0.0f, 0.0f);
	m_pMushroomCursor->Position(-150.0f, -29.0f);
	mCursorStartPos = m_pMushroomCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 40.0f);
	mSelectedMode = 0;
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

	m_pHUD = nullptr;
	
	delete m_pMainBackground;
	m_pMainBackground = nullptr;
}

void StartScreen::ChangeSelectedMode(int change)
{
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	m_pMushroomCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

int StartScreen::SelectedMode()
{
	return mSelectedMode;
}

void StartScreen::Update()
{
	m_pHUD->Update();
	m_pMainBackground->Update();

	if (m_pInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
		ChangeSelectedMode(1);
	}
	else if (m_pInputManager->KeyPressed(SDL_SCANCODE_UP)) {
		ChangeSelectedMode(-1);
	}
}

void StartScreen::Render()
{
	m_pHUD->Render();
	m_pMainBackground->Render();
	m_pLogo->Render();
	m_pRights->Render();
	m_pMushroomCursor->Render();
	m_p1Player->Render();
	m_p2Player->Render();
	m_pTopScore->Render();
}