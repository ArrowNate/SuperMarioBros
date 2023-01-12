#ifndef _GOOMBA_H
#define _GOOMBA_H

#include "AnimatedTexture.h"

using namespace SDLFramework;

class Goomba : public GameEntity {
private:
    //Variables
    bool alive;
    bool isJumping;
    int direction;
    int speed;
    TextureGL* m_pGoomba;

        int xPosition;
        int yPosition;
        int width;
        int height;
        
        
        virtual void move(int direction) = 0;
        virtual void animate() = 0;
        virtual void kill() = 0;
        virtual void jump() = 0;
        
   
public:
    //Methods
    Goomba();
    ~Goomba();

    void Update();
    void Render();

    void Move(int direction);
    void Animate();
    void Kill();
    void Jump();






};
#endif