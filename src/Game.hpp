#ifndef GAME_HPP
#define GAME_HPP
#include "libs.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

#define WINDOW_WIDTH    480.f
#define WINDOW_HEIGHT   640.f
#define BALL_R          10.f
#define BALL_V          2.5f
#define PADDLE_WIDTH     40.f
#define PADDLE_HEIGHT    10.f
#define PADDLE_Y         WINDOW_HEIGHT-4*PADDLE_HEIGHT
#define PADDLE_V         2*BALL_V
#define BLCK_COLS       5.f
#define BLCK_ROWS       4.f
#define BLCK_HPS        4
#define BLCK_WIDTH      WINDOW_WIDTH/BLCK_COLS
#define BLCK_HEIGHT     WINDOW_HEIGHT/4/BLCK_ROWS
#define BLOCKS_Y        WINDOW_HEIGHT/4
#define FRAMERATE       5000
enum class State{ Menu, Playing, Paused, Won, Lost };

class Game{
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;
    Paddle m_paddle;
    Ball m_ball;
    std::vector<Brick> m_bricks;
    State state;
    int framerate;

public:
    Game(
        sf::VideoMode windowSize = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        double ballR = BALL_R, 
        double ballV = BALL_V, 
        sf::Vector2f paddleSize = sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT),
        double paddleY = PADDLE_Y,
        double paddleV = PADDLE_V,
        int blockRows = BLCK_ROWS,
        int blockCols = BLCK_COLS,
        int blockHPs = BLCK_HPS,
        sf::Vector2f blockSize = sf::Vector2f(BLCK_WIDTH, BLCK_HEIGHT),
        double blocksY = BLOCKS_Y,
        int framerate = FRAMERATE
    );
    void run(); //  while(window.isOpen)
    void procesEvents();    //  window.pollEvent()
    void update(sf::Time dt); //    game logic and collisions.
    void render();          //  window.clear(), draw(), display()
};
#endif

