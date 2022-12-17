#include "Level.h"

void Level::StartLevel()
{
	mLevelStarted = true;
}

void Level::HandleBlackScreen()
{

}

Level::Level(int level, HUD* levelHud, HUD* blackScreenHud)
{
	m_pTimer = Timer::Instance();
	m_pBlackScreenHUD = blackScreenHud;

	mLevel = level;
	mLevelStarted = false;

	mBlackScreenTimer = 0.0f;

	m_pBlackScreen = new TextureGL("Black.png", 0, 0, 800, 600);
	m_pBlackScreen->Parent(this);
	m_pBlackScreen->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pBlackScreenHUD = new HUD;
	m_pBlackScreenHUD->Parent(this);
	m_pBlackScreenHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);

	mBlackScreenOn = 0.0f;
	mBlackScrenOff = 2.0f;

}

Level::~Level()
{
}

Level::LevelStates Level::State()
{
	return mCurrentState;
}

void Level::Update()
{
}

void Level::Render()
{
}
