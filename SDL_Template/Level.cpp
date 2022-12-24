#include "Level.h"

Level::Level() {
	
}

Level::Level(std::string filename) {
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
	int y = 150;

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
			//m_pLevelTextures[mTile]->Scale(Vector2(2, 2));
			if (m_pLevelTextures[mTile]->GetAnimatedTile()) {

				m_pLevelTextures[mTile]->TilePosition(Vector2(x, y), true);
			}
			else {
				m_pLevelTextures[mTile]->TilePosition(Vector2(x, y));
			}
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

Level::~Level() {
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
Tiles* Level::LevelTextures(char tile) {
	//Should change this to return a class of tile
	switch (tile) {
	case '1':
		//GroundBrick
		m_ptile = new Tiles("SP_LevelAssets_001.png", 0, 0, 32, 32);
		break;

		//Bricks
	case '2':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 32, 0, 32, 32);
		break;

		//Platforms
	case '5':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 128, 0, 32, 32);
		break;
		 
		//QuestionBlock
	case '6':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 160, 0, 32, 32, 2, 0.7f);
		break;

		//Bush
	case '7':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 0, 32, 32, 32);
		break;

	case '8':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 32, 32, 32, 32);
		break;	

	case '9':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 64, 32, 32, 32);
		break;

		//Hill
	case 'A':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 224, 64, 32, 32);
		break;

	case 'B':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 256, 64, 32, 32);
		break;

	case 'C':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 288, 64, 32, 32);
		break;

	case 'D':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 256, 128, 32, 32);
		break;

	case 'E':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 288, 128, 32, 32);
		break;

	case 'F':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 256, 96, 32, 32);
		break;

		//Pipes
	case 'G':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 96, 256, 32, 32);
		break;

	case 'H':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 0, 96, 32, 32);
		break;

	case 'I':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 32, 96, 32, 32);
		break;

	case 'J':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 0, 128, 32, 32);
		break;

		//Cloud 
	case 'K':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 160, 96, 32, 32);
		break;

	case 'L':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 192, 96, 32, 32);
		break;

	case 'M':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 224, 96, 32, 32);
		break;

	case 'N':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 160, 128, 32, 32);
		break;

	case 'O':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 192, 128, 32, 32);
		break;

	case 'P':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 224, 128, 32, 32);
		break;

		//Win Bar 
	case 'Q':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 96, 32, 32, 32);
		break;

	case 'R':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 128, 32, 32, 32);
		break;

	case 'S':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 160, 32, 32, 32);
		break;

	case 'T':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 192, 32, 32, 32);
		break;

		//Castle
	case 'U':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 0, 64, 32, 32);
		break;

	case 'V':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 32, 64, 32, 32);
		break;

	case 'W':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 64, 64, 32, 32);
		break;

	case 'X':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 128, 64, 32, 32);
		break;

	case 'Y':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 160, 64, 32, 32);
		break;

	case 'Z':
		m_ptile = new Tiles("SP_LevelAssets_001.png", 192, 64, 32, 32);
		break;
	default:
		m_ptile = nullptr;
	}

	return m_ptile;
}

void Level::Update() {

	for (int i = 0; i < m_pLevelTextures.size(); i++) {
		if (m_pLevelTextures[i] != nullptr) {
			m_pLevelTextures[i]->Update();
		}
	}

}

void Level::Render()
{
	for (int i = 0; i < m_pLevelTextures.size(); i++) {
		if (m_pLevelTextures[i] != nullptr) {
			m_pLevelTextures[i]->Render();
		}
	}
}
