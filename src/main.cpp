#include "Game.hpp"

#define WINDOW_WIDTH    480.f
#define WINDOW_HEIGHT   640.f
#define FRAMERATE       500

int main(){
    sf::RenderWindow m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ARKANOID", sf::Style::Close || sf::Style::Titlebar);

    Game game(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT));
    game.setState(State::Playing);

    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                m_window.close();
        }
        sf::sleep(sf::milliseconds(1000/FRAMERATE));
        m_window.clear();

        switch (game.getState()) {
            case State::Menu:
                break;
            case State::Playing:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    game.setState(State::Paused);
                    sf::sleep(sf::milliseconds(500));
                }
                else{
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                            game.movePaddleLeft();
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                            game.movePaddleRight();
                    if(!game.bricksLeft())  game.setState(State::Won);
                    
                    game.update(sf::Vector2f(m_window.getSize()));
                    game.render(m_window);
                }
                break;
            case State::Paused:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    game.setState(State::Playing);
                    sf::sleep(sf::milliseconds(500));
                }
                game.render(m_window);
                break;
            case State::Won:
                break;
            case State::Lost:
                break;
        }
        m_window.display();
    }
    return EXIT_SUCCESS;
}
