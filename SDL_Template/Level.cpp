#include "Level.h"

Level::Level() 
{

}

Level::Level(std::string filename) 
{
	//Reading and loading the data from the xml file
	std::string fullPath = SDL_GetBasePath();
	fullPath.append(filename);
	mXMLDocument.LoadFile(fullPath.c_str());
	mWidth = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->IntAttribute("width");
	mHeight = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->IntAttribute("height");
	auto element = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data");

	mOffsetX = 32;
	mOffsetY = 31;
	mTile = 0;
	mTileInfo = element->GetText(); //<---A string of the information between the data tag from the xml file.

	for (int i = 0; i < mTileInfo.length(); i++) {
		mLevel.push_back(mTileInfo[i]); //<-----pushing each element of the array mTileInfo into a vector
	}

	for (int i = 0; i < mHeight; i++) {
		std::vector<char> levelWidth;
		for (int j = 0; j <= mWidth * 2; j++) {
			if (mLevel[mTile] != '\n' && mLevel[mTile] != ',') {
				levelWidth.push_back(mLevel[mTile]); //<----Pushing each char into a column for debugging
			}
			mTile++;
		}
		mLevelHeight.push_back(levelWidth);//<----Pushing each column into a row for debugging
	}

	int x = 0;
	int y = 0;

	for (int i = 0; i < mLevelHeight.size(); i++) {
		for (int j = 0; j < mWidth; j++) {
			std::cout << mLevelHeight[i][j];
			m_pLevelTextures.push_back(LevelTextures(mLevelHeight[i][j]));
		}
		std::cout << std::endl; //<-----Displaying the map into the console for debugging
	}

	//This for loop sets the position and scale of each tile in the m_pLevelTextures vector
	mTile = 0;
	for (int i = 0; i < m_pLevelTextures.size(); i++) {
		if (m_pLevelTextures[mTile] != nullptr) {
			m_pLevelTextures[mTile]->Scale(Vector2(2, 2));
			m_pLevelTextures[mTile]->Position(x + 16, y);
		}
		x += mOffsetX;
		mTile++;
		if (mTile % mWidth == 0) {
			y += mOffsetY;
			x = 0;
		}
	}
	mTile = 0;
}

Level::~Level() 
{
	for (auto l : m_pLevelTextures) {
		delete l;
		l = nullptr;
	}

	delete m_ptile;
	m_ptile = nullptr;
}

/// <summary>
/// This function takes in a char and returns a TextureGL pointer
/// </summary>
/// <param name="tile"></param>
/// <returns>TextureGL*</returns>
Texture* Level::LevelTextures(char tile) {
	//Should change this to return a class of tile
	switch (tile) {
	case '6':
		m_ptile = new TextureGL("LevelTiles.png", 0, 16, 16, 16);
		break;

	case '7':
		m_ptile = new TextureGL("LevelTiles.png", 0, 16, 16, 16);
		break;

	default:
		m_ptile = nullptr;
	}

	return m_ptile;
}

void Level::Update()
{

}

void Level::Render()
{
	for (int i = 0; i < m_pLevelTextures.size(); i++) {
		if (m_pLevelTextures[i] != nullptr) {
			m_pLevelTextures[i]->Render();
		}
	}
}

Level::LevelStates Level::State()
{
	return mCurrentState;
}
