#include "ball.h"
ball::ball()
{
    
    Ball.setRadius(10.f);
    Ball.setFillColor(sf::Color::Red);
}
sf::CircleShape ball::getObject()
{
    return this->Ball;
}