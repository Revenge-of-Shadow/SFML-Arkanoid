#include "Brick.hpp"

void Brick::setColor(){
    if(!healthPoints) setFillColor(sf::Color::Transparent);
    else {
        int val = 0xFF/maxHealthPoints*healthPoints;
        setFillColor(sf::Color(0xFF-val, 0, val));
    }
}
Brick::Brick(){}
Brick::Brick(sf::Vector2f size, sf::Vector2f pos, int hp)
:sf::RectangleShape(size), healthPoints(hp), maxHealthPoints(hp){
    setOrigin(sf::Vector2f(size.x/2, size.y/2));
    setPosition(pos);


    setColor();
    setOutlineThickness(1.f);
    setOutlineColor(sf::Color::White);
}

bool Brick::processHit(){  //  Returns if exists.
    if(!healthPoints) return false;

    --healthPoints;
    setColor();
    return true;
}

void Brick::draw(sf::RenderTarget& target) const{
    if(!healthPoints)   return;
    target.draw(*this);
}

bool Brick::isDead(){
    return  !healthPoints;
}

bool Brick::operator==(const Brick& b){
    return getPosition()==b.getPosition();
}
