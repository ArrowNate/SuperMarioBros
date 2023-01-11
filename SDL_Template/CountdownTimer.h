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

	int mTimeRemaining;
public:

	CountdownTimer();
	~CountdownTimer();

	int TimeRemaining();
	void SetGameTime(int time);
	void Time(int time);
	void Update();
	void Render();
};

#endif // ! _COUNTDOWNTIMER_H
