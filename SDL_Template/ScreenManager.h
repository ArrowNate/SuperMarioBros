#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "InputManager.h"

using namespace SDLFramework;

class ScreenManager {
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play };
	Screens mCurrentScreen;

	InputManager* m_pInput;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};
#endif