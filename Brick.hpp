#include "libs.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Brick:public sf::RectangleShape{
    int maxHealthPoints;
    int healthPoints;
    
    void setColor(){
        if(!healthPoints) setFillColor(sf::Color::Transparent);
        else {
            int val = 0xFF/maxHealthPoints*healthPoints;
            setFillColor(sf::Color(0xFF-val, 0, val));
        }
    }
public:
    Brick();
    Brick(sf::Vector2f size, sf::Vector2f pos, int hp)
        :sf::RectangleShape(size), healthPoints(hp), maxHealthPoints(hp){
        setOrigin(sf::Vector2f(size.x/2, size.y/2));
        setPosition(pos);


        setColor();
        setOutlineThickness(1.f);
        setOutlineColor(sf::Color::White);
    }

    bool processHit(){  //  Returns if exists.
        if(!healthPoints) return false;

        --healthPoints;
        setColor();
        return true;
    }

    void draw(sf::RenderTarget& target) const{
        if(!healthPoints)   return;
        target.draw(*this);
    }

    bool isDead(){
        return  !healthPoints;
    }

    bool operator==(const Brick& b){
        return getPosition()==b.getPosition();
    }
};
