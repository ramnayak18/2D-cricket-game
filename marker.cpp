#include "marker.h"
marker::marker()
{
    /// initialising the marker
    this->Marker.setPosition(300.f,200.f);
    this->Marker.setFillColor(sf::Color::White);
    this->Marker.setRadius(5.f);
}
sf::CircleShape marker::getObject() const
{
    return this->Marker;
}