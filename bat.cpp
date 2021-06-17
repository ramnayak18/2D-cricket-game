#include "bat.h"
bat::bat()
{
    this->Bat.setPosition(415.f,440.f);
    this->Bat.setFillColor(sf::Color(240,230,140));
    this->Bat.setSize(sf::Vector2f(10,30));
    this->Bats.push_back(this->Bat);
    this->Bat.setPosition(410.f,460.f);
    this->Bat.setSize(sf::Vector2f(20,80));
    this->Bats.push_back(this->Bat);

}
std::vector<sf::RectangleShape> bat::getObject() const
{
    return this->Bats;
}