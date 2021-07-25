#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
/// @brief describes the swing options for the ball
enum swing{INSWING=0, STRAIGHT, OUTSWING};
/// @brief describes the spin options for the ball
enum spin{INWARD=0, STRAIGHTWARD, OUTWARD};

/// @file objects.h
/// @brief declares objects to be used on screen, and ensapsulates state of the marker and ball

/// @brief creates and returns stump
class stump
{
    sf::RectangleShape stump1;
public:
    /// @brief sets size and color of a single wicket
    stump();
    /// @return a single rectangle-shaped wicket
    sf::RectangleShape getObject() const;
};

/// @brief creates and supplies buttons, manages button states
class tile
{
    public:
    /// @brief stores the button
    sf::ConvexShape tiles;
    /// @brief creates a flag-shaped button with yellow color and white outline, initialises button state as "NULL"
    tile();
    /// @brief stores text displayed on button 
    sf::Text text;
    /// @brief stores button state - "NULL" or "Hover"
    std::string state;
    /// @return the button 
    sf::ConvexShape getObject();
    /// @brief stores the accepted text in tile::text
    /// @param Text accepts the text for the button
    void setText(sf::Text Text);
    /// @brief changes button's fill colour based on it's state (green for "Hover" and yellow for "NULL")
    void updateColor();
    /// @brief updates state of tiles depending upon user-pressed key
    /// @param event accepts the event of key being pressed
    /// @param options accepts the number of buttons
    /// @param arr accepts any array of pointers to the buttons (tiles)
    /// @return index number of the button modified
    int update(tile* arr[],unsigned options,sf::Event& event);
};

/// @brief creates and returns pitch
class pitch 
{
    sf::ConvexShape pitch1;
    public:
    /// @brief creates a convex shaped cricket pitch brown in colour
    pitch();
    /// @return the cricket pitch
    sf::ConvexShape getObject() const;
};

/// @brief creates and returns markers
class marker
{
    sf::CircleShape Marker;
    
    public:

    /// @brief creates a circular white marker
    marker();
    /// @return the marker
    sf::CircleShape getObject() const;
};

/// @brief creates and returns crease for the pitch
class crease
{
    std::vector<sf::RectangleShape> lines;
    sf::RectangleShape line;
    
    public:

    /// @brief creates a vector of rectangular shapes to be used as crease
    crease();
    /// @return the vector of rectangular shapes to be used as crease
    std::vector<sf::RectangleShape> getObject() const;
};

/// @brief creates and returns batsman
class batsman
{
    sf::Sprite spritebatsman;
    sf::Texture texturebatsman;
    public:
    /// @brief loads sprite of batsman
    batsman();
    /// @return the sprite of batsman
    sf::Sprite getObject();
};

/// @brief creates and returns bat
class bat
{
    sf::RectangleShape Bat;
    std::vector<sf::RectangleShape> Bats;
    public:
    /// @brief creates a cricket bat as a vector of two rectangles
    bat();
    /// @return the cricket bat as a vector of two rectangles
    std::vector<sf::RectangleShape> getObject() const;
};

/// @brief creates and supplies balls, manages ball states and ball movements
class ball
{
    public:
    /// @brief stores the ball
    sf::CircleShape Ball;
    /// @brief creates a ball and initialises ball::state, ball::movementSpeed and ball::theta with their default values
    ball();
    /// @brief stores ball's state - "To Marker"/"To Wicket"/"Hitted Bat"
    std::string state;
    /// @brief stores marker's x coordinate
    /// @see ball::getMarkerPositions(float,float)
    float x;
    /// @brief stores marker's y coordinate
    /// @see ball::getMarkerPositions(float,float)
    float y;
    /// @brief stores swing type - INSWING/OUTSWING/STRAIGHT
    /// @see ball::updateSwing() 
    unsigned SWING;
    /// @brief stores spin type - INWARD/OUTWARD/STRAIGHTWARD
    /// @see ball::updateSpin()
    unsigned SPIN;
    /// @brief stores angle by which spin ball has turned in INWARD/OUTWARD spin
    /// @see ball::SPIN
    float theta;
    /// @brief stores ball's speed after being hit by the player
    float movementSpeed;
    /// @brief stores bowler type - "SPIN"/"FAST"
    std::string BowlerType;
    /// @brief updates ball::BowlerType
    /// @param B accepts bowler type
    void getBowlerType(std::string B);
    /// @brief updates the values of ball::x and ball::y
    /// @param MarkerPosx accepts marker's x-coordinate
    /// @param MarkerPosy accepts marker's y-coordinate
    void getMarkerPositions(float MarkerPosx, float MarkerPosy);
    /// @brief moves the ball according to its ball::state\n
    /// "To Marker" - moves the ball towards the marker at a fixed speed\n
    /// "To Wicket" - spins/swings the ball towards the batsman\n
    /// "Hitted Bat" - rebounds the ball after being hit in a direction depending upon the key pressed and with a speed depending upon the time taken to hit the ball
    void updateBallMovement();
    /// @brief stores the key pressed to move batsman
    std::string keypressed;
    /// @brief updates the value of ball::keypressed
    /// @param S accepts the key pressed to move batsman
    void getKeyPressed(std::string S);
    /// @brief stores a random swing type in ball::SWING
    void updateSwing();
    /// @brief stores a random spin type in ball::SPIN
    void updateSpin();
    /// @return the ball
    sf::CircleShape getObject();
};

/// @brief creates and returns bail
class bail
{
    sf::RectangleShape bail1;
    public:
    /// @brief creates a single rectangle-shaped white-coloured bail
    bail();
    /// @return a single bail
    sf::RectangleShape getObject() const;
};






#endif