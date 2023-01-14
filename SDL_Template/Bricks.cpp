#include "Bricks.h"
#include <glew.h>
#include "Level.h"

Brick::Brick()
{
	x = 0;
	y = 0;
	width = 32;
	height = 32;
	isDestroyed = false;
}

Brick::~Brick()
{

}

void Brick::draw()
{
	//OpenGL Code
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void Brick::update()
{
	//Check to see if the brick is destroyed
	if (isDestroyed)
	{
		//Delete the brick
		deleteBrick();
	}
}

void Brick::deleteBrick()
{
	//OpenGL Code
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}