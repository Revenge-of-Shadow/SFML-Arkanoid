#ifndef BALL_H
#define BALL_H
#include "Paddle.hpp"
#include "Brick.hpp"

class Ball
{
private:
    float x, y, vX, vY, r;
    sf::CircleShape shape;

public:
    Ball();
    Ball(float startX, float startY, float vX, float vY, float r);
    void move();
    void bounceX();
    void bounceY();
    void collideWall(float w, float h);
    bool collidePaddle(Paddle& p);
    bool collideBrick(Brick& b);
    void draw(sf::RenderTarget& target);

    float getX();
    float getVX();
    float getY();
    float getVY();
    float getR();
};
#endif
