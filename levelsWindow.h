#ifndef _LEVELS_WINDOW_H
#define _LEVELS_WINDOW_H
#include <unistd.h>
#include <iostream>
#include "objects.h"
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
    sf::Sprite spritebg;
    sf::Texture texturebg;
    tile* _sectionTile[2];
    tile* _levelTile[3];
    tile* _oversTile[2];

    /// logic variables
    bool levelhover[3];
    bool overshover[2];
    bool levelinit;
    unsigned target;
    unsigned Overs;
    unsigned arr[2];
public:
    levelsWindow();
    void reset();
    const int levelLogic(sf::RenderWindow& window);
    const int oversLogic(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    unsigned* call(sf::RenderWindow& window);
};
#endif