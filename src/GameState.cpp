#include "GameState.hpp"

GameState::GameState(){}

GameState::GameState(Paddle& p, Ball& b, std::vector<Brick>& bricks)
:paddle(p), ball(b), bricks(bricks){ }

void GameState::capture(Paddle& p, Ball& b, std::vector<Brick>& bricks){
    this->paddle = p;
    this->ball = b;
    this->bricks = bricks;
}

bool GameState::saveToFile(const std::string filename){
    std::ofstream file(filename);
    if(!file.is_open()) return false;

    file<<paddle.x<<' '<<paddle.y<<' '<<paddle.vx<<' '<<paddle.width<<' '<<paddle.height<<'\n';
    file<<ball.x<<' '<<ball.y<<' '<<ball.vX<<' '<<ball.vY<<' '<<ball.r<<'\n';

    file<<bricks.size()<<'\n';

    for(const Brick& brick : bricks){
        file<<brick.getPosition().x<<
            ' '<<brick.getPosition().y<<
            ' '<<brick.getSize().x<<
            ' '<<brick.getSize().y<<
            ' '<<brick.getMaxHP()<<
            ' '<<brick.getHP()<<'\n';
    }
    file.close();
    return true;
}

bool GameState::loadFromFile(const std::string filename){
    std::ifstream file(filename);
    if(!file.is_open()) return false;

    file>>paddle.x>>paddle.y>>paddle.vx>>paddle.width>>paddle.height;
    file>>ball.x>>ball.y>>ball.vX>>ball.vY>>ball.r;
    
    int bsize;

    file>>bsize;

    bricks.erase(bricks.begin(), bricks.end());

    for(int i = 0; i<bsize; ++i){
        int mhp, hp;
        sf::Vector2f pos;
        sf::Vector2f size;
        file>>pos.x>>pos.y>>size.x>>size.y>>mhp>>hp;
        Brick br(size, pos, mhp);
        while(br.getHP() > hp)  br.processHit();
        bricks.push_back(br);
    }

    return true;
}

void GameState::apply(Paddle &p, Ball &b, std::vector<Brick> &bricks){
    p = this->paddle;
    b = this->ball;
    bricks = this->bricks;
}
