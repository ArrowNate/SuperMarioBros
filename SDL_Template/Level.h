#ifndef _LEVEL_H
#define _LEVEL_H
#include "tinyxml2.h"
#include <sdl.h>
#include <vector>
#include <string>
#include "TextureGL.h"
#include "HUD.h"
#include "Timer.h"

using namespace tinyxml2;
using namespace SDLFramework;

class Level : public GameEntity{

private:
	enum LevelStage {StageOne, StageTwo};
	LevelStage mCurrentStage;

	int mWidth;
	int mHeight;
	int mOffsetX;
	int mOffsetY;
	int mTile;
	std::string mTileInfo;
	tinyxml2::XMLDocument mXMLDocument;

	std::vector<std::vector<char>> mLevelHeight;
	std::vector<char> mLevel;
	std::vector<Texture*> m_pLevelTextures;
	Texture* m_ptile;

	bool mBlackScreenOff;
	int mBlackScreenDelay;
	Texture* m_PBlackScreen;
	Texture* m_PTestLevel;
	Timer* m_pTimer;
	HUD* m_pHUD;
	TextureGL* m_pLevelWorld;
	TextureGL* m_pWorldLevelText;
	TextureGL* m_pMarioLifes;
	TextureGL* m_pXLifes;
	TextureGL* m_pMarioSprite;


public:
	std::vector<Texture*> GetLevelTextures;
	Texture* LevelTextures(char);

	bool BlackScreenOff();

	void BlackScreenDelay();
	void LevelStage();
	void Update();
	void Render();

	Level();
	Level(std::string);
	~Level();
};
#endif // !_LEVEL_H

