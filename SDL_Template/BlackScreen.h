#ifndef _BLACKSCREEN_H
#define _BLACKSCREEN_H
#include "TextureGL.h"
#include "HUD.h"
#include "LevelManager.h"
#include "Player.h"

using namespace SDLFramework;
class BlackScreen : public GameEntity
{
private:
	Player* m_pPlayer;
	enum LevelStage { StageOne, StageTwo };
	LevelStage mCurrentStage;
	bool mBlackScreenOff;
	int mBlackScreenDelay;
	Texture* m_PBlackScreen;
	Texture* m_PTestLevel;
	Timer* m_pTimer;
	HUD* m_pHUD;
	TextureGL* m_pLevelWorld;
	TextureGL* m_pWorldLevelText;
	TextureGL* m_pMarioLifes;
	TextureGL* m_pXLifes;
	TextureGL* m_pMarioSprite;

	LevelManager* m_pLevel1_1;
public:

	bool BlackScreenOff();
	void BlackScreenDelay();

	BlackScreen();
	~BlackScreen();

	void Update();
	void Render();
};

#endif // !_BLACKSCREEN_H



