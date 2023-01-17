#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H
#include "Level.h"
#include "InputManager.h"
#include "Timer.h"
#include "Player.h"
#include <vector>

using namespace SDLFramework;

class LevelManager : public GameEntity {
private:
	static LevelManager* sInstance;
	Timer* m_pTimer;
	InputManager* m_pLevelInput;
	Player* m_pPlayerMoveRight;

private:
	std::vector<Level*> m_pLevel1_1;

	int mCurrentLevel;
	int mCurrentWorld;

	float mLevelMoveSpeed;
	float mlevelCurrentSpeed;
	float mLevelMaxSpeed;

	bool mLevelMovement;
	bool mIsPlayerMoveRight;

public:
	static LevelManager* Instance();

	void Release();

	void Update();
	void Render();

	bool IsPlayerMovingRight();
	bool IsLevelMove();
	void HandleLevelMovement();
	bool IsPlayerMove();

	LevelManager();
	~LevelManager();

private:
	
	void LevelMover();
};
#endif // !_LEVELMANAGER_H

