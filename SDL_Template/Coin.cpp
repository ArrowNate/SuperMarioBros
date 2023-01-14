#include "Coin.h"



Coin::Coin(int x, int y, float scale) : x(x), y(y), scale(scale) {}

void Coin::draw() {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(scale, scale, scale);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glVertex2f(0, 0);
	glEnd();
	glPopMatrix();
}