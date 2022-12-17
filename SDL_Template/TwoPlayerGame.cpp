#include "TwoPlayerGame.h"

TwoPlayerGame::TwoPlayerGame()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	mGameStarted = false;
	StartNewGame();
}

TwoPlayerGame::~TwoPlayerGame()
{
	m_pTimer = nullptr;
}

void TwoPlayerGame::StartNewGame()
{
	mGameStarted = true;
}

bool TwoPlayerGame::GameOver()
{
	return false;
}

void TwoPlayerGame::Update()
{
}

void TwoPlayerGame::Render()
{
}
