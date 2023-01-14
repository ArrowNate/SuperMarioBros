#ifndef _BRICKS_H
#define _BRICKS_H

class Brick
{
public:
	Brick();
	~Brick();

	//Methods
	void draw();
	void update();
	void deleteBrick();
	void Render();

private:
	//Variables
	int x;
	int y;
	int width;
	int height;
	bool isDestroyed;
};
#endif