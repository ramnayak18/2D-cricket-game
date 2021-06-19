#ifndef _Messages
#define _Messages
#include "tile.h"
class messagesWindow
{
private:
    /// objects required for window

    sf::Event event;
    
    sf::Sprite Wlcmsprite;
    sf::Texture Wlcmtexture;

    sf::Text cont;
    sf::Font font;

    tile _tile;
    sf::ConvexShape tile_;

public:
    messagesWindow();
    void call(sf::RenderWindow& window);
};
#endif