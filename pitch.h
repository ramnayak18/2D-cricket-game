#ifndef _Pitch
#define _Pitch
#include <SFML/Graphics.hpp>
class pitch 
{
    sf::ConvexShape pitch1;
    public:
    /// initialise pitch
    pitch();
    /// function to return pitch
    sf::ConvexShape getObject() const;
};
#endif