#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "ScoreBoard.h"
#include "HUD.h"

using namespace SDLFramework;

class StartScreen : public GameEntity
{
private:

	HUD* m_pHUD;

	Texture* m_pBackgrounfRef;
	Texture* m_pMainBackground;
	Timer* m_pTimer;
	InputManager* m_pInputManager;

	GameEntity* m_pPlayerModes;
	TextureGL* m_pMushroomCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	TextureGL* m_pRights;

	TextureGL* m_p1Player;
	TextureGL* m_p2Player;

	TextureGL* m_pTopScore;
	ScoreBoard* m_pTopScoreNumber;

	TextureGL* m_pLogo;


public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	int SelectedMode();

	void Update();
	void Render();
};

#endif // ! _STARTSCREEN_H