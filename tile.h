#ifndef _Tile
#define _Tile
#include "SFML/Graphics.hpp"
class tile
{
    sf::ConvexShape tiles;
    public:
    /// initialise tile
    tile();
    /// function to return tile 
    sf::ConvexShape getObject();
};
#endif