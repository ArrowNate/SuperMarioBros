#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"

class ScreenManager {
private:
	static ScreenManager * sInstance;

	enum Screens { Start, One, Two };
	Screens mCurrentScreen;
	InputManager* m_pInput;
	StartScreen* m_pStartScreen;
	ScreenManager* m_pScreenManager;
	//OnePlayerGame* m_pOnePlayerGame;
	//TwoPlayerGame* m_pTwoPlayerGame;

	int ScreenChoice;

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