#include "Koopa.h"
#include "AnimatedTexture.h"
#include <chrono>


Koopa::Koopa()
{
    alive = true;
    xPosition = 0;
    yPosition = 0;
    width = 0;
    height = 0;
    direction = 0;
    speed = 0;

    m_pKoopa = new AnimatedTexture("KoopaRight.png",0,0, 128,160, 2, 0.5f, AnimatedTexture::Horizontal);
    m_pKoopa->Parent(this);
    m_pKoopa->Position(-100.0f, 184.0f);
}

Koopa::~Koopa()
{
    delete m_pKoopa;
    m_pKoopa = nullptr;
}
void Koopa::Update()
{
    Move(direction);
    m_pKoopa->Update();

    // Added code
    direction = 0;
    speed = 1.0f;
}
void Koopa::Render()
{
    m_pKoopa->Render();
}
void Koopa::Move(int direction)
{
    if (direction == 0)
    {
        xPosition += speed;
        if (xPosition > 512)
        {
            xPosition = 0;
        }
        m_pKoopa->Position(xPosition, 184.0f);
    }
    else if (direction == 1)
    {
        xPosition -= speed;
        if (xPosition < 0)
        {
            xPosition = 512;
        }
        m_pKoopa->Position(xPosition, 184.0f);
    }
}
    void Koopa::Attack(int direction)
    {
        // Attack in the same direction as the Koopa is moving
        float xPos = xPosition;
        float yPos = yPosition;
        float attackSpeed = 10.0f;
        float attackWidth = 32.0f;
        float attackHeight = 64.0f;

        if (direction == 0)
        {
            xPos += attackSpeed;
        }
        else if (direction == 1)
        {
            xPos -= attackSpeed;
        }

        AnimatedTexture* attack = new AnimatedTexture("KoopaLeft.png", 0, 0, attackWidth, attackHeight, 2, 1.0f, AnimatedTexture::Horizontal);
        attack->Parent(this);
        attack->Position(xPos, yPos);

        std::chrono::milliseconds duration(500);
        //std::this_thread::sleep_for(duration);

        delete attack;
        attack = nullptr;
    }

