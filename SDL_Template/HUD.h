#ifndef _HUD_H
#define _HUD_H
#include "Timer.h"
#include "TextureGL.h"
#include "AnimatedTexture.h"
#include <ctime>
#include <vector>

using namespace SDLFramework;

class HUD :  public GameEntity
{
private:

	Timer* m_pTimer;
	Texture* m_pTimeText;
	TextureGL* m_pHUDbackground;

	TextureGL* m_pPlayerName;
	TextureGL* m_pPlayerScore;

	AnimatedTexture* m_pCoins;
	TextureGL* m_pMultiply;
	TextureGL* m_pNumberOfCoins;
	TextureGL* m_pWorld;
	TextureGL* m_pWorldLevel;
	TextureGL* m_pTime;

	int mSetTime;

public:
	HUD();
	~HUD();

	void TimeCount(int time);

	void Update() override;
	void Render() override;

};

#endif // !_HUD_H