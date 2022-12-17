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
	Texture* m_pPlayerScore;

	AnimatedTexture* m_pCoins;
	Texture* m_pNumberOfCoins;
	Texture* m_pWorld;
	Texture* m_pWorldLevel;
	Texture* m_pTime;

public:
	HUD();
	~HUD();

	void Update() override;
	void Render() override;

};

#endif // !_HUD_H