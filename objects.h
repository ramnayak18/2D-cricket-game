#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
enum swing{INSWING=0, STRAIGHT, OUTSWING};

class stump
{
    sf::RectangleShape stump1;
public:
    /// initialise wicket
    stump();
    /// function to return wicket
    sf::RectangleShape getObject() const;
};

class tile
{
    public:
    sf::ConvexShape tiles;
    /// initialise tile
    tile();
    sf::Text text;
    std::string state;
    /// function to return tile 
    sf::ConvexShape getObject();
    void setText(sf::Text Text);
    void updateColor();
};

class pitch 
{
    sf::ConvexShape pitch1;
    public:
    /// initialise pitch
    pitch();
    /// function to return pitch
    sf::ConvexShape getObject() const;
};

class marker
{
    sf::CircleShape Marker;
    
    public:

    /// initialise marker
    marker();
    /// function to return marker
    sf::CircleShape getObject() const;
};

class crease
{
    std::vector<sf::RectangleShape> lines;
    sf::RectangleShape line;
    
    public:

    /// initialise crease
    crease();
    /// function to return crease
    std::vector<sf::RectangleShape> getObject() const;
};

class batsman
{
    sf::Sprite spritebatsman;
    sf::Texture texturebatsman;
    public:
    /// initialise sprite
    batsman();
    /// function to return batsman 
    sf::Sprite getObject();
};

class bat
{
    sf::RectangleShape Bat;
    std::vector<sf::RectangleShape> Bats;
    public:
    /// initialise sprite
    bat();
    /// function to return bat 
    std::vector<sf::RectangleShape> getObject() const;
};

class ball
{
    sf::CircleShape Ball;
    public:
    /// initialise sprite
    ball();
    std::string state;
    /// function to return ball 
    sf::CircleShape getObject();
};

class bail
{
    sf::RectangleShape bail1;
    public:
    /// initialise bail
    bail();
    /// function to return bail
    sf::RectangleShape getObject() const;
};






#endif