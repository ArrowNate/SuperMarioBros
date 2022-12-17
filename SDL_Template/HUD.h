#ifndef _HUD_H
#define _HUD_H
#include "Timer.h"
#include "TextureGL.h"
#include "AnimatedTexture.h"

using namespace SDLFramework;

class HUD :  public GameEntity
{
private:

	Timer* m_pTimer;
	TextureGL* m_pHUDbackground;

	TextureGL* m_pPlayerName;
	TextureGL* m_pPlayerScore;

	AnimatedTexture* m_pCoins;
	TextureGL* m_pMultiply;
	TextureGL* m_pNumberOfCoins;
	TextureGL* m_pWorld;
	TextureGL* m_pWorldLevel;
	TextureGL* m_pTime;

public:
	HUD();
	~HUD();

	void Update() override;
	void Render() override;

};

#endif // !_HUD_H