#ifndef _ONEPLAYERGAME_H
#define _ONEPLAYERGAME_H
#include "InputManager.h"
#include "Timer.h"
#include "StartScreen.h"

using namespace SDLFramework;

class OnePlayerGame : public GameEntity
{
private:
	Timer* m_pTimer;
	TextureGL* m_pTextureGL;
	InputManager* m_pInputManager;

	OnePlayerGame* m_pOnePlayerGame;
};

#endif // !_ONEPLAYERGAME_H