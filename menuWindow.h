#ifndef _Menu_Window_H
#define _Menu_Window_H
#include "objects.h"
enum class jump_t {HELP,ABOUT,LEVELS,CLOSE};
class menuWindow
{
    sf::Event event;
    sf::Font font;
    sf::Text text[4];
    tile* _tile[4];
    sf::Sprite spritebg;
    sf::Texture texturebg;

public:
    menuWindow();
    void reset();
    void render(sf::RenderWindow& window);
    jump_t call(sf::RenderWindow& window);
};
#endif