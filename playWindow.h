#ifndef _Play_
#define _Play_
#include "tile.h"
#include "pitch.h"
#include "stump.h"
#include "bail.h"
#include "crease.h"
#include "bat.h"
#include "batsman.h"
#include "ball.h"
#include "marker.h"
#include<iostream>

enum swing{INSWING=0, STRAIGHT, OUTSWING};

class playWindow
{
private:
    /// objects required for window
    float movementSpeed;
    sf::Event event;
    sf::Text back;
    sf::Text score;
    sf::Text overs;
    sf::Text target;
    sf::Font font;
    tile _tile;
    sf::ConvexShape tile_;
    pitch _pitch;
    sf::ConvexShape pitch_;
    crease _crease;
    std::vector<sf::RectangleShape> crease_;
    bat _bat;
    std::vector<sf::RectangleShape> bat_;
    sf::CircleShape ball_;
    ball _ball;
    batsman _batsman;
    sf::Sprite batsman_;
    bail _bail;
    sf::CircleShape marker_;
    marker _marker;
    sf::RectangleShape bail_[4];
    stump _stump;
    sf::RectangleShape stump_[6];
    
    /// game logic variables
    unsigned chase;  
    unsigned SWING;
    bool BallHitMark;
public:
    void defaultscr(sf::RenderWindow& window);
    playWindow();
    void updateBallMovement();
    void updateBallSwing();
    void updateMarker();
    void update();
    void call(unsigned tgt,sf::RenderWindow& window);
};
#endif