#ifndef _Batsman
#define _Batsman
#include <SFML/Graphics.hpp>
#include <iostream>
class batsman
{
    sf::Sprite spritebatsman;
    sf::Texture texturebatsman;
    public:
    /// initialise sprite
    batsman();
    /// function to return batsman 
    sf::Sprite getObject();
};
#endif