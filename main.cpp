#include <SFML/Graphics.hpp>

#include "Ball.h"

#define WINDOW_WIDTH    480.f
#define WINDOW_HEIGHT   640.f
#define BALL_R          10.f
#define BALL_V          2.5f
#define BOARD_WIDTH     40.f
#define BOARD_HEIGHT    10.f
#define BOARD_Y         WINDOW_HEIGHT-4*BOARD_HEIGHT
#define BOARD_V         2*BALL_V


int main(){
    std::srand(std::time({}));
    Ball ball = Ball(WINDOW_WIDTH/2, BOARD_Y-BOARD_HEIGHT/2-BALL_R*2, rand()%1? BALL_V : -BALL_V, -BALL_V, BALL_R);
    Paddle paddle = Paddle(BOARD_WIDTH, BOARD_HEIGHT, WINDOW_WIDTH/2, BOARD_Y, BOARD_V);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ARCANOID",
                            sf::Style::Close || sf::Style::Titlebar);
    window.setVerticalSyncEnabled(true);

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
        paddle.clampToBounds(WINDOW_WIDTH);
        ball.collidePaddle(paddle);
        ball.collideWall(WINDOW_WIDTH, WINDOW_HEIGHT);
        //  Logical checks end.
        //  Game actions.
        ball.move();
        //  Game actions end.
        // if(paddle.getX() < ball.getX())
            // paddle.moveRight();
        // else
            // paddle.moveLeft();

        window.clear();
        paddle.draw(window);
        ball.draw(window);
        //  Game actions.
        window.display();
    }

    return EXIT_SUCCESS;
}
