#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <SFML/Graphics.hpp>
class ball
{
    sf::CircleShape Ball;
    public:
    /// initialise sprite
    ball();
    /// function to return ball 
    sf::CircleShape getObject();
};
#endif