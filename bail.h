#ifndef _Bail
#define _Bail
#include <SFML/Graphics.hpp>
#include <vector>
class bail
{
    sf::RectangleShape bail1;
    public:
    /// initialise bail
    bail();
    /// function to return bail
    sf::RectangleShape getObject() const;
};
#endif