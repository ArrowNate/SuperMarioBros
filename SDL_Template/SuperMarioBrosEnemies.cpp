#include "SuperMarioBrosEnemies.h"

SuperMarioBrosEnemies::~SuperMarioBrosEnemies()
{

}

void SuperMarioBrosEnemies::Initialize()
{
    //Goomba
    goombaRect.x = 1.0f;
    goombaRect.y = 2.0f;
    goombaRect.w = 64.0f;
    goombaRect.h = 64.0f;

    //Koopa
    koopaRect.x = 2.0f;
    koopaRect.y = 3.0f;
    koopaRect.w = 64.0f;
    koopaRect.h = 64.0f;

    //Piranha Plant
    piranhaPlantRect.x = 0.0f;
    piranhaPlantRect.y = 0.0f;
    piranhaPlantRect.w = 64.0f;
    piranhaPlantRect.h = 64.0f;

    //Hammer Bro
    hammerBroRect.x = 0.0f;
    hammerBroRect.y = 0.0f;
    hammerBroRect.w = 64.0f;
    hammerBroRect.h = 64.0f;
}

void SuperMarioBrosEnemies::Render()
{
    //Goomba
    glPushMatrix();
    glTranslatef(goombaRect.x, goombaRect.y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, goombaRect.h);
    glVertex2f(goombaRect.w, goombaRect.h);
    glVertex2f(goombaRect.w, 0.0f);
    glEnd();
    glPopMatrix();

    //Koopa
    glPushMatrix();
    glTranslatef(koopaRect.x, koopaRect.y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, koopaRect.h);
    glVertex2f(koopaRect.w, koopaRect.h);
    glVertex2f(koopaRect.w, 0.0f);
    glEnd();
    glPopMatrix();

    //Piranha Plant
    glPushMatrix();
    glTranslatef(piranhaPlantRect.x, piranhaPlantRect.y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, piranhaPlantRect.h);
    glVertex2f(piranhaPlantRect.w, piranhaPlantRect.h);
    glVertex2f(piranhaPlantRect.w, 0.0f);
    glEnd();
    glPopMatrix();

    //Hammer Bro
    glPushMatrix();
    glTranslatef(hammerBroRect.x, hammerBroRect.y, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, hammerBroRect.h);
    glVertex2f(hammerBroRect.w, hammerBroRect.h);
    glVertex2f(hammerBroRect.w, 0.0f);
    glEnd();
    glPopMatrix();
}

void SuperMarioBrosEnemies::Update()
{
    //Goomba
    if (goombaRect.x < 0)
    {
        goombaSpeed = 0.2f;
    }
    else if (goombaRect.x > 640)
    {
        goombaSpeed = -0.2f;
    }
    goombaRect.x += goombaSpeed;

    //Koopa
    if (koopaRect.x < 0)
    {
        koopaSpeed = 0.4f;
    }
    else if (koopaRect.x > 640)
    {
        koopaSpeed = -0.4f;
    }
    koopaRect.x += koopaSpeed;

    //Piranha Plant
    if (piranhaPlantRect.x < 0)
    {
        piranhaPlantSpeed = 0.3f;
    }
    else if (piranhaPlantRect.x > 640)
    {
        piranhaPlantSpeed = -0.3f;
    }
    piranhaPlantRect.x += piranhaPlantSpeed;

    //Hammer Bro
    if (hammerBroRect.x < 0)
    {
        hammerBroSpeed = 0.5f;
    }
    else if (hammerBroRect.x > 640)
    {
        hammerBroSpeed = -0.5f;
    }
    hammerBroRect.x += hammerBroSpeed;
}

//void SuperMarioBrosEnemies::HandleInput()
//{
//    //Goomba
//    if (SDL_GetKeyState(NULL)[SDLK_LEFT])
//    {
//        goombaRect.x -= goombaSpeed;
//    }
//    else if (SDL_GetKeyState(NULL)[SDLK_RIGHT])
//    {
//        goombaRect.x += goombaSpeed;
//    }
//
//    //Koopa
//    if (SDL_GetKeyState(NULL)[SDLK_a])
//    {
//        koopaRect.x -= koopaSpeed;
//    }
//    else if (SDL_GetKeyState(NULL)[SDLK_d])
//    {
//        koopaRect.x += koopaSpeed;
//    }
//
//    //Piranha Plant
//    if (SDL_GetKeyState(NULL)[SDLK_q])
//    {
//        piranhaPlantRect.x -= piranhaPlantSpeed;
//    }
//    else if (SDL_GetKeyState(NULL)[SDLK_e])
//    {
//        piranhaPlantRect.x += piranhaPlantSpeed;
//    }
//
//    //Hammer Bro
//    if (SDL_GetKeyState(NULL)[SDLK_z])
//    {
//        hammerBroRect.x -= hammerBroSpeed;
//    }
//    else if (SDL_GetKeyState(NULL)[SDLK_c])
//    {
//        hammerBroRect.x += hammerBroSpeed;
//    }
//}