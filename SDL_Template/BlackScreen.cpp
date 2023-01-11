#include "BlackScreen.h"

bool BlackScreen::BlackScreenOff()
{
	return mBlackScreenOff;
}

void BlackScreen::BlackScreenDelay()
{
	for (int i = 0; i = mBlackScreenDelay; i++) {
		mBlackScreenDelay += -1.0 * m_pTimer->DeltaTime();
		std::cout << mBlackScreenDelay << std::endl;
		mBlackScreenOff = true;
	}
}

BlackScreen::BlackScreen()
{
	m_pTimer = Timer::Instance();
	m_pLevel1_1 = LevelManager::Instance();
	m_pHUD = new HUD();
	m_pHUD->Parent(this);
	m_pHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_PBlackScreen = new TextureGL("Black.png");
	m_PBlackScreen->Parent(this);
	m_PBlackScreen->Scale(Vector2(20.0f, 20.0f));
	m_PBlackScreen->Position(0.0f, 0.0f);


	m_PTestLevel = new TextureGL("MainBackground.png");
	m_PTestLevel->Parent(this);
	m_PTestLevel->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pLevelWorld = new TextureGL("WORLD", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pLevelWorld->Parent(this);
	m_pLevelWorld->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.4f);

	m_pWorldLevelText = new TextureGL("1-1", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorldLevelText->Parent(this);
	m_pWorldLevelText->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.4f);

	m_pMarioLifes = new TextureGL("3", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pMarioLifes->Parent(this);
	m_pMarioLifes->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.6f);

	m_pXLifes = new TextureGL("Xmultiply.png", 0, 0, 15, 15);
	m_pXLifes->Parent(this);
	m_pXLifes->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.6f);

	m_pMarioSprite = new TextureGL("MarioIdle_01.png", 0, 0, 33, 41);
	m_pMarioSprite->Parent(this);
	m_pMarioSprite->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.6f);

	mBlackScreenOff = false;
	mBlackScreenDelay = 8000.0f;
}

BlackScreen::~BlackScreen()
{
	m_pTimer = nullptr;
	m_pLevel1_1 = nullptr;
	
	delete m_pHUD;
	m_pHUD = nullptr;

	delete m_PBlackScreen;
	m_PBlackScreen = nullptr;

	delete m_PTestLevel;
	m_PTestLevel = nullptr;

	delete m_pLevelWorld;
	m_pLevelWorld = nullptr;

	delete m_pWorldLevelText;
	m_pWorldLevelText = nullptr;

	delete m_pMarioLifes;
	m_pMarioLifes = nullptr;

	delete m_pXLifes;
	m_pXLifes = nullptr;

	delete m_pMarioSprite;
	m_pMarioSprite = nullptr;
}

void BlackScreen::Update()
{
	BlackScreenDelay();
	m_pHUD->Update();
	m_pLevel1_1->Update();
}

void BlackScreen::Render()
{
	if (mBlackScreenDelay >= 0) {
		if (!mBlackScreenOff) {
			m_PBlackScreen->Render();
			m_pLevelWorld->Render();
			m_pWorldLevelText->Render();
			m_pMarioLifes->Render();
			m_pXLifes->Render();
			m_pMarioSprite->Render();
			//m_pHUD->Render();
			mBlackScreenOff = false;
		}

	}
	if (mBlackScreenDelay <= 0) {
		//m_PTestLevel->Render();
		m_pLevel1_1->Render();
		m_pHUD->Render();
	}

}
