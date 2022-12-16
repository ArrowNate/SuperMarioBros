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
	case Play:

		break;
	}
}

void ScreenManager::Render() { 
	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Render();
		break;
	case Play:
		break;
	}
}

ScreenManager::ScreenManager() {
	m_pInput = InputManager::Instance();

	mCurrentScreen = Start;
	m_pStartScreen = new StartScreen;
}

ScreenManager::~ScreenManager() {
	m_pInput = nullptr;
	m_pStartScreen = nullptr;
}