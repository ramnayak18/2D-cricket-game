#include "menuWindow.h"
#include <iostream>
#include <unistd.h>
menuWindow::menuWindow()
{
    /// setting up menu background
    this->texturebg.loadFromFile("Background/menubg.jpg");
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);

    /// setting up text and tiles
    this->font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    this->text[0].setString("Play");
    this->text[1].setString("Help");
    this->text[2].setString("About");
    this->text[3].setString("Close");
    for(int i=0;i<4;i++)
    {
        this->text[i].setCharacterSize(55);
        this->text[i].setFillColor(sf::Color::Blue);
        this->text[i].setFont(this->font);
        this->text[i].setPosition(700.f,300.f+200*i);
        tile_[i] = _tile.getObject();
        tile_[i].setPosition(500.f,250.f+200*i);
    }
}

/// resetting screen to original condition
void menuWindow::reset()
{
    tile_[0].setFillColor(sf::Color::Red);
    tile_[0].setOutlineColor(sf::Color::Green);
    hover[0] = true;
    for(int i=1;i<4;i++)
    {
        hover[i] = false;
        tile_[i].setFillColor(sf::Color::Yellow);
        tile_[i].setOutlineColor(sf::Color::White);
    }
    event.key.code = sf::Keyboard::Space;
}

/// function to render graphics on screen
void menuWindow::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spritebg);
    for(int i=0;i<4;i++)
    {
        window.draw(tile_[i]);
        window.draw(text[i]);
    }
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
}

jump_t menuWindow::call(sf::RenderWindow& window)
{
    int i;
    reset();
    while(true)
    {
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Up: 
                        for(i=0;i<4;i++)
                            if(hover[i])
                            {
                                hover[i] = false;
                                tile_[i].setOutlineColor(sf::Color::White);
                                hover[(i+3)%4] = true;
                                tile_[(i+3)%4].setOutlineColor(sf::Color::Green);
                                break;
                            }
                        break;
                    case sf::Keyboard::Down:
                        for(i=0;i<4;i++)
                            if(hover[i])
                            {
                                hover[i] = false;
                                tile_[i].setOutlineColor(sf::Color::White);
                                hover[(i+1)%4] = true;
                                tile_[(i+1)%4].setOutlineColor(sf::Color::Green);
                                break;
                            }
                        break;
                    case sf::Keyboard::Enter:
                        for(i=0;i<4;i++)
                        {
                            if(hover[i])
                            {
                                tile_[0].setFillColor(sf::Color::Yellow);
                                tile_[i].setFillColor(sf::Color::Red);
                                break;
                            }
                        }
                }
            }
            render(window);
            if(event.key.code==sf::Keyboard::Enter)
            {
                sleep(1);
                if(text[i].getString()=="Play")
                    return jump_t::LEVELS;
                if(text[i].getString()=="Close")
                    return jump_t::CLOSE;
                if(text[i].getString()=="Help")
                    return jump_t::HELP;
                if(text[i].getString()=="About")
                    return jump_t::ABOUT;
            }
        }
    }
}