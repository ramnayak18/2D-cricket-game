#include "stump.h"
stump::stump()
{
    this->stump1.setSize(sf::Vector2f(8.f,100.f));
    this->stump1.setFillColor(sf::Color::White);
}
sf::RectangleShape stump::getObject() const
{
    return this->stump1;
}