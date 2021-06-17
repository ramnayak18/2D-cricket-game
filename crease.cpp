#include "crease.h"
crease::crease()
{
    /// Two big lines   
    this->line.setSize(sf::Vector2f(420,2));
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(210,2));
    this->lines.push_back(this->line);
    /// Four Small Ones
    this->line.setSize(sf::Vector2f(2,40));
    this->lines.push_back(this->line);
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(2,30));
    this->lines.push_back(this->line);
    this->lines.push_back(this->line);
   
}

std::vector<sf::RectangleShape> crease::getObject() const
{
    return this->lines;
}