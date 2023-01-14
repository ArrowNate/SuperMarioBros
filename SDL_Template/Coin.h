#ifndef COIN_H
#define COIN_H

#include <Glew.h>

class Coin {
private:
	int x, y;
	float scale;
public:
	Coin(int x, int y, float scale);
	void draw();
};

#endif 