#ifndef _help
#define _help
#include "tile.h"
class helpWindow
{
private:
    /// objects required for window

    sf::Event event;
    
    sf::Sprite spritebg;
    sf::Texture texturebg;

    sf::Text back;
    sf::Font font;

    tile _tile;
    sf::ConvexShape tile_;

public:
    helpWindow();
    void call(sf::RenderWindow& window);
};
#endif