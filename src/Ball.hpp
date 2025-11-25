#ifndef BALL_H
#define BALL_H
#include "Paddle.hpp"
#include "Brick.hpp"

class Ball
{
private:
    sf::CircleShape shape;

public:
    float x, y, vX, vY, r;
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

    Ball* operator*();
    Ball& operator=(const Ball& other);
};
#endif
