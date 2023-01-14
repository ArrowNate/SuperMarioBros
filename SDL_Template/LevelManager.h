#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H
#include "Level.h"
#include "InputManager.h"
#include <vector>

class LevelManager : public GameEntity {
private:
	static LevelManager* sInstance;

	InputManager* m_pLevelInput;
private:
	std::vector<Level*> m_pLevels;

	int mCurrentLevel;
	int mCurrentWorld;

	float mLevelMoveSpeed;
	bool mLevelMovement;

public:
	static LevelManager* Instance();

	void Release();

	void Update();
	void Render();

	bool IsLevelMove();

	LevelManager();
	~LevelManager();

private:
	void HandleLevelMovement();
};
#endif // !_LEVELMANAGER_H

