#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(float startX, float startY, float radius); // Constructor

    float getX() const;
    float getY() const;
    float getRadius() const;

    void reset(float startX, float startY);
    void move(float deltaX, float deltaY);
    void draw() const; // Function to draw the ball using OpenGL

private:
    float x;
    float y;
    float radius;
};

#endif
