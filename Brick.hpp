#include "libs.hpp"
#include <SFML/Graphics/Color.hpp>

class Brick:public sf::RectangleShape{
    int maxHealthPoints;
    int healthPoints;
    
    sf::Color giveColor(){
        if(!healthPoints) return sf::Color::Transparent;
        else {
            int val = 0xFF/maxHealthPoints*healthPoints;
            return sf::Color(0xFF-val, val, 0);
        }
    }
public:
    Brick();
    Brick(sf::Vector2f size, sf::Vector2f pos, int hp)
        :sf::RectangleShape(size), healthPoints(hp), maxHealthPoints(hp){
        setPosition(pos);


        setFillColor(giveColor());
        setOutlineThickness(getSize().x/getSize().y);
        setOutlineColor(sf::Color::White);
    }

    bool processHit(){  //  Returns if exists.
        if(!healthPoints) return false;

        --healthPoints;
        setFillColor(giveColor());
        return true;
    }

    void draw(sf::RenderTarget& target) const{
        if(!healthPoints)   return;
        target.draw(*this);
    }
};
