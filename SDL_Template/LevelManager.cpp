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


bool LevelManager::IsPlayerMovingRight()
{
    return mIsPlayerMoveRight;
}

bool LevelManager::IsLevelMove()
{
    return mLevelMovement;
}

LevelManager::LevelManager()
{
    m_pTimer = Timer::Instance();
    m_pLevelInput = InputManager::Instance();

    if (m_pPlayerMoveRight != nullptr) {
        m_pPlayerMoveRight->RunningRight();
        mIsPlayerMoveRight = false;
    }

   

    mLevelMoveSpeed = 0.0f;
    mlevelCurrentSpeed = -1.5f;
    mLevelMaxSpeed = 400.0f;

    mLevelMovement = false;


    mCurrentLevel = 0;
    mCurrentWorld = 0;
    m_pLevel1_1.push_back(new Level("/Assets/Mario_Level_1_1.xml"));
}

LevelManager::~LevelManager()
{
    m_pTimer = nullptr;
    m_pLevelInput = nullptr;

    delete m_pPlayerMoveRight;
    m_pPlayerMoveRight = nullptr;


    for (auto i : m_pLevel1_1) {
        delete i;
        i = nullptr;
    }
}

void LevelManager::HandleLevelMovement()
{
   
   /* if (m_pLevelInput->KeyDown(SDL_SCANCODE_LEFT)) {
            m_pLevel1_1[mCurrentLevel]->Translate(Vec2_Right * mlevelCurrentSpeed, World);
            std::cout <<  m_pLevel1_1[mCurrentLevel]->Position().x << std::endl;
      }*/
    
    if (m_pLevelInput->KeyDown(SDL_SCANCODE_D)) {
      
       m_pLevel1_1[mCurrentLevel]->Translate(Vec2_Right * mlevelCurrentSpeed, World);
       std::cout << m_pLevel1_1[mCurrentLevel]->Position().x << std::endl;
       mIsPlayerMoveRight = true;
       
       
    }
}

//void LevelManager::LevelMover()
//{
//   
//    Translate(Vec2_Right * (mlevelCurrentSpeed + mLevelMoveSpeed) * m_pTimer->DeltaTime(), World);
//    if (mLevelMovement == true) {
//        mlevelCurrentSpeed += 200.0f * m_pTimer->DeltaTime();
//        if (mlevelCurrentSpeed > mLevelMaxSpeed) {
//            mlevelCurrentSpeed = mLevelMaxSpeed;
//        }
//    }
//
//    if (mLevelMovement == false) {
//        mlevelCurrentSpeed -= 350.0f * m_pTimer->DeltaTime();
//        if (mlevelCurrentSpeed < 0.0f) {
//            mlevelCurrentSpeed = 0.0f;
//            mLevelMoveSpeed = 0.0f;
//        }
//    }
//}

void LevelManager::Update()
{
    m_pLevel1_1[mCurrentLevel]->Update();

    if (m_pPlayerMoveRight != nullptr) {
        m_pPlayerMoveRight->Update();
    }

    IsPlayerMovingRight();
    HandleLevelMovement();
    IsLevelMove();
}

void LevelManager::Render()
{
    m_pLevel1_1[mCurrentLevel]->Render();
}