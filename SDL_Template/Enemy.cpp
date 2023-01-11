#include "Enemy.h"


Goomba::Goomba()
{
    alive = true;
    isJumping = false;
    xPosition = 0;
    yPosition = 0;
    width = 32;
    height = 32;
    direction = 0;
    speed = 0;
    texture = TextureGL("Goomba.png", 0, 0, 32, 32);
}

void Goomba::move() {
    //Implement movement
}

void Goomba::animate() {
    //Implement animation
}

void Goomba::kill() {
    alive = false;
}

void Goomba::jump() {
    isJumping = true;
}

Koopa::Koopa() {
    alive = true;
    isJumping = false;
    xPosition = 0;
    yPosition = 0;
    width = 32;
    height = 32;
    direction = 0;
    speed = 0;
    texture = TextureGL("koopa.png", 0, 0, 32, 32);
}

void Koopa::move() {
    //Implement movement
}

void Koopa::animate() {
    //Implement animation
}

void Koopa::kill() {
    alive = false;
}

void Koopa::jump() {
    isJumping = true;
}