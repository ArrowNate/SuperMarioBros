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
}

void LevelManager::Render()
{
    m_pLevels[mCurrentLevel]->Render();
}

LevelManager::LevelManager()
{
    mCurrentLevel = 0;
    mCurrentWorld = 0;
    m_pLevels.push_back(new Level("/Assets/Mario_Level_1_1.xml"));
}

LevelManager::~LevelManager()
{
    for (auto i : m_pLevels) {
        delete i;
        i = nullptr;
    }
}
