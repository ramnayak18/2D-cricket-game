#ifndef _Menu
#define _Menu
#include "tile.h"
enum class jump_t {HELP,ABOUT,LEVELS,CLOSE};
class menuWindow
{
    sf::Event event;
    sf::Font font;
    sf::Text text[4];
    tile _tile;
    sf::ConvexShape tile_[4];
    sf::Sprite spritebg;
    sf::Texture texturebg;

    /// logic variables
    bool hover[4];

public:
    menuWindow();
    void reset();
    void render(sf::RenderWindow& window);
    jump_t call(sf::RenderWindow& window);
};
#endif
