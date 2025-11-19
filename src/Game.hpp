#ifndef GAME_HPP
#define GAME_HPP
#include "libs.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

#define BALL_R          10.f
#define BALL_V          2.5f
#define PADDLE_WIDTH     40.f
#define PADDLE_HEIGHT    10.f
#define BLCK_COLS       5.f
#define BLCK_ROWS       4.f
#define BLCK_HPS        4

class Game{
    sf::Clock m_deltaClock;
    Paddle m_paddle;
    Ball m_ball;
    std::vector<Brick> m_bricks;
    int framerate;

public:
    Game(
        sf::VideoMode windowSize,
        double ballR = BALL_R, 
        double ballV = BALL_V, 
        sf::Vector2f paddleSize = sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT),
        int blockRows = BLCK_ROWS,
        int blockCols = BLCK_COLS,
        int blockHPs = BLCK_HPS
    );

    void update(sf::Vector2f windowSize);
    void render(sf::RenderTarget& target);

    int bricksLeft();   //  This used to look so good in an unseparated class!
    void movePaddleLeft();
    void movePaddleRight();
};
#endif

