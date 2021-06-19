#include "navAdapter.h"
int navAdapter::navigate(sf::Event& event,unsigned choices,std::vector<bool>& hover,std::vector<sf::ConvexShape>& tile_)
{
    int i;
    switch(event.key.code)
    {
        case sf::Keyboard::Up: 
            for(i=0;i<choices;i++)
                if((*(hover.begin()+i)))
                {
                    (*(hover.begin()+i)) = false;
                    (*(tile_.begin()+i)).setOutlineColor(sf::Color::White);
                    *(hover.begin()+(i+choices-1)%choices) = true;
                    (*(tile_.begin()+(i+choices-1)%choices)).setOutlineColor(sf::Color::Green);
                    break;
                }
            break;
        case sf::Keyboard::Down:
            for(i=0;i<choices;i++)
                if((*(hover.begin()+i)))
                {
                    (*(hover.begin()+i)) = false;
                    (*(tile_.begin()+i)).setOutlineColor(sf::Color::White);
                    *(hover.begin()+(i+1)%choices) = true;
                    (*(tile_.begin()+(i+1)%choices)).setOutlineColor(sf::Color::Green);
                    break;
                }
            break;
        case sf::Keyboard::Enter:
            for(i=0;i<choices;i++)
            {
                if(*(hover.begin()+i))
                {
                    (*tile_.begin()).setFillColor(sf::Color::Yellow);
                    (*(tile_.begin()+i)).setFillColor(sf::Color::Red);
                    break;
                }
            }
    }
    return i;
}