#ifndef BOARD_H
#define BOARD_H
#include "libs.hpp"

class Paddle{
    float x, y, width, height, vx;
    sf::RectangleShape shape;


public:
    Paddle(float width, float height, float x, float y, float vx);

    void moveLeft();
    void moveRight();

    void clampToBounds(float w);

    void draw(sf::RenderTarget& target);

    float getX();
    float getY();
    float getWidth();
    float getHeight();
};
#endif
