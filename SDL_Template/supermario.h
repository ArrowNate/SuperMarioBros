#ifndef __SUPERMARIO_H
#define __SUPERMARIO_H

//#include <GL/gl.h>
//#include <GL/glu.h>
#include <string>

// Base Enemy class
class Enemy {
public:
    Enemy(int x, int y);
    void drawEnemy();
    bool moveEnemy();
protected:
    int x;
    int y;
};

// Goomba enemy class
class Goomba : public Enemy {
public:
    Goomba(int x, int y);
    void drawGoomba();
    bool moveGoomba();
protected:
    int x;
    int y;
};

// Koopa enemy class
class Koopa : public Enemy {
public:
    Koopa(int x, int y);
    void drawKoopa();
    bool moveKoopa();
protected:
    int x;
    int y;
};

#endif // __SUPERMARIO_H

