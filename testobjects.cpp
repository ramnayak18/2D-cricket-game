#include "testobjects.h"

void TileTest::SetUp()
{
    
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Test",sf::Style::Fullscreen); 
    _tile = new tile();
    screenshot = new sf::Texture();
    ss = new sf::Image();
    window->draw(_tile->getObject());
    screenshot->create(window->getSize().x,window->getSize().y);
    screenshot->update(*window);
    *ss = screenshot->copyToImage();
}
void TileTest::TearDown()
{
    delete window;
    delete _tile;
    delete screenshot;
    delete ss;
}

/* 
 * tests if the tiles are rendered on the the window or not by
 * checking the colour of pixels of a screenshot of the rendered
 * window
 */

TEST_F(TileTest,ColorRenderTest)
{  
    color = ss->getPixel(5,5);
    ASSERT_EQ(color,sf::Color::Yellow);
}
TEST_F(TileTest,OutlineRenderTest)
{
    color = ss->getPixel(5,155);
    EXPECT_EQ(color,sf::Color::White);
}