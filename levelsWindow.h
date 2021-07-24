#ifndef _LEVELS_WINDOW_H
#define _LEVELS_WINDOW_H
#include <unistd.h>
#include <iostream>
#include "objects.h"
#include <cstdlib>
#include <ctime>
/// @file levelsWindow.h
/// @brief declares the functionalities and event loop of "Levels" window

/// @brief controls the functionalities and event loop of "Levels" window
/// @see playWindow.h
class levelsWindow
{
private:
    sf::Event event;
    sf::Font font;
    sf::Text section[2];
    sf::Text level[3];
    sf::Text overs[2];
    sf::Sprite spritebg;
    sf::Texture texturebg;
    tile* _sectionTile[2];
    tile* _levelTile[3];
    tile* _oversTile[2];

    /// logic variables
    bool levelinit;
    unsigned target;
    unsigned Overs;
    unsigned arr[2];
public:
    /// @brief sets up background, button and text on the screen and updates button states to their default value
    /// @see tile
    levelsWindow();
    /// @brief resets the buttons to their default states before entering menu window
    /// @see tile
    void reset();
    /// @brief changes button states of levels depending upon the key pressed
    /// @return the serial number of the difficulty level selected
    /// @see tile
    const int levelLogic(sf::RenderWindow& window);
    /// @brief changes button states of overs depending upon the key pressed
    /// @return the serial number of the overs selected
    /// @see tile
    const int oversLogic(sf::RenderWindow& window);
    /// @brief renders the components of the window on the screen
    /// @param window accepts a window reference to display the contents
    void render(sf::RenderWindow& window);
    /// @brief runs the event loop for the window, updating button states for levels and overs, and calculating the target to be chased
    /// @param window accepts a window reference to display the contents
    /// @return a pointer to an array storing the target to be achieved and total number of overs
    /// @note Use Up and Down Arrow keys to navigate between buttons and press Enter to select one
    /// @see levelLogic() oversLogic()
    unsigned* call(sf::RenderWindow& window);
};
#endif