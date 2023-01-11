#ifndef ENEMY_H
#define ENEMY_H

#include "TextureGL.h"
#include "AnimatedTexture.h"
using namespace SDLFramework;
using namespace std;

class Goomba;
class Koopa;

TextureGL* m_pGoomba;
TextureGL* m_pKoopa;

class Enemy {
public:
    TextureGL texture;
    int xPosition;
    int yPosition;
    int width;
    int height;

    virtual void move() = 0;
    virtual void animate() = 0;
    virtual void kill() = 0;
    virtual void jump() = 0;
};

class Goomba : public Enemy {
public:
    //Variables
    bool alive;
    bool isJumping;
    int direction;
    int speed;

    //Methods
    Goomba();
    void move();
    void animate();
    void kill();
    void jump();
};

class Koopa : public Enemy {
public:
    //Variables
    bool alive;
    bool isJumping;
    int direction;
    int speed;

    //Methods
    Koopa();
    void move();
    void animate();
    void kill();
    void jump();
};
#endif