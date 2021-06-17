#ifndef _Crease
#define _Crease
#include <SFML/Graphics.hpp>
#include <vector>
class crease
{
    std::vector<sf::RectangleShape> lines;
    sf::RectangleShape line;
    
    public:

    /// initialise crease
    crease();
    /// function to return crease
    std::vector<sf::RectangleShape> getObject() const;
};
#endif