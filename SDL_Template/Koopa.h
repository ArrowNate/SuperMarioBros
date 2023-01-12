#ifndef _KOOPA_H
#define _KOOPA_H

#include "AnimatedTexture.h"

using namespace SDLFramework;

class Koopa : public GameEntity {
private:
    //Variables
    bool alive;
    int direction;
    int speed;
    TextureGL* m_pKoopa;

    int xPosition;
    int yPosition;
    int width;
    int height;



public:
    //Methods
    Koopa();
    ~Koopa();

    void Update();
    void Render();

    void Attack(int direction);

    void Move(int direction);
    //void Animate();
    //void Kill();







};
#endif