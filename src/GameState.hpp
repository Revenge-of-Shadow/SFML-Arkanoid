#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "libs.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include <SFML/System/Vector2.hpp>
#include <tuple>

class GameState{
    Paddle paddle; 
    Ball ball; 
    std::vector<Brick> bricks; 

public:
    GameState();
    GameState(Paddle&, Ball&, std::vector<Brick>&);
    
    void capture(Paddle&, Ball&, std::vector<Brick>&);
    bool saveToFile(const std::string filename);
    bool loadFromFile(const std::string filename);
    void apply(Paddle&, Ball&, std::vector<Brick>&);

    Paddle getPaddle() const;
    Ball getBall() const;
    std::vector<Brick> getBricks() const;
};

#endif
