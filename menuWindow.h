#ifndef _Menu
#define _Menu
#include "tile.h"
#include "navAdapter.h"
#include <vector>
enum class jump_t {HELP,ABOUT,LEVELS,CLOSE};
class menuWindow
{
    sf::Event event;
    sf::Font font;
    sf::Text text[4];
    tile _tile;
    std::vector<sf::ConvexShape> tile_;
    sf::Sprite spritebg;
    sf::Texture texturebg;

    /// logic variables
    std::vector<bool> hover;
    navAdapter nav;

public:
    menuWindow();
    void reset();
    void render(sf::RenderWindow& window);
    jump_t call(sf::RenderWindow& window);
};
#endif
