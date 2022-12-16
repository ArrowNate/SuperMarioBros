#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "InputManager.h"
#include "AnimatedTexture.h"

using namespace SDLFramework;

class StartScreen : public GameEntity
{
private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;

	TextureGL* m_pRights;

	TextureGL* m_p1Player;
	TextureGL* m_p2Player;

	TextureGL* m_pTopScore;

	TextureGL* m_pLogo;

public:
	StartScreen();
	~StartScreen();

	void Update();
	void Render();
};

#endif // !__STARTSCREEN_H