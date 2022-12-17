 #include "ScreenManager.h"

ScreenManager * ScreenManager::sInstance = nullptr;

ScreenManager * ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void ScreenManager::Update() {
	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Update();

		if (m_pInput->KeyPressed(SDL_SCANCODE_DOWN)) {
			ScreenChoice -= 1;
		}
		if (m_pInput->KeyPressed(SDL_SCANCODE_UP)) {
			ScreenChoice += 1;
		}
		if (ScreenChoice < 0) {
			ScreenChoice = 1;
		}
		else if (ScreenChoice > 1) {
			ScreenChoice = 0;
		}

		if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN) && ScreenChoice == 0) {

			mCurrentScreen = One;
		}

		if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN) && ScreenChoice == 1) {

			mCurrentScreen = Two;
		}
		break;


	case One:
		m_pOnePlayerGame->Update();
		if (m_pInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
		}
		break;

	case Two:
		if (m_pInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
		}
		break;
	}

}

void ScreenManager::Render() { 
	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Render();

	case One:
		m_pOnePlayerGame->Render();
		break;

	case Two:
		m_pTwoPlayerGame->Render();
		break;
	}

}

ScreenManager::ScreenManager() {
	mCurrentScreen = Start;
	m_pInput = InputManager::Instance();
	m_pStartScreen = new StartScreen;
	m_pOnePlayerGame = new OnePlayerGame();
	m_pTwoPlayerGame = new TwoPlayerGame();
	ScreenChoice = 0;
}

ScreenManager::~ScreenManager() {
	m_pInput = nullptr;

	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pOnePlayerGame;
	m_pOnePlayerGame = nullptr;

	delete m_pTwoPlayerGame;
	m_pTwoPlayerGame = nullptr;
}