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



	TextureGL* m_pLogo;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
};

#endif // !__STARTSCREEN_H