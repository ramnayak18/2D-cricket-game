#ifndef _Bat
#define _Bat
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class bat
{
    sf::RectangleShape Bat;
    std::vector<sf::RectangleShape> Bats;
    public:
    /// initialise sprite
    bat();
    /// function to return bat 
    std::vector<sf::RectangleShape> getObject() const;
};
#endif