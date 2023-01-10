#pragma once
#include <SDL.h>
#include <glew.h>

class SuperMarioBrosEnemies
{
public:
    SuperMarioBrosEnemies();
    ~SuperMarioBrosEnemies();

    void Initialize();
    void Render();
    void Update();
    void HandleInput();

private:
    //Goomba
    SDL_Rect goombaRect;
    float goombaSpeed;

    //Koopa
    SDL_Rect koopaRect;
    float koopaSpeed;

    //Piranha Plant
    SDL_Rect piranhaPlantRect;
    float piranhaPlantSpeed;

    //Hammer Bro
    SDL_Rect hammerBroRect;
    float hammerBroSpeed;
};

SuperMarioBrosEnemies::SuperMarioBrosEnemies()
{
    goombaSpeed = 0.2f;
    koopaSpeed = 0.4f;
    piranhaPlantSpeed = 0.3f;
    hammerBroSpeed = 0.5f;
}




