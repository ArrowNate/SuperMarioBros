#ifndef _ONEPLAYERGAME_H
#define _ONEPLAYERGAME_H
#include "InputManager.h"
#include "Timer.h"
#include "StartScreen.h"
#include "Player.h"

using namespace SDLFramework;

class OnePlayerGame : public GameEntity
{
private:
	Timer* m_pTimer;
	TextureGL* m_pTextureGL;
	InputManager* m_pInputManager;

	OnePlayerGame* m_pOnePlayerGame;

	float mGameStartTimer;

	bool mGameStarted;

public:
	OnePlayerGame();
	~OnePlayerGame();

	void StartNewGame();

	bool GameOver();

	void Update() override;
	void Render() override;
};

#endif // !_ONEPLAYERGAME_H