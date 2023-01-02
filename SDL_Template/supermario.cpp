#include "supermario.h"
#include <glew.h>

Enemy::Enemy(int x, int y) {
    this->x = x;
    this->y = y;
}

void Enemy::drawEnemy() {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + 20, y);
    glVertex2i(x + 20, y + 20);
    glVertex2i(x, y + 20);
    glEnd();
}

bool Enemy::moveEnemy() {
    x--;
    if (x < 0) {
        return false;
    }
    return true;
}

Goomba::Goomba(int x, int y) : Enemy(x, y) {

}

void Goomba::drawGoomba() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + 20, y);
    glVertex2i(x + 20, y + 20);
    glVertex2i(x, y + 20);
    glEnd();
}

bool Goomba::moveGoomba() {
    x--;
    if (x < 0) {
        return false;
    }
    return true;
}

Koopa::Koopa(int x, int y) : Enemy(x, y) {

}

void Koopa::drawKoopa() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + 20, y);
    glVertex2i(x + 20, y + 20);
    glVertex2i(x, y + 20);
    glEnd();
}

bool Koopa::moveKoopa() {
    x--;
    if (x < 0) {
        return false;
    }
    return true;
}
