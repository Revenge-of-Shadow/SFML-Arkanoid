#include <iostream>
#include <SFML/Graphics.hpp>

class Paddle{
    float x, y, width, height, vx;
    sf::RectangleShape shape;


public:
    Paddle(float width, float height, float x, float y, float vx):
        width(width), height(height), x(x), y(y), vx(vx){

        shape.setSize(sf::Vector2f(width, height));
        shape.setOrigin(width/2, height/2);
        shape.setPosition(x,y);
        shape.setFillColor(sf::Color::White);
    }

    void moveLeft(){
        x-=vx;  
    }
    void moveRight(){
        x+=vx;
    }

    void clampToBounds(float w){
        if(x - width/2 <= 0){
            // std::cout<<"\tLeft border hit";
            x = width/2;
        }
        else if(x + width/2 >= w){
            // std::cout<<"\tRight border hit";
            x = w - width/2;
        }
    }

    void draw(sf::RenderTarget& target){
        shape.setPosition(x,y);
        target.draw(shape);
    }

    float getX(){return x;}
    float getY(){return y;}
    float getWidth(){return width;}
    float getHeight(){return height;}
};
