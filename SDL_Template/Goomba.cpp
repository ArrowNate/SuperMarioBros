#include "Goomba.h"


Goomba::Goomba()
{
    alive = true;
    isJumping = false;
    xPosition = 32;
    yPosition = 0;
    width = 32;
    height = 32;
    direction = 1;
    speed = 2;

    m_pGoomba = new TextureGL("Goomba.png", 0, 0, 32, 64);
    m_pGoomba->Parent(this);
    m_pGoomba->Position(-100.0f, 150.0f);
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
}

void Goomba::Animate()
{
}

void Goomba::Kill()
{
}

void Goomba::Jump()
{
}


