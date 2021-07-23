#include "testobjects.h"
void ObjectTest::SetUp()
{
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Test",sf::Style::Fullscreen); 
    screenshot = new sf::Texture();
    ss = new sf::Image();
    screenshot->create(window->getSize().x,window->getSize().y);
}
void ObjectTest::Update()
{
    screenshot->update(*window);
    *ss = screenshot->copyToImage();
}
void ObjectTest::TearDown()
{
    delete window;
    delete screenshot;
    delete ss;
}

/* 
 * tests if the objects are rendered on the the window or not by checking the colour of pixels
 * of a screenshot of the rendered window
 */

TEST_F(ObjectTest,TileRenderTest)
{  
    tile* _tile = new tile();
    window->draw(_tile->getObject());
    Update();
    color = ss->getPixel(5,5);
    delete _tile;
    EXPECT_EQ(color,sf::Color::Yellow);
    color = ss->getPixel(5,155);
    EXPECT_EQ(color,sf::Color::White);
}
TEST_F(ObjectTest,StumpRenderTest)
{
    stump* _stump = new stump();
    window->draw(_stump->getObject());
    Update();
    color = ss->getPixel(2,5);
    delete _stump;
    EXPECT_EQ(color,sf::Color::White);
}
TEST_F(ObjectTest,MarkerRenderTest)
{
    marker* _marker = new marker();
    window->draw(_marker->getObject());
    Update();
    color = ss->getPixel(304,204);
    delete _marker;
    EXPECT_EQ(color,sf::Color::White);
}
TEST_F(ObjectTest,BatsmanRenderTest)
{
    batsman* _batsman = new batsman();
    sf::Sprite b = _batsman->getObject();
    sf::Texture t = *b.getTexture();
    window->draw(b);
    sf::Color c(0,0,0,0);
    Update();
    unsigned count = 0;
    for(int i=0;i<=t.getSize().x;i++)
    {
        for(int j=0;j<=t.getSize().y;j++)
        {
            if(ss->getPixel(i,j) != c)
                count++;
        }
    }
    delete _batsman;
    EXPECT_NE(count,0);
    color = ss->getPixel(100,100);
    EXPECT_EQ(c,color);
}
TEST_F(ObjectTest,BatRenderTest)
{
    bat* _bat = new bat();
    std::vector<sf::RectangleShape> b = _bat->getObject();
    for(auto& B: b)
        window->draw(B);
    Update();
    delete _bat;
    color = ss->getPixel(420,448);
    EXPECT_EQ(color,sf::Color(240,230,140));
    color = ss->getPixel(411,500);
    EXPECT_EQ(color,sf::Color(240,230,140));
}

void ToMarkerTest::SetUp()
{
    _ball = new ball();
    _marker = new marker();
    marker_ = _marker->getObject();
}
void ToMarkerTest::setPosition(float a, float b, float c, float d)
{
    _ball->Ball.setPosition(a,b);
    marker_.setPosition(c,d);
    _ball->getMarkerPositions(c,d);
    initslope = slope(c,d);
    prevX = a;
    prevY = b;
}
float ToMarkerTest::slope(float a,float b)
{
    return (a-_ball->Ball.getPosition().x)/(b-_ball->Ball.getPosition().y);
}
void ToMarkerTest::TearDown()
{
    delete _ball;
    delete _marker;
}

/// PRECONDITION: position of ball on the screen should be above the marker
/// POSTCONDITION:
///   -ball moves in a straight line
///   -ball moves from it's current position towards the marker and just crosses it
///   -ball moves at a fixed speed
TEST_F(ToMarkerTest,Test1)
{
    setPosition(200.f,52.f,251.f,83.f);
    while(_ball->Ball.getPosition().y<marker_.getPosition().y)
    {
        _ball->updateBallMovement();
        ASSERT_NEAR(initslope,slope(prevX,prevY),0.001f);
        EXPECT_NEAR(0.5f,_ball->Ball.getPosition().x-prevX,0.001f);
        if(_ball->Ball.getPosition().y>=marker_.getPosition().y)
            break;
        prevX = _ball->Ball.getPosition().x;
        prevY = _ball->Ball.getPosition().y;
    }
    EXPECT_LT(prevY,83.f);
}
TEST_F(ToMarkerTest,Test2)
{
    setPosition(260.f,52.f,251.f,83.f);
    while(_ball->Ball.getPosition().y<marker_.getPosition().y)
    {
        _ball->updateBallMovement();
        ASSERT_NEAR(initslope,slope(prevX,prevY),0.001f);
        EXPECT_NEAR(0.5f,_ball->Ball.getPosition().y-prevY,0.001f);
        if(_ball->Ball.getPosition().y>=marker_.getPosition().y)
            break;
        prevX = _ball->Ball.getPosition().x;
        prevY = _ball->Ball.getPosition().y;
    }
    EXPECT_LT(prevY,83.f);
}
TEST_F(ToMarkerTest,Test3)
{
    setPosition(293.f,52.f,251.f,83.f);
    while(_ball->Ball.getPosition().y<marker_.getPosition().y)
    {
        _ball->updateBallMovement();
        ASSERT_NEAR(initslope,slope(prevX,prevY),0.001f);
        EXPECT_NEAR(0.5f,prevX-_ball->Ball.getPosition().x,0.001f);
        if(_ball->Ball.getPosition().y>=marker_.getPosition().y)
            break;
        prevX = _ball->Ball.getPosition().x;
        prevY = _ball->Ball.getPosition().y;
    }
    EXPECT_LT(prevY,83.f);
}
