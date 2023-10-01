#include "Bar.h"
#include <GL/glut.h>

Bar::Bar(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height) {}

float Bar::getX() const {
    return x;
}

float Bar::getY() const {
    return y;
}

float Bar::getWidth() const {
    return width;
}

float Bar::getHeight() const {
    return height;
}

void Bar::moveUp(int barSpeed) {
    y += barSpeed;
}

void Bar::moveDown(int barSpeed) {
    y -= barSpeed;
}

void Bar::draw() const {

    // Define a cor da barra (branco)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Desenha um retângulo representando a barra
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}
