#ifndef _help
#define _help
#include "objects.h"
/// @file helpWindow.h
/// @brief declares the functionalities and event loop of "Help" window

/// @brief controls the functionalities and event loop of "Help" window
/// @see aboutWindow
class helpWindow
{
private:
    /// objects required for window

    sf::Event event;
    
    sf::Sprite spritebg;
    sf::Texture texturebg;

    sf::Text back;
    sf::Font font;

    tile _tile;
    sf::ConvexShape tile_;

public:
    /// @brief sets up the background, button and text on the screen
    helpWindow();
    /// @brief runs the event loop and renders contents on the window, sets the view to adapt to the videomode of the desktop
    /// @param window accepts the window reference to render the contents on
    /// @note press Esc key to exit the "help" window
    void call(sf::RenderWindow& window);
};
#endif