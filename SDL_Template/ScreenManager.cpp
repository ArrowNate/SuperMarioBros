 #include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
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

		break;
	case Play:
		
		break;
	}
}

void ScreenManager::Render() { 
	switch (mCurrentScreen) {
	case Start:
		break;
	case Play:
		break;
	}
}

ScreenManager::ScreenManager() {
	m_pInput = InputManager::Instance();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	m_pInput = nullptr;
}