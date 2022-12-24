#ifndef _TILES_H
#define _TILES_H
#include "tinyxml2.h"
#include <sdl.h>
#include <vector>
#include <string>
#include "TextureGL.h"
#include "AnimatedTexture.h"


using namespace tinyxml2; 
using namespace SDLFramework;

class Tiles : public GameEntity
{
private:

	TextureGL* m_pLevelTiles;
	AnimatedTexture* m_pAnimTiles;

	std::vector<char> mLevel;
	std::vector<Texture*> m_pLevelTextures;

	bool mIsAnimated;

public:
	

	//Tiles(std::string);
	Tiles(std::string filename, int x, int y, int w, int h);
	Tiles(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed);
	~Tiles();

	bool GetAnimatedTile();
	void TilePosition(Vector2 pos);
	void TilePosition(Vector2 pos, bool isAnimated);

	void Update();
	void Render();
};

#endif // !_TILES_H




