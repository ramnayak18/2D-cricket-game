#include "bail.h"
bail::bail()
{
    this->bail1.setSize(sf::Vector2f(15.f,2.5f));
    this->bail1.setFillColor(sf::Color::White);
}
sf::RectangleShape bail::getObject() const
{
    return this->bail1;
}