#ifndef BRICK_H
#define BRICK_H
#include "libs.hpp"

class Brick:public sf::RectangleShape{
    int maxHealthPoints;
    int healthPoints;
    
    void setColor();
public:
    Brick();
    Brick(sf::Vector2f size, sf::Vector2f pos, int hp);

    bool processHit();

    void draw(sf::RenderTarget& target) const;

    bool isDead();

    bool operator==(const Brick& b);
};
#endif
