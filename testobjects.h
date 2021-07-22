#ifndef OBJECTTEST_H
#define OBJECTTEST_H
#include <gtest/gtest.h>
#include <math.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include"objects.h"

/// sets up environment for testing the rendering of tiles 
class ObjectTest: public testing::Test
{
    public:
        sf::RenderWindow* window;
        sf::Texture* screenshot;
        sf::Image* ss;
        sf::Color color;
        void SetUp();
        void Update();
        void TearDown();
};
class ToMarkerTest: public testing::Test
{
    public:
    ball* _ball;
    marker* _marker;
    sf::CircleShape marker_;
    float initslope;
    float prevX;
    float prevY;
    void SetUp();
    void setPosition(float a, float b, float c, float d);
    float slope(float a,float b);
    void TearDown();
};
class SpinTest: public testing::Test
{
    public:
    ball* _ball;
    float oldX;
    float oldY;
    float Dist;
    void SetUp();
    float dist();
    void TearDown();
};
#endif