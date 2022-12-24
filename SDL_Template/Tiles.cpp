#include "Tiles.h"

//Texture* Tiles::LevelTextures(char tiles)

//}

Tiles::Tiles(std::string filename, int x, int y, int w, int h)
{
	m_pLevelTiles = new TextureGL(filename, x, y, w, h);

	mIsAnimated = false;
}

Tiles::Tiles(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed)
{
	m_pAnimTiles = new AnimatedTexture(filename, x, y, w, h, frameCount, animationSpeed, AnimatedTexture::Horizontal);

	mIsAnimated = true;
}

Tiles::~Tiles()
{
	delete m_pLevelTiles;
	m_pLevelTiles = nullptr;

	delete m_pAnimTiles;
	m_pAnimTiles = nullptr;
}

bool Tiles::GetAnimatedTile()
{
	return mIsAnimated;
}

void Tiles::TilePosition(Vector2 pos)
{
	m_pLevelTiles->Position(pos);
}

void Tiles::TilePosition(Vector2 pos, bool isAnimated)
{
	m_pAnimTiles->Position(pos);
}

void Tiles::Update()
{
	if (m_pLevelTiles != nullptr) {
		m_pLevelTiles->Update();
	}

	if (m_pAnimTiles != nullptr) {
		m_pAnimTiles->Update();
	}

}

void Tiles::Render()
{
	if (m_pLevelTiles != nullptr) {
		m_pLevelTiles->Render();
	}

	if (m_pAnimTiles != nullptr) {
		m_pAnimTiles->Render();
	}
}
