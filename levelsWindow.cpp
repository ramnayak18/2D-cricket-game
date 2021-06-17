#include "levelsWindow.h"
levelsWindow::levelsWindow()
{
    std::srand(std::time(0));

    /// setting up background
    this->texturebg.loadFromFile("Background/bg.jpg");
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);

    /// setting up text and tiles
    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    for(int i=0;i<2;i++)
    {
        sectionTile[i] = _tile.getObject();
        sectionTile[i].setPosition(0.f,50.f+600*i);
        section[i].setFont(font);
        section[i].setFillColor(sf::Color::Blue);
        section[i].setCharacterSize(55);
        section[i].setPosition(200.f,100.f+600*i);
    }
    section[0].setString("Level");
    section[1].setString("Overs");
    for(int i=0;i<3;i++)
    {
        levelTile[i] = _tile.getObject();
        levelTile[i].setPosition(1000.f,50.f+200*i);
        level[i].setFont(font);
        level[i].setFillColor(sf::Color::Blue);
        level[i].setCharacterSize(55);
        level[i].setPosition(1200.f,100.f+200*i);
    }
    level[0].setString("Easy");
    level[1].setString("Medium");
    level[2].setString("Hard");
    for(int i=0;i<2;i++)
    {
        oversTile[i] = _tile.getObject();
        oversTile[i].setPosition(1000.f,650.f+200*i);
        overs[i].setFont(font);
        overs[i].setFillColor(sf::Color::Blue);
        overs[i].setCharacterSize(55);
        overs[i].setPosition(1200.f,700.f+200*i);
    }
    overs[0].setString("2");
    overs[1].setString("5");
}

/// resetting default screen
void levelsWindow::reset()
{
    levelTile[0].setFillColor(sf::Color::Red);
    levelTile[0].setOutlineColor(sf::Color::Green);
    levelhover[0] = true;
    for(int i=0;i<2;i++)
    {
        levelTile[i+1].setFillColor(sf::Color::Yellow);
        levelTile[i+1].setOutlineColor(sf::Color::White);
        levelhover[i+1] = false;
        oversTile[i].setFillColor(sf::Color::Yellow);
        oversTile[i].setOutlineColor(sf::Color::White);
        overshover[i] = false;
    }
    levelinit = false;
    event.key.code=sf::Keyboard::Space;
}

/// rendering the graphics on screen
void levelsWindow::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spritebg);
    for(int i=0;i<2;i++)
    {
        window.draw(sectionTile[i]);
        window.draw(levelTile[i]);
        window.draw(oversTile[i]);
        window.draw(section[i]);
        window.draw(level[i]);
        window.draw(overs[i]);
    }
    window.draw(levelTile[2]);
    window.draw(level[2]);
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
}

/// logic for keys pressed for levels
const int levelsWindow::levelLogic(sf::RenderWindow& window)
{
    int i;
    switch(event.key.code)
    {
        case sf::Keyboard::Up:
            for(i=0;i<3;i++)
                if(levelhover[i])
                {
                    levelhover[i] = false;
                    levelTile[i].setOutlineColor(sf::Color::White);
                    levelhover[(i+2)%3] = true;
                    levelTile[(i+2)%3].setOutlineColor(sf::Color::Green);
                    break;
                }
            break;
        case sf::Keyboard::Down:
            for(i=0;i<3;i++)
                if(levelhover[i])
                {
                    levelhover[i] = false;
                    levelTile[i].setOutlineColor(sf::Color::White);
                    levelhover[(i+1)%3] = true;
                    levelTile[(i+1)%3].setOutlineColor(sf::Color::Green);
                    break;
                }
            break;
        case sf::Keyboard::Enter:
            for(i=0;i<3;i++)
            {
                if(levelhover[i])
                {
                    levelTile[0].setFillColor(sf::Color::Yellow);
                    levelTile[i].setFillColor(sf::Color::Red);
                    levelinit = true;
                    oversTile[0].setFillColor(sf::Color::Red);
                    oversTile[0].setOutlineColor(sf::Color::Green);
                    levelTile[i].setOutlineColor(sf::Color::White);
                    overshover[0] = true;
                    event.key.code = sf::Keyboard::Space;
                    render(window);
                    sleep(1);
                    break;
                }
            }
    }
    return i;                
}

/// logic for keys pressed for overs
const int levelsWindow::oversLogic(sf::RenderWindow& window)
{
    int j;
    switch(event.key.code)
    {
        case sf::Keyboard::Up:
        case sf::Keyboard::Down:
            for(j=0;j<2;j++)
            if(overshover[j])
            {
                overshover[j] = false;
                oversTile[j].setOutlineColor(sf::Color::White);
                overshover[(j+1)%2] = true;
                oversTile[(j+1)%2].setOutlineColor(sf::Color::Green);
                if(oversTile[j].getOutlineColor()==sf::Color::White);
                    break;
            }
            break;
        case sf::Keyboard::Enter:
            for(j=0;j<2;j++)
            {
                if(overshover[j])
                {
                    oversTile[0].setFillColor(sf::Color::Yellow);
                    oversTile[j].setFillColor(sf::Color::Red);
                    render(window);
                    sleep(1);
                        break;
                }
            }
    }
    return j;
}

unsigned levelsWindow::call(sf::RenderWindow& window)
{
    int i,j;
    reset();
    while(true)
    {
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed && !levelinit)
                i = levelLogic(window);
            else if(event.type==sf::Event::KeyPressed && levelinit)
            {   
                j = oversLogic(window);
                if(event.key.code==sf::Keyboard::Enter)
                {
                    if(j==0 && i==0)
                        target = rand()%(16-12+1)+12;
                    else if(j==0 && i==1)
                        target = rand()%(20-17+1)+17;
                    else if(j==0 && i==2)
                        target = rand()%(24-21+1)+21;
                    else if(j==1 && i==0)
                        target = rand()%(30-25+1)+25;
                    else if(j==1 && i==1)
                        target = rand()%(40-31+1)+31;
                    else if(j==1 && i==2)
                        target = rand()%(50-41+1)+41;
                    return target;
                }
            }
        }
        render(window);
    }
}