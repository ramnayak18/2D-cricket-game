#include "helpWindow.h"
#include <iostream>
helpWindow::helpWindow()
{
    /// setting up help background
    if(!this->texturebg.loadFromFile("Background/helpbg.jpg"));
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);

    /// setting up back button
    tile_ = _tile.getObject();
    tile_.setPosition(1300.f,900.f);
    tile_.setOutlineColor(sf::Color::Green);
    tile_.setFillColor(sf::Color::Red);

    /// setting up "back" text
    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    back.setFillColor(sf::Color::Blue);
    back.setString("Back(Esc)");
    back.setCharacterSize(55);
    back.setFont(font);
    back.setPosition(1400.f,950.f);
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