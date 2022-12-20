#include "OnePlayerGame.h"

OnePlayerGame::OnePlayerGame()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	mGameStarted = false;
	StartNewGame();
}

OnePlayerGame::~OnePlayerGame()
{
	m_pTimer = nullptr;
}

void OnePlayerGame::StartNewGame()
{
	mGameStarted = true;
}

bool OnePlayerGame::GameOver()
{
	return false;
}

void OnePlayerGame::Update()
{

}

void OnePlayerGame::Render()
{

}
