#include "Goomba.h"
#include <chrono>


Goomba::Goomba()
{
    alive = true;
    xPosition = 0;
    yPosition = 0;
    width = 0;
    height = 0;
    direction = 0;
    speed = 0;

    m_pGoomba = new AnimatedTexture("Goomba.png", 0, 0, 32, 64, 2, 0.5f, AnimatedTexture::Horizontal);
    m_pGoomba->Parent(this);
    m_pGoomba->Position(-100.0f, 201.0f);
}

Goomba::~Goomba()
{
    delete m_pGoomba;
    m_pGoomba = nullptr;
}
void Goomba::Update()
{
    Move(direction);
    m_pGoomba->Update();

    // Added code
    direction = 0;
    speed = 1.0f;
}
void Goomba::Render()
{
    m_pGoomba->Render();
}
void Goomba::Move(int direction)
{
    if (direction == 0)
    {
        xPosition += speed;
        if (xPosition > 512)
        {
            xPosition = 0;
        }
        m_pGoomba->Position(xPosition, 201.0f);
    }
    else if (direction == 1)
    {
        xPosition -= speed;
        if (xPosition < 0)
        {
            xPosition = 512;
        }
        m_pGoomba->Position(xPosition, 201.0f);
    }
}
