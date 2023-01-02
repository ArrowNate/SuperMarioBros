#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <GL/gl.h>
#include <string>

class Enemy
{
public:
    Enemy();
    ~Enemy();

    void Update(float deltaTime);
    void Render();

    void SetPosition(float x, float y);

    float GetX() { return mPosition.x; }
    float GetY() { return mPosition.y; }

private:
    SDL_Rect mRect;
    SDL_Texture* mTexture;
    SDL_Renderer* mRenderer;

    struct {
        float x;
        float y;
    } mPosition;

    std::string mType;
};

#endif /* ENEMY_H */
