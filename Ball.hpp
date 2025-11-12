
#include "Paddle.hpp"

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
    void draw(sf::RenderTarget& target);

    float getX();
    float getVX();
    float getY();
    float getVY();
    float getR();
};


Ball::Ball(float startX, float startY, float vX, float vY, float r):
    x(startX), y(startY), vX(vX), vY(vY), r(r){
    shape.setRadius(r);
    shape.setPosition(x,y);
    shape.setOrigin(r,r);
    shape.setFillColor(sf::Color::Green);

}

void Ball::move(){
    x+=vX;
    y+=vY;
}
void Ball::bounceX(){
    vX=-vX;
}
void Ball::bounceY(){
    vY=-vY;
}
void Ball::collideWall(float w, float h){
    if(x+r>w || x-r<0)
        bounceX();
    else if(y+r>h || y-r<0)
        bounceY();
}

bool Ball::collidePaddle(Paddle& p){
    bool result = false;
    if(y > p.getY())    return result;   //  Just a bit harder.
    
    while(y-r <= p.getY()+p.getHeight()/2
        &&  y+r >= p.getY()-p.getHeight()/2
        && x+r >= p.getX()-p.getWidth()/2 
        && x-r <= p.getX()+p.getWidth()/2){
        if(!result){
            bounceY();
            result = true;
        }
        move();
    }
    return result;
}

void Ball::draw(sf::RenderTarget& target){
    shape.setPosition(x,y);
    target.draw(shape);
}

float Ball::getX(){
    return x;
}
float Ball::getY(){
    return y;
}
float Ball::getVX(){
    return vX;
}
float Ball::getVY(){
    return vY;
}
float Ball::getR(){
    return r;
}

