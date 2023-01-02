#include "Enemy.h"


Enemy::Enemy()

{


    mRect.x = 0;
    mRect.y = 0;
    mRect.w = 32;
    mRect.h = 32;

    mPosition.x = 0.0f;
    mPosition.y = 0.0f;

    mType = "";
}

Enemy::~Enemy()
{
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mRenderer = NULL;
}

void Enemy::Update(float deltaTime)
{
    mPosition.x += 1.0f * deltaTime;
    mPosition.y += 1.0f * deltaTime;

    mRect.x = (int)(mPosition.x + 0.5f);
    mRect.y = (int)(mPosition.y + 0.5f);
}

void Enemy::Render()
{
    SDL_RenderCopy(mRenderer, mTexture, NULL, &mRect);
}

void Enemy::SetPosition(float x, float y)
{
    mPosition.x = x;
    mPosition.y = y;

    mRect.x = (int)(x + 0.5f);
    mRect.y = (int)(y + 0.5f);
}