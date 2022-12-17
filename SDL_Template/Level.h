#ifndef _LEVEL_H
#define _LEVEL_H
#include "OnePlayerGame.h"
#include "TwoPlayerGame.h"
#include "HUD.h"
#include "Timer.h"
#include "AnimatedTexture.h"
#include "StartScreen.h"
#include "ScreenManager.h"
#include "InputManager.h"

using namespace SDLFramework;

class Level : public GameEntity
{
public:
	enum LevelStates {Running, Finished, GameOver};

private:
	Timer* m_pTimer;
	HUD* m_pLevelHUD;

	int mLevel;
	bool mLevelStarted;

	float mBlackScreenTimer;

	TextureGL* m_pBlackScreen;
	HUD* m_pBlackScreenHUD;
	float mBlackScreenOn;
	float mBlackScrenOff;

	TextureGL* m_pLives;

	//Player* m_pPlayer;

	//bool mPlayerHit;
	//float mRespawnDelay;
	//float mRespawnTimer;

	//TextureGL* m_pGameOver;
	//float mGameOverDelay;
	//float mGameOverTimer;
	//float mGameOverOnScreen;

	LevelStates mCurrentState;

private:
	void StartLevel();

	void HandleBlackScreen();
	//void HandleCollisions();
	//void HandlePlayerDeath();

public:
	Level(int level, HUD* levelHud, HUD* blackScreenHud);
	~Level();

	LevelStates State();

	void Update() override;
	void Render() override;
};

#endif // !_LEVEL_H