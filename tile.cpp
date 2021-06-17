#include "tile.h"
tile::tile()
{
    /// initialising the tile
    tiles.setPointCount(4);
    tiles.setPoint(0,sf::Vector2f(0.f,0.f));
    tiles.setPoint(1,sf::Vector2f(500.f,0.f));
    tiles.setPoint(2,sf::Vector2f(450.f,150.f));
    tiles.setPoint(3,sf::Vector2f(0.f,150.f));
    tiles.setFillColor(sf::Color(255,215,0));
    tiles.setOutlineColor(sf::Color::White);
    tiles.setOutlineThickness(20.f);
}
sf::ConvexShape tile::getObject()
{
    return this->tiles;
}