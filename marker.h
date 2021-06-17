#ifndef _Marker
#define _Marker
#include <SFML/Graphics.hpp>
#include <vector>
class marker
{
    sf::CircleShape Marker;
    
    public:

    /// initialise marker
    marker();
    /// function to return marker
    sf::CircleShape getObject() const;
};
#endif