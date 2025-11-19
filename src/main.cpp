#include "Game.hpp"
#include "Menu.hpp"
#include <SFML/Window/Keyboard.hpp>

#define WINDOW_WIDTH    480.f
#define WINDOW_HEIGHT   640.f
#define FRAMERATE       50
enum class State{ Menu, Playing, Paused, Won, Lost };

int main(){
    sf::RenderWindow m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ARKANOID", sf::Style::Close || sf::Style::Titlebar);

    Game game(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT));
    State state = State::Menu;
    Menu menu("./orbitron-latin-800-normal.ttf", 24);

    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                m_window.close();
        }
        sf::sleep(sf::milliseconds(1000/FRAMERATE));
        m_window.clear();

        switch (state) {
            case State::Menu:
                sf::sleep(sf::milliseconds(1000/FRAMERATE*10));
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                    || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    menu.moveDown();
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                    || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    menu.moveUp();
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                        {
                            switch (menu.getOption()) {
                                case Option::Start:
                                    state=State::Playing;
                                    break;
                                case Option::Options:
                                    break;
                                case Option::Exit:
                                    m_window.close();
                                    break;
                            }
                        }

                menu.render(m_window);
                break;
            case State::Playing:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    state = State::Paused;
                    sf::sleep(sf::milliseconds(500));
                }
                else{
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                            game.movePaddleLeft();
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                            game.movePaddleRight();
                    if(!game.bricksLeft())  state = State::Won;
                    
                    game.update(sf::Vector2f(m_window.getSize()));
                    game.render(m_window);
                }
                break;
            case State::Paused:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    state = State::Playing;
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
