#include "Ball.h"
#include <GL/glut.h>
#include <cmath>

Ball::Ball(float startX, float startY, float radius)
    : x(startX), y(startY), radius(radius) {}

float Ball::getX() const {
    return x;
}

float Ball::getY() const {
    return y;
}

float Ball::getRadius() const {
    return radius;
}

void Ball::reset(float startX, float startY) {
    x = startX;
    y = startY;
}

void Ball::move(float deltaX, float deltaY) {
    x += deltaX;
    y += deltaY;
}

void Ball::draw() const {
    // Set the color of the ball (white)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the ball as a filled circle
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float angle = i * M_PI / 180.0; // Convert degrees to radians
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}