#include "Paddle.hpp"

Paddle::Paddle(float width, float height, float x, float y, float vx):
    width(width), height(height), x(x), y(y), vx(vx){

    shape.setSize(sf::Vector2f(width, height));
    shape.setOrigin(width/2, height/2);
    shape.setPosition(x,y);
    shape.setFillColor(sf::Color::White);
}

void Paddle::moveLeft(){
    x-=vx;  
}
void Paddle::moveRight(){
    x+=vx;  
}
void Paddle::clampToBounds(float w){
    if(x - width/2 <= 0){
        x = width/2;
    }
    else if(x + width/2 >= w){
        x = w - width/2;
    }
}
void Paddle::draw(sf::RenderTarget& target){
    shape.setPosition(x,y);
    target.draw(shape);
}

float Paddle::getX(){return x;}
float Paddle::getY(){return y;}
float Paddle::getWidth(){return width;}
float Paddle::getHeight(){return height;}
