#include "libs.hpp"
#include "Ball.hpp"

#define WINDOW_WIDTH    480.f
#define WINDOW_HEIGHT   640.f
#define BALL_R          10.f
#define BALL_V          2.5f
#define BOARD_WIDTH     40.f
#define BOARD_HEIGHT    10.f
#define BOARD_Y         WINDOW_HEIGHT-4*BOARD_HEIGHT
#define BOARD_V         2*BALL_V
#define BLCK_COLS       5.f
#define BLCK_ROWS       4.f
#define BLCK_HPS        4
#define BLCK_WIDTH      WINDOW_WIDTH/BLCK_COLS
#define BLCK_HEIGHT     WINDOW_HEIGHT/8/BLCK_ROWS
#define BLOCKS_HEIGHT   WINDOW_HEIGHT/4


int main(){
    std::srand(std::time({}));
    Ball ball = Ball(WINDOW_WIDTH/2, BOARD_Y-BOARD_HEIGHT/2-BALL_R*2, rand()%1? BALL_V : -BALL_V, -BALL_V, BALL_R);
    Paddle paddle = Paddle(BOARD_WIDTH, BOARD_HEIGHT, WINDOW_WIDTH/2, BOARD_Y, BOARD_V);

    std::vector<Brick> bricks;
    bricks.reserve(BLCK_ROWS*BLCK_COLS);
    for(int y = 0; y < BLCK_ROWS; ++y)
        for(int x = 0; x < BLCK_COLS; ++x)
            bricks.push_back(Brick(
                sf::Vector2f(BLCK_WIDTH, BLCK_HEIGHT),
                sf::Vector2f(
                    BLCK_WIDTH*(x+0.5),
                    BLOCKS_HEIGHT+BLCK_HEIGHT*(y+0.5)
                ),
                BLCK_HPS
            ));



    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ARCANOID",
                            sf::Style::Close || sf::Style::Titlebar);
    // window.setVerticalSyncEnabled(true);

    while(window.isOpen()){
        //  Standard 2.6 window closed check.
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //  Check for pressed keys.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            paddle.moveLeft();
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            paddle.moveRight();
        //  Check for pressed keys end.
        //  Logical checks.
        if(!bricks.size())  break;
        paddle.clampToBounds(WINDOW_WIDTH);
        ball.collidePaddle(paddle);
        ball.collideWall(WINDOW_WIDTH, WINDOW_HEIGHT);
        for(Brick& b : bricks){
            if(ball.collideBrick(b))   b.processHit();
            if(b.isDead())
                bricks.erase(find(bricks.begin(), bricks.end(), b));
        }
        //  Logical checks end.
        //  Game actions.
        ball.move();
        //  Game actions end.
        // if(paddle.getX() < ball.getX())
            // paddle.moveRight();
        // else
            // paddle.moveLeft();

        window.clear();
        for(auto b : bricks)
            b.draw(window);
        ball.draw(window);
        paddle.draw(window);
        //  Game actions.
        window.display();
    }

    return EXIT_SUCCESS;
}
