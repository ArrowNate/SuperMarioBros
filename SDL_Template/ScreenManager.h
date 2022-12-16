#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "InputManager.h"
#include "StartScreen.h"

class ScreenManager
{
private:
	static ScreenManager * sInstance;

	enum Screens { Start, OnePlayer, TwoPlayer};
	Screens mCurrentScreen;

	InputManager* m_pInput;
	StartScreen* m_pStartScreen;

public:
	static ScreenManager * Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};
#endif