#include "levelsWindow.h"
/// @file levelsWindow.cpp
/// @brief implements the functionalities and event loop of "Levels" window
levelsWindow::levelsWindow()
{
    std::srand(std::time(0));

    this->texturebg.loadFromFile("Background/bg.jpg");
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);

    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    section[0].setString("Level");
    section[1].setString("Overs");
    for(int i=0;i<2;i++)
    {
        _sectionTile[i] = new tile();
        _sectionTile[i]->tiles.setPosition(0.f,50.f+600*i);
        section[i].setFont(font);
        section[i].setFillColor(sf::Color::Blue);
        section[i].setCharacterSize(55);
        section[i].setPosition(200.f,100.f+600*i);
        _sectionTile[i]->text = section[i];
    }
    level[0].setString("Easy");
    level[1].setString("Medium");
    level[2].setString("Hard");
    for(int i=0;i<3;i++)
    {
        _levelTile[i] = new tile();
        _levelTile[i]->tiles.setPosition(1000.f,50.f+200*i);
        level[i].setFont(font);
        level[i].setFillColor(sf::Color::Blue);
        level[i].setCharacterSize(55);
        level[i].setPosition(1200.f,100.f+200*i);
        _levelTile[i] -> text = level[i];
    }
    overs[0].setString("2");
    overs[1].setString("5");
    for(int i=0;i<2;i++)
    {
        _oversTile[i] = new tile();
        _oversTile[i]->tiles.setPosition(1000.f,650.f+200*i);
        overs[i].setFont(font);
        overs[i].setFillColor(sf::Color::Blue);
        overs[i].setCharacterSize(55);
        overs[i].setPosition(1200.f,700.f+200*i);
        _oversTile[i]->text = overs[i];
    }
}

void levelsWindow::reset()
{
    _levelTile[0]->tiles.setFillColor(sf::Color::Red);
    _levelTile[0]->tiles.setOutlineColor(sf::Color::Green);
    _levelTile[0]->state = "Hover";
    for(int i=0;i<2;i++)
    {
        _levelTile[i+1]->tiles.setFillColor(sf::Color::Yellow);
        _levelTile[i+1]->tiles.setOutlineColor(sf::Color::White);
        _levelTile[i+1]->state = "NULL";
        _oversTile[i]->tiles.setFillColor(sf::Color::Yellow);
        _oversTile[i]->tiles.setOutlineColor(sf::Color::White);
        _oversTile[i]->state = "NULL";
    }
    levelinit = false;
    event.key.code=sf::Keyboard::Space;
}

void levelsWindow::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(spritebg);
    for(int i=0;i<2;i++)
    {
        window.draw(_sectionTile[i]->tiles);
        window.draw(_levelTile[i]->tiles);
        window.draw(_oversTile[i]->tiles);
        window.draw(_sectionTile[i]->text);
        window.draw(_levelTile[i]->text);
        window.draw(_oversTile[i]->text);
    }
    window.draw(_levelTile[2]->tiles);
    window.draw(_levelTile[2]->text);
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
}

const int levelsWindow::levelLogic(sf::RenderWindow& window)
{
    int i;
    i = _levelTile[0]->update(_levelTile,3,event);
    if(event.key.code == sf::Keyboard::Enter)
    {
        levelinit = true;
        _oversTile[0]->tiles.setFillColor(sf::Color::Red);
        _oversTile[0]->tiles.setOutlineColor(sf::Color::Green);
        _levelTile[i]->tiles.setOutlineColor(sf::Color::White);
        _oversTile[0]->state = "Hover";
        event.key.code = sf::Keyboard::Space;
        render(window);
        sleep(1);
    }
    return i;                
}

const int levelsWindow::oversLogic(sf::RenderWindow& window)
{
    int j;
    j = _oversTile[0]->update(_oversTile,2,event);
    if(event.key.code == sf::Keyboard::Enter)
    {
        render(window);
        sleep(1);
    }
    return j;
}

unsigned* levelsWindow::call(sf::RenderWindow& window)
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
                    if(j==0 && i==0){
                        target = rand()%(16-12+1)+12;
                        Overs = 2;}
                    else if(j==0 && i==1){
                        target = rand()%(20-17+1)+17;
                        Overs = 2;}
                    else if(j==0 && i==2){
                        target = rand()%(24-21+1)+21;
                        Overs = 2;}
                    else if(j==1 && i==0){
                        target = rand()%(30-25+1)+25;
                        Overs = 5;}
                    else if(j==1 && i==1){
                        target = rand()%(40-31+1)+31;
                        Overs = 5;}
                    else if(j==1 && i==2){
                        target = rand()%(50-41+1)+41;
                        Overs = 5;}
                    arr[0] = target;
                    arr[1] = Overs;
                    return arr;
                }
            }
        }
        render(window);
    }
}