#ifndef _NavAdapter
#define _NavAdapter
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
class navAdapter
{
    public:
    int navigate(sf::Event&,unsigned,std::vector<bool>&,std::vector<sf::ConvexShape>&);
};
#endif
