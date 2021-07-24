#ifndef _ABOUT
#define _ABOUT
#include "objects.h"
/// @file aboutWindow.h
/// @brief decalres the functionalities and event loop of "About" window

/// @brief controls the functionalities and event loop of "About" window
/// @see helpWindow
class aboutWindow
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
    aboutWindow();
    /// @brief runs the event loop and renders contents on the window, sets the view to adapt to the videomode of the desktop
    /// @param window accepts the window to render the contents on
    /// @note press Esc key to exit the "About" window
    void call(sf::RenderWindow& window);
};
#endif