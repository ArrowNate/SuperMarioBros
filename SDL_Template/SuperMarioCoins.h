#ifndef SUPER_MARIO_COINS_H
#define SUPER_MARIO_COINS_H

#include <SDL.h>
#include <SDL_opengl.h>

class SuperMarioCoins
{
private:
    float x;
    float y;
    float z;
    float size;

public:
    SuperMarioCoins(float xPos, float yPos, float zPos, float Size);

    //Draw the coin
    void drawCoin();

    //Getters and setters
    float getX();
    float getY();
    float getZ();
    float getSize();
    void setX(float xPos);
    void setY(float yPos);
    void setZ(float zPos);
    void setSize(float Size);
};

#endif //SUPER_MARIO_COINS_H