#include "SuperMarioCoins.h"

SuperMarioCoins::SuperMarioCoins(float xPos, float yPos, float zPos, float Size)
{
    x = xPos;
    y = yPos;
    z = zPos;
    size = Size;
}

void SuperMarioCoins::drawCoin()
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(size, size, size);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, 1.5, 0.0);
    glVertex3f(0.0, 1.5, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glPopMatrix();
}

float SuperMarioCoins::getX()
{
    return x;
}

float SuperMarioCoins::getY()
{
    return y;
}

float SuperMarioCoins::getZ()
{
    return z;
}

float SuperMarioCoins::getSize()
{
    return size;
}

void SuperMarioCoins::setX(float xPos)
{
    x = xPos;
}

void SuperMarioCoins::setY(float yPos)
{
    y = yPos;
}

void SuperMarioCoins::setZ(float zPos)
{
    z = zPos;
}

void SuperMarioCoins::setSize(float Size)
{
    size = Size;
}