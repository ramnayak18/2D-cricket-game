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
        sectionTile.push_back(_tile.getObject());
        sectionTile.at(i).setPosition(0.f,50.f+600*i);
        section[i].setFont(font);
        section[i].setFillColor(sf::Color::Blue);
        section[i].setCharacterSize(55);
        section[i].setPosition(200.f,100.f+600*i);
    }
    section[0].setString("Level");
    section[1].setString("Overs");
    for(int i=0;i<3;i++)
    {
        levelTile.push_back(_tile.getObject());
        levelTile.at(i).setPosition(1000.f,50.f+200*i);
        level[i].setFont(font);
        level[i].setFillColor(sf::Color::Blue);
        level[i].setCharacterSize(55);
        level[i].setPosition(1200.f,100.f+200*i);
        levelhover.push_back(false);
    }
    level[0].setString("Easy");
    level[1].setString("Medium");
    level[2].setString("Hard");
    for(int i=0;i<2;i++)
    {
        oversTile.push_back(_tile.getObject());
        oversTile.at(i).setPosition(1000.f,650.f+200*i);
        overs[i].setFont(font);
        overs[i].setFillColor(sf::Color::Blue);
        overs[i].setCharacterSize(55);
        overs[i].setPosition(1200.f,700.f+200*i);
        overshover.push_back(false);
    }
    overs[0].setString("2");
    overs[1].setString("5");
}

/// resetting default screen
void levelsWindow::reset()
{
    levelTile.at(0).setFillColor(sf::Color::Red);
    levelTile.at(0).setOutlineColor(sf::Color::Green);
    levelhover.at(0) = true;
    for(int i=0;i<2;i++)
    {
        levelTile.at(i+1).setFillColor(sf::Color::Yellow);
        levelTile.at(i+1).setOutlineColor(sf::Color::White);
        levelhover.at(i+1) = false;
        oversTile.at(i).setFillColor(sf::Color::Yellow);
        oversTile.at(i).setOutlineColor(sf::Color::White);
        overshover.at(i) = false;
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
        window.draw(sectionTile.at(i));
        window.draw(levelTile.at(i));
        window.draw(oversTile.at(i));
        window.draw(section[i]);
        window.draw(level[i]);
        window.draw(overs[i]);
    }
    window.draw(levelTile.at(2));
    window.draw(level[2]);
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
}

/// logic for keys pressed for levels
const int levelsWindow::levelLogic(sf::RenderWindow& window)
{
    int i = nav.navigate(event,3,levelhover,levelTile);
    if(event.key.code == sf::Keyboard::Enter)
    {
        render(window);
        sleep(1);
        levelinit = true;
        oversTile.at(0).setFillColor(sf::Color::Red);
        oversTile.at(0).setOutlineColor(sf::Color::Green);
        levelTile.at(i).setOutlineColor(sf::Color::White);
        overshover.at(0) = true;
        event.key.code = sf::Keyboard::Space;
        render(window);
    }
    return i;                
}

/// logic for keys pressed for overs
const int levelsWindow::oversLogic(sf::RenderWindow& window)
{
    int j = nav.navigate(event,2,overshover,oversTile);
    if(event.key.code == sf::Keyboard::Enter)
    {
        render(window);
        sleep(1);
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