#ifndef _LEVEL_H
#define _LEVEL_H
#include "tinyxml2.h"
#include <sdl.h>
#include <vector>
#include <string>
#include "TextureGL.h"
#include "HUD.h"

using namespace tinyxml2;
using namespace SDLFramework;

class Level : public GameEntity{
public:
	enum LevelStates {Running, Finished, GameOver};

private:
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

	LevelStates mCurrentState;

public:
	std::vector<Texture*> GetLevelTextures;
	Texture* LevelTextures(char);

	void Update();
	void Render();

	LevelStates State();

	Level();
	Level(std::string);
	~Level();
};
#endif // !_LEVEL_H

