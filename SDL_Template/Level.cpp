#include "Level.h"

Level::Level() {

	m_pTimer = Timer::Instance();
	m_pHUD = new HUD();
	m_pHUD->Parent(this);
	m_pHUD->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_PBlackScreen = new TextureGL("Black.png");
	m_PBlackScreen->Parent(this);
	m_PBlackScreen->Scale(Vector2(20.0f, 20.0f));
	m_PBlackScreen->Position(0.0f, 0.0f);


	m_PTestLevel = new TextureGL("MainBackground.png");
	m_PTestLevel->Parent(this);
	m_PTestLevel->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pLevelWorld = new TextureGL("WORLD", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pLevelWorld->Parent(this);
	m_pLevelWorld->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.4f);

	m_pWorldLevelText = new TextureGL("1-1", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pWorldLevelText->Parent(this);
	m_pWorldLevelText->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.4f);

	m_pMarioLifes = new TextureGL("3", "emulogic.ttf", 20, { 255, 255, 255 });
	m_pMarioLifes->Parent(this);
	m_pMarioLifes->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.6f);

	m_pXLifes = new TextureGL("Xmultiply.png", 0, 0, 15, 15);
	m_pXLifes->Parent(this);
	m_pXLifes->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.6f);

	m_pMarioSprite = new TextureGL("MarioIdle_01.png", 0, 0, 33, 41);
	m_pMarioSprite->Parent(this);
	m_pMarioSprite->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.6f);

	mBlackScreenOff = false;
	mBlackScreenDelay = 10000.0f;

	m_pPlayer = new Player();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.6f);
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


Level::~Level() {
	for (auto l : m_pLevelTextures) {
		delete l;
		l = nullptr;
	}

	m_pTimer = nullptr;

	delete m_ptile;
	m_ptile = nullptr;

	delete m_pHUD;
	m_pHUD = nullptr;

	delete m_PBlackScreen;
	m_PBlackScreen = nullptr;

	delete m_PTestLevel;
	m_PTestLevel = nullptr;

	delete m_pLevelWorld;
	m_pLevelWorld = nullptr;

	delete m_pWorldLevelText;
	m_pWorldLevelText = nullptr;

	delete m_pMarioLifes;
	m_pMarioLifes = nullptr;

	delete m_pXLifes;
	m_pXLifes = nullptr;

	delete m_pMarioSprite;
	m_pMarioSprite = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;

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

void Level::LevelStage() {
	switch (mCurrentStage) {
	case StageOne:
	
		break;
	case StageTwo:
		/*m_pLevelWorld = new TextureGL("WORLD", "emulogic.ttf", 20, { 255, 255, 255 });
		m_pLevelWorld->Parent(this);
		m_pLevelWorld->Position(7.2f, 14.0f);

		m_pWorldLevelText = new TextureGL("1-2", "emulogic.ttf", 20, { 255, 255, 255 });
		m_pWorldLevelText->Parent(this);
		m_pWorldLevelText->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.4f);*/

		break;
	}
}

bool Level::BlackScreenOff() {
	return mBlackScreenOff;
}

void Level::BlackScreenDelay() {
	
	for (int i = 0; i = mBlackScreenDelay; i++) {
		mBlackScreenDelay += -1.0 * m_pTimer->DeltaTime();
		std::cout << mBlackScreenDelay << std::endl;
		mBlackScreenOff = true;
	}	
}

void Level::Update(){
	
	BlackScreenDelay();
	m_pHUD->Update();
	m_pPlayer->Update();

	//std::cout << "Level1-1" << std::endl;

}

void Level::Render()
{
	/*for (int i = 0; i < m_pLevelTextures.size(); i++) {
		if (m_pLevelTextures[i] != nullptr) {
			m_pLevelTextures[i]->Render();
		}
	}*/

	switch (mCurrentStage) {
	case StageOne:
		if (mBlackScreenDelay >= 0) {
			if (!mBlackScreenOff) {
				m_PBlackScreen->Render();
				m_pLevelWorld->Render();
				m_pWorldLevelText->Render();
				m_pMarioLifes->Render();
				m_pXLifes->Render();
				m_pMarioSprite->Render();
				m_pHUD->Render();
				mBlackScreenOff = false;
			}
			
		}
		if (mBlackScreenDelay <= 0) {
			m_PTestLevel->Render();
			m_pHUD->Render();
			m_pPlayer->Render();
		}
		break;

	case StageTwo:
		if (mBlackScreenDelay >= 0) {
			m_PBlackScreen->Render();
			m_pLevelWorld->Render();
			m_pWorldLevelText->Render();
			m_pHUD->Render();
		}
		if (mBlackScreenDelay <= 1) {
			m_PTestLevel->Render();
			m_pHUD->Render();
		}
		break;

	}
}

