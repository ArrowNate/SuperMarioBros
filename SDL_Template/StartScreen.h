#ifndef  _STARTSCREEN_H
#define _STARTSCREEN_H
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "HUD.h"


using namespace SDLFramework;

class StartScreen : public GameEntity
{
private:
	//static const int GROUND_TILES[2][32];

	Timer* m_pTimer;
	InputManager* m_pInputManager;
	HUD* m_pHUD;

	Texture* m_pBackgrounfRef;
	Texture* m_pTiles;

public:
	StartScreen();
	~StartScreen();


	void Update();
	void Render();
};

#endif // ! _STARTSCREEN_H



