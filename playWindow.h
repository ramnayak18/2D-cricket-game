#ifndef _Play_H
#define _Play_H
#include "objects.h"
#include<iostream>
#include<string>
/// @file playWindow.h
/// @brief declares the actual game window where the game is played by executing the game event loop

/// @brief the actual game window where the game is played by executing the game event loop
/// @bug the bowler type is shown after the last ball also
/// @bug the speed of the first ball is very high
class playWindow
{
private:
    /// objects required for window
    float movementSpeed;
    sf::Event event;
    sf::Text back;
    sf::Text score;
    sf::Text overs;
    sf::Text wicket;
    sf::Text target;
    sf::Text GameOver;
    sf::Text BowlerType;
    sf::Text Shot;
    sf::Font font;
    tile _tile;
    sf::ConvexShape tile_;
    pitch _pitch;
    sf::ConvexShape pitch_;
    crease _crease;
    std::vector<sf::RectangleShape> crease_;
    bat _bat;
    std::vector<sf::RectangleShape> bat_;
    ball _ball;
    batsman _batsman;
    sf::Sprite batsman_;
    bail _bail;
    sf::CircleShape marker_;
    marker _marker;
    sf::RectangleShape bail_[4];
    stump _stump;
    sf::RectangleShape stump_[6];
    bool gameOver;
    bool wicketUpdated;
    bool scoreUpdated;
    bool BowlerTypeShown;
    sf::Sprite spritebg;
    sf::Texture texturebg;
    sf::Sprite spritefour;
    sf::Texture texturefour;
    sf::Sprite spritesix;
    sf::Texture texturesix;
    sf::Sprite spritewicket;
    sf::Texture texturewicket;
    sf::Sprite spritelost;
    sf::Texture texturelost;
    sf::Sprite spritewon;
    sf::Texture texturewon;
    sf::Sprite spritewelcome;
    sf::Texture texturewelcome;
    sf::SoundBuffer bathitballbuffer;
    sf::SoundBuffer KidsCheersbuffer;
    sf::SoundBuffer disappointedchildrenbuffer;
    sf::Sound bathitballsound;
    sf::Sound KidsCheerssound;
    sf::Sound disappointedchildrensound;
    sf::Music music;
    
    /// game logic variables
    unsigned chase;  
    unsigned SWING;
    unsigned Score;
    unsigned Wickets;
    float Overs;
    unsigned idealWickets;
    bool BallHitMark;
    bool BallHitBat;
    bool BallHitWicket;
    bool clockrestarted;
    float x;
    bool xupdate;
    bool soundplayed;
    std::string keypressed;
public:
    /// @brief updates scores, wickets, runs and bowler type and renders the components of the window on the screen
    /// @param window accepts a window reference to display the contents
    /// @param tgt accepts a pointer to the target to be chased and the number of overs
    /// @see levelsWindow::call()
    void defaultscr(sf::RenderWindow& window,unsigned* tgt);
    /// @brief invokes playWindow::initvariables()
    playWindow();
    /// @brief sets up objects to be displayed on the screen, loads music, initialises game logic variables with their default values
    void initvariables();
    /// @brief sets a random bowler type to the ball - "FAST"/"SPIN" 
    /// @see ball::getBowlerType()
    void updateBowlerType();
    /// @brief displays the welcome message to the user
    void renderwelcome(sf::RenderWindow& window);
    /// @brief plays game music
    void startmusic();
    /// @brief sets a random position on the pitch (with contraints) for the marker to be placed
    /// @see ball::getMarkerPositions(float,float)
    void updateMarker();
    /// @brief moves batsman according to key pressed
    /// @note A - Left\n
    /// Q - Diagonally left (45 degrees)\n
    /// W - Diagonally left (22.5 degrees)\n
    /// E - Up\n
    /// R - Diagonally right (22.5 degrees)\n
    /// T - Diagonally right (45 degrees)\n
    /// D - Right
    void update();
    /// @brief runs the event loop for the game play\n
    /// -a bowler type (FAST/SPIN) is chosen after each over\n
    /// -each ball is a random spin or swing depending on bowler type and has a random marker, few balls are wide\n
    /// -batsman movements are updated, and a hit is counted when the ball falls in the bounds of the bat\n
    /// -earlier hits are given 4/6 runs, late hits 1/2 runs, wickets are down when the ball hits it\n
    /// -messages are displayed and music played after each 4/6/wicket\n
    /// @param window accepts a window reference to display the contents\n
    /// @param tgt accepts a pointer to the target to be chased and the number of overs\n
    /// @note Hit as early as you can after the ball hits the marker to get more runs\n
    /// @see playWindow::updateBowlerType() ball::getBowlerType() ball::updateSwing() ball::updateSpin() playWindow::updateMarker() playWindow::update()
    void call(unsigned* tgt,sf::RenderWindow& window);
};
#endif