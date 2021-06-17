#ifndef LEVELSWINDOW_H
#define LEVELSWINDOW_H
#include <unistd.h>
#include <iostream>
#include "tile.h"
#include <cstdlib>
#include <ctime>
class levelsWindow
{
private:
    sf::Event event;
    sf::Font font;
    sf::Text section[2];
    sf::Text level[3];
    sf::Text overs[2];
    sf::ConvexShape sectionTile[2];
    sf::ConvexShape oversTile[2];
    sf::ConvexShape levelTile[3];
    sf::Sprite spritebg;
    sf::Texture texturebg;
    tile _tile;

    /// logic variables
    bool levelhover[3];
    bool overshover[2];
    bool levelinit;
    unsigned target;

public:
    levelsWindow();
    void reset();
    const int levelLogic(sf::RenderWindow& window);
    const int oversLogic(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    unsigned call(sf::RenderWindow& window);
};
#endif