#include "Game.hpp"

Game::Game(
        sf::VideoMode windowSize,
        double ballR,
        double ballV,
        sf::Vector2f paddleSize,
        int blockRows,
        int blockCols,
        int blockHPs
):
    //  Forcing constructors.
    m_paddle(paddleSize.x, paddleSize.y, windowSize.width/2.f, windowSize.height-4*paddleSize.y, 2*ballV)
{
    m_ball = Ball( windowSize.width/2.f, m_paddle.getY()-m_paddle.getHeight()/2-ballR*2,
        rand()%1? ballV : -ballV, -ballV, ballR);
    std::srand(std::time({}));
    
    sf::Vector2f blockSize = sf::Vector2f(windowSize.width/blockCols, windowSize.height/blockRows/4);
    m_bricks.reserve(blockRows*blockCols);
    for(int y = 0; y < blockRows; ++y)
        for(int x = 0; x < blockCols; ++x)
            m_bricks.push_back(Brick(
                blockSize,
                sf::Vector2f(
                    blockSize.x*(x+0.5),
                    windowSize.height/4.f+blockSize.y*(y+0.5)
                ),
                blockHPs
    ));
}

void Game::update(sf::Vector2f windowSize){
    m_paddle.clampToBounds(windowSize.x);
    m_ball.collidePaddle(m_paddle);
    m_ball.collideWall(windowSize.x, windowSize.y);

    for(Brick& b : m_bricks){
        if(m_ball.collideBrick(b))   b.processHit();
        if(b.isDead())
            m_bricks.erase(find(m_bricks.begin(), m_bricks.end(), b));
    }
    m_ball.move();
}
void Game::render(sf::RenderTarget& target){
    for(auto b : m_bricks)
        b.draw(target);
    m_ball.draw(target);
    m_paddle.draw(target);
}
void Game::setState(State state) { this->state = state; }
State Game::getState() { return state; }
int Game::bricksLeft(){ return m_bricks.size(); }
void Game::movePaddleLeft(){ m_paddle.moveLeft(); }
void Game::movePaddleRight(){ m_paddle.moveRight(); }
