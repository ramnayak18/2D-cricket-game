#ifndef _ABOUT
#define _ABOUT
#include "tile.h"
class aboutWindow
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
    aboutWindow();
    void call(sf::RenderWindow& window);
};
#endif