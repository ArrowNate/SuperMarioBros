#ifndef  _COUNTDOWNTIMER_H
#define _COUNTDOWNTIMER
#include "TextureGL.h"
#include <vector>

using namespace SDLFramework;

class CountdownTimer : public GameEntity
{
private:

	std::vector<Texture*> m_pCountDown;
	SDL_Color mColor;

public:

	CountdownTimer();
	~CountdownTimer();

	void Time(int time);
	void Render();
};

#endif // ! _COUNTDOWNTIMER_H



