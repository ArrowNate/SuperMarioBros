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
		break;
	case OnePlayer:

		break;
	case TwoPlayer:

		break;
	}

}

void ScreenManager::Render() { 
	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Render();
		break;
	case OnePlayer:

		break;
	case TwoPlayer:

		break;
	}

}

ScreenManager::ScreenManager() {
	mCurrentScreen = Start;
	m_pInput = InputManager::Instance();
	m_pStartScreen = new StartScreen();

}

ScreenManager::~ScreenManager() {
	m_pInput = nullptr;
	m_pStartScreen = nullptr;
}