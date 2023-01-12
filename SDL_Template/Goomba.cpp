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
    m_pGoomba->Update();
}
void Goomba::Render()
{
    m_pGoomba->Render();
}
void Goomba::Move(int direction)
{
    for (int x = 0; x < 100; x++)
    {
        //update the position of the enemy
        xPosition += speed;

        //boundary check to make sure the enemy stays on the screen
        if (xPosition > Graphics::SCREEN_WIDTH)
        {
            xPosition = 0;
        }

        //update the enemy's position on the screen
        AnimatedTexture::Horizontal(xPosition, yPosition);
    }
    
}

//void Goomba:()
//{
//}

//void Goomba::Kill()
//{
//   
//}


