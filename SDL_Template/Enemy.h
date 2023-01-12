//#ifndef ENEMY_H
//#define ENEMY_H
//
//#include "TextureGL.h"
//#include "AnimatedTexture.h"
//
//using namespace SDLFramework;
//
//class Goomba;
//class Koopa;
//
//
//class Enemy {
//public:
//    TextureGL texture;
//    int xPosition;
//    int yPosition;
//    int width;
//    int height;
//    
//    
//    virtual void move(int direction) = 0;
//    virtual void animate() = 0;
//    virtual void kill() = 0;
//    virtual void jump() = 0;
//    Enemy(int xPosition, int yPosition, int width, int height, TextureGL texture);
//};
//
//
//class Goomba : public Enemy {
//public:
//    //Variables
//    bool alive;
//    bool isJumping;
//    int direction;
//    int speed;
//    TextureGL* m_pGoomba;
//    
//    //Methods
//    Goomba();
//    void move(int direction);
//    void animate();
//    void kill();
//    void jump();
//};
//
//class Koopa : public Enemy {
//public:
//    //Variables
//    bool alive;
//    bool isJumping;
//    int direction;
//    int speed;
//    TextureGL* m_pKoopa;
//   
//    //Methods
//    Koopa();
//    void move(int direction);
//    void animate();
//    void kill();
//    void jump();
//};
//#endif
