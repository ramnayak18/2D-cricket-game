#ifndef LEVELSWINDOW_H
#define LEVELSWINDOW_H
#include <unistd.h>
#include <iostream>
#include "tile.h"
#include "navAdapter.h"
#include <cstdlib>
#include <ctime>
#include <vector>
class levelsWindow
{
private:
    sf::Event event;
    sf::Font font;
    sf::Text section[2];
    sf::Text level[3];
    sf::Text overs[2];
    std::vector<sf::ConvexShape> sectionTile;
    std::vector<sf::ConvexShape> oversTile;
    std::vector<sf::ConvexShape> levelTile;
    sf::Sprite spritebg;
    sf::Texture texturebg;
    tile _tile;

    /// logic variables
    std::vector<bool> levelhover;
    std::vector<bool> overshover;
    bool levelinit;
    unsigned target;
    navAdapter nav;

public:
    levelsWindow();
    void reset();
    const int levelLogic(sf::RenderWindow& window);
    const int oversLogic(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    unsigned call(sf::RenderWindow& window);
};
#endif