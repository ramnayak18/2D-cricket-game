#ifndef OBJECTTEST_H
#define OBJECTTEST_H
#include<gtest/gtest.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include"objects.h"

/// sets up environment for testing the rendering of tiles 
struct TileTest: public testing::Test
{
    sf::RenderWindow* window;
    tile* _tile;
    sf::Texture* screenshot;
    sf::Image* ss;
    sf::Color color;
    void SetUp();
    void TearDown();
};
#endif