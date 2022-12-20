#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H
#include "Level.h"
#include <vector>

class LevelManager {
private:
	static LevelManager* sInstance;

private:
	std::vector<Level*> m_pLevels;

	int mCurrentLevel;
	int mCurrentWorld;

public:
	static LevelManager* Instance();

	void Release();

	void Update();
	void Render();

	LevelManager();
	~LevelManager();
};
#endif // !_LEVELMANAGER_H

