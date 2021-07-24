#include "helpWindow.h"
#include <iostream>
/// @file helpWindow.cpp
/// @brief implements the functionalities and event loop of "Help" window

helpWindow::helpWindow()
{
    if(!this->texturebg.loadFromFile("Background/helpbg.jpg"));
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);

    tile_ = _tile.getObject();
    tile_.setScale(0.7f,0.7f);
    tile_.setPosition(1500.f,952.f);
    tile_.setOutlineColor(sf::Color::Green);
    tile_.setFillColor(sf::Color::Red);

    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    back.setFillColor(sf::Color::Blue);
    back.setString("Back(Esc)");
    back.setCharacterSize(38);
    back.setFont(font);
    back.setPosition(1580.f,976.f);
}
void helpWindow::call(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spritebg);
    window.draw(tile_);
    window.draw(back);
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
    event.key.code = sf::Keyboard::Space;
    while(true)
    {
        if(window.pollEvent(this->event))
        if(this->event.type==sf::Event::KeyPressed && this->event.key.code==sf::Keyboard::Escape)
            break;          
    }
}