#ifndef  _STARTSCREEN_H
#define _STARTSCREEN_H
#include "InputManager.h"
#include "AnimatedTexture.h"


using namespace SDLFramework;

class StartScreen : public GameEntity
{
private:
	//static const int GROUND_TILES[2][32];
	static const int GROUND_TILES = 33;

	Timer* m_pTimer;
	InputManager* m_pInputManager;

	TextureGL* m_pPlayerName;
	Texture* m_pPlayerScore;

	AnimatedTexture* m_pCoins;
	Texture* m_pNumberOfCoins;
	Texture* m_pWorld;
	Texture* m_pWorldLevel;

	Texture* m_pGroundText[GROUND_TILES];
	//Texture* m_pGroundText[2][32];
	GameEntity* m_pTilesPosition;
	

public:
	StartScreen();
	~StartScreen();


	void Update();
	void Render();
};

#endif // ! _STARTSCREEN_H



