#ifndef MENU_HPP
#define MENU_HPP

#include "libs.hpp"
#include <SFML/Graphics/Font.hpp>
#include <string>

enum class Option { Start, Options, Exit };

class Menu{
    Option currentOption;
    std::string fontpath;
    static sf::Font font;
    int fontsize;
    sf::Text textStart;
    sf::Text textOptions;
    sf::Text textExit;

    void setOption(Option opt);

public:
    Menu(std::string fontpath, int fontsize);
    void moveUp();
    void moveDown();
    Option getOption();
    void render(sf::RenderTarget& target);
};


#endif
