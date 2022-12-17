#ifndef _TWOPLAYERGAME_H
#define _TWOPLAYERGAME_H
#include "InputManager.h"
#include "Timer.h"
#include "StartScreen.h"

using namespace SDLFramework;

class TwoPlayerGame : public GameEntity
{
private:
	Timer* m_pTimer;
	TextureGL* m_pTextureGL;
	InputManager* m_pInputManager;

	TwoPlayerGame* m_pTwoPlayerGame;

	float mGameStartTimer;

	bool mGameStarted;

public:
	TwoPlayerGame();
	~TwoPlayerGame();

	void StartNewGame();

	bool GameOver();

	void Update() override;
	void Render() override;
};

#endif // !_TWOPLAYERGAME_H