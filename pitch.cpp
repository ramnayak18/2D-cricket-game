#include "pitch.h"
pitch::pitch()
{
    /// initialising the pitch
    pitch1.setPointCount(4);
    pitch1.setPoint(0,sf::Vector2f(190,560));
    pitch1.setPoint(1,sf::Vector2f(630,560));
    pitch1.setPoint(2,sf::Vector2f(470,100));
    pitch1.setPoint(3,sf::Vector2f(280,100));
    pitch1.setFillColor(sf::Color(210,105,30));
}
sf::ConvexShape pitch::getObject() const
{
    return this->pitch1;
}