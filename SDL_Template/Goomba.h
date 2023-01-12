#ifndef _GOOMBA_H
#define _GOOMBA_H

#include "AnimatedTexture.h"

using namespace SDLFramework;

class Goomba : public GameEntity {
private:
    //Variables
    bool alive;
    int direction;
    int speed;
    TextureGL* m_pGoomba;

        int xPosition;
        int yPosition;
        int width;
        int height;
        
        
        
        
        
   
public:
    //Methods
    Goomba();
    ~Goomba();

    void Update();
    void Render();

    void Move(int direction);
    //void Animate();
    //void Kill();
   






};
#endif