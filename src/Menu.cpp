#include "Menu.hpp"
#include <SFML/Graphics/CircleShape.hpp>
sf::Font Menu::font;
Menu::Menu(std::string fontpath, int fontsize = 24){
    currentOption = Option::Start;
    this->fontpath = fontpath;
    font.loadFromFile(this->fontpath);

    textStart = sf::Text("> Start", font, fontsize);
    textOptions = sf::Text("Options", font, fontsize);
    textExit = sf::Text("Exit", font, fontsize);
}
void Menu::moveUp(){
    switch (currentOption) {
        case Option::Start: 
            setOption(Option::Exit);
            break;
        case Option::Options: 
            setOption(Option::Start);
            break;
        case Option::Exit: 
            setOption(Option::Options);
            break;
    }
}
void Menu::moveDown(){
    switch (currentOption) {
        case Option::Start: 
            setOption(Option::Options);
            break;
        case Option::Options: 
            setOption(Option::Exit);
            break;
        case Option::Exit: 
            setOption(Option::Start);
            break;
    }
}
Option Menu::getOption(){ return currentOption; }
void Menu::setOption(Option opt){ 
    currentOption = opt; 
    
    switch (currentOption) {
        case Option::Start: 
            textStart.setString("> Start");
            textOptions.setString("Options");
            textExit.setString("Exit");
            break;
        case Option::Options: 
            textStart.setString("Start");
            textOptions.setString("> Options");
            textExit.setString("Exit");
            break;
        case Option::Exit: 
            textStart.setString("Start");
            textOptions.setString("Options");
            textExit.setString("> Exit");
            break;
    }
}
void Menu::render(sf::RenderTarget& target){
    textStart.setPosition(target.getSize().x/5.f, target.getSize().y/5.f*2.f);
    textOptions.setPosition(target.getSize().x/5.f, target.getSize().y/5.f*3.f);
    textExit.setPosition(target.getSize().x/5.f, target.getSize().y/5.f*4.f);
    
    target.draw(textStart);
    target.draw(textOptions);
    target.draw(textExit);
}
