#ifndef BOARD_H
#define BOARD_H
#include "libs.hpp"

class Paddle{
    sf::RectangleShape shape;


public:
    float  width, height, vx;
    float x, y;
    Paddle();
    Paddle(float width, float height, float x, float y, float vx);

    void moveLeft();
    void moveRight();

    void clampToBounds(float w);

    void draw(sf::RenderTarget& target);

    float getX();
    void setX(float);
    float getY();
    void setY(float);
    float getWidth();
    float getHeight();

    Paddle* operator*();
    Paddle& operator=(const Paddle& other);
};
#endif
