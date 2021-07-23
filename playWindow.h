#ifndef _Play_H
#define _Play_H
#include "objects.h"
#include<iostream>
#include<string>



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
    void defaultscr(sf::RenderWindow& window,unsigned* tgt);
    playWindow();
    void initvariables();
    void updateBallMovement();
    void updateBallSwing();
    void updateBowlerType();
    void renderwelcome(sf::RenderWindow& window);
    void startmusic();
    void updateMarker();
    void update();
    void call(unsigned* tgt,sf::RenderWindow& window);
};
#endif