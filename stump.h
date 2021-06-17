#ifndef _Stump
#define _Stump
#include <SFML/Graphics.hpp>
#include <vector>
class stump
{
    sf::RectangleShape stump1;
public:
    /// initialise wicket
    stump();
    /// function to return wicket
    sf::RectangleShape getObject() const;
};
#endif