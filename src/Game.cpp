#include "Game.hpp"
#include <iostream>

Game::Game(
        sf::VideoMode windowSize,
        double ballR,
        double ballV,
        sf::Vector2f paddleSize,
        double paddleY,
        double paddleV,
        int blockRows,
        int blockCols,
        int blockHPs,
        sf::Vector2f blockSize,
        double blocksY,
        int framerate
):
    state(State::Playing),
    framerate(framerate),
    //  Forcing constructors.
    m_window(windowSize, "ARCANOID", sf::Style::Close || sf::Style::Titlebar),
    m_ball( windowSize.width/2.f, paddleY-paddleSize.y/2-ballR*2,
        rand()%1? ballV : -ballV, -ballV, ballR),
    m_paddle(paddleSize.x, paddleSize.y, windowSize.width/2.f, paddleY, paddleV)
{
    std::srand(std::time({}));
    
    m_bricks.reserve(blockRows*blockCols);
    for(int y = 0; y < blockRows; ++y)
        for(int x = 0; x < blockCols; ++x)
            m_bricks.push_back(Brick(
                blockSize,
                sf::Vector2f(
                    blockSize.x*(x+0.5),
                    blocksY+blockSize.y*(y+0.5)
                ),
                blockHPs
    ));
}

void Game::run(){
    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                m_window.close();
        }
        update(sf::milliseconds(1000.f/framerate));
        render();
    }
}
void Game::update(sf::Time dt){
    sf::sleep(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        state == State::Paused? state =  State::Playing: state = State::Paused;
    if(state == State::Paused) return;
    if(!m_bricks.size())  state = State::Won;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_paddle.moveLeft();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_paddle.moveRight();
       

    m_paddle.clampToBounds(m_window.getSize().x);
    m_ball.collidePaddle(m_paddle);
    m_ball.collideWall(m_window.getSize().x, m_window.getSize().y);
    for(Brick& b : m_bricks){
        if(m_ball.collideBrick(b))   b.processHit();
        if(b.isDead())
            m_bricks.erase(find(m_bricks.begin(), m_bricks.end(), b));
    }
    
    m_ball.move();
}
void Game::render(){
    m_window.clear();
    for(auto b : m_bricks)
        b.draw(m_window);
    m_ball.draw(m_window);
    m_paddle.draw(m_window);
    m_window.display();
}
