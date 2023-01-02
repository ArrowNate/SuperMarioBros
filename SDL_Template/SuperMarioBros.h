#ifndef SUPER_MARIO_BROS_H
#define SUPER_MARIO_BROS_H

#include <SDL.h>
#include <glew.h>
#include <vector>

class GoombaEnemy {
private:
	float x, y;
	float speed;
	float width, height;
public:
	void setPosition(float x, float y);
	void setSpeed(float speed);
	void setSize(float width, float height);
	void draw();
	void update();
};

class KoopaEnemy {
private:
	float x, y;
	float speed;
	float width, height;
public:
	void setPosition(float x, float y);
	void setSpeed(float speed);
	void setSize(float width, float height);
	void draw();
	void update();
};

class SuperMarioBros {
private:
	std::vector<GoombaEnemy> enemies;
public:
	void initEnemy();
	void drawEnemy();
	void updateEnemy();
};

#endif