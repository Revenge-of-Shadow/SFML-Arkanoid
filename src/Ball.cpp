#include "Ball.hpp"
Ball::Ball(){}
Ball::Ball(float startX, float startY, float vX, float vY, float r):
    x(startX), y(startY), vX(vX), vY(vY), r(r){
    shape.setRadius(r);
    shape.setPosition(x,y);
    shape.setOrigin(r,r);
    shape.setFillColor(sf::Color::Cyan);

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
bool Ball::collideBrick(Brick& b){
    bool vert = false;
    bool horiz = false;
    bool bounced = false;

    do {
        vert = (y-r <= b.getPosition().y+b.getSize().y/2
            &&  y+r >= b.getPosition().y-b.getSize().y/2);
        horiz = (x+r >= b.getPosition().x-b.getSize().x/2 
            && x-r <= b.getPosition().x+b.getSize().x/2);
        if(vert&&horiz){
            if(!bounced){
                bounceY();
                bounceX();
                bounced = true;
            }
            else
                move();
        }
    }
    while(vert&&horiz);
    if(!bounced)return false;
    else if(!vert)   bounceX();
    else        bounceY();

    return true;
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

Ball* Ball::operator*(){ return this; }
Ball& Ball::operator=(const Ball& other){
    if(this != &other){
        this->x = other.x; 
        this->y = other.y; 
        this->vX = other.vX;
        this->vY = other.vY;
        this->r = other.r;

        shape.setRadius(r);
        shape.setPosition(x,y);
        shape.setOrigin(r,r);
        shape.setFillColor(sf::Color::Cyan);
    }
    return *this;
}
