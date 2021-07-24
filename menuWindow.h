#ifndef _Menu_Window_H
#define _Menu_Window_H
#include "objects.h"
/// @file menuWindow.h
/// @brief declares the functionalities and event loop of "Menu" window

/// @brief describes the options for the next window after the menuWindow
enum class jump_t {HELP,ABOUT,LEVELS,CLOSE};
/// @brief controls the functionalities and event loop of "Menu" window
/// @see levelsWindow.h playWindow.h helpWindow.h aboutWindow.h
class menuWindow
{
    sf::Event event;
    sf::Font font;
    sf::Text text[4];
    tile* _tile[4];
    sf::Sprite spritebg;
    sf::Texture texturebg;

public:
    /// @brief sets up background, button and text on the screen and updates button states to their default value
    /// @see tile
    menuWindow();
    /// @brief resets the buttons to their default states before entering menu window
    /// @see tile
    void reset();
    /// @brief renders the components of the window on the screen
    /// @param window accepts a window reference to display the contents
    void render(sf::RenderWindow& window);
    /// @brief runs the event loop for the window, updating button states and calculating which window to go to next
    /// @param window accepts a window reference to display the contents
    /// @return a jump_t value to indicate which window to go to next
    /// @see tile
    /// @note Use Up and Down Arrow keys to navigate between buttons and press Enter to select one
    jump_t call(sf::RenderWindow& window);
};
#endif