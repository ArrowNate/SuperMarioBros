#include "LevelManager.h"

LevelManager* LevelManager::sInstance = nullptr;

LevelManager* LevelManager::Instance()
{
    if (sInstance == nullptr) {
        sInstance = new LevelManager();
    }

    return sInstance;
}

void LevelManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

void LevelManager::Update()
{
    m_pLevels[mCurrentLevel]->Update();
    HandleLevelMovement();
    IsLevelMove();
}

void LevelManager::Render()
{
    m_pLevels[mCurrentLevel]->Render();
}

bool LevelManager::IsLevelMove()
{
    return mLevelMovement;
}

LevelManager::LevelManager()
{
    m_pLevelInput = InputManager::Instance();
    mLevelMoveSpeed = 500.0f;
    mLevelMovement = false;

    mCurrentLevel = 0;
    mCurrentWorld = 0;
    m_pLevels.push_back(new Level("/Assets/Mario_Level_1_1.xml"));
}

LevelManager::~LevelManager()
{
    m_pLevelInput = nullptr;

    for (auto i : m_pLevels) {
        delete i;
        i = nullptr;
    }
}

void LevelManager::HandleLevelMovement()
{
    if (m_pLevelInput->KeyPressed(SDL_SCANCODE_RIGHT) && !mLevelMovement) {
        if (mCurrentLevel = 0) {
            mLevelMovement = true;
            Translate(Vec2_Right * mLevelMoveSpeed, World);
        }
       
    }
}
