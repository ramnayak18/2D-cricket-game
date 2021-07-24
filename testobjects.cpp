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

/// PRECONDITION: 
///   -position of ball on the screen is above the marker

/// POSTCONDITION:
///   -ball moves in a straight line
///   -ball moves from it's current position towards the marker and just crosses it
///   -ball moves at a fixed speed

/// PROCESS:
///   -matches slope of each move of ball with that of the line joining marker and ball
///   -checks if the ball before it's last move is above the marker
TEST_F(ToMarkerTest,Test1)
{
    setPosition(200.f,52.f,251.f,83.f);
    while(_ball->Ball.getPosition().y<marker_.getPosition().y)
    {
        _ball->updateBallMovement();
        ASSERT_NEAR(initslope,slope(prevX,prevY),0.001f);
        EXPECT_NEAR(1.f,_ball->Ball.getPosition().x-prevX,0.001f);
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
        EXPECT_NEAR(1.f,_ball->Ball.getPosition().y-prevY,0.001f);
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
        EXPECT_NEAR(1.f,prevX-_ball->Ball.getPosition().x,0.001f);
        if(_ball->Ball.getPosition().y>=marker_.getPosition().y)
            break;
        prevX = _ball->Ball.getPosition().x;
        prevY = _ball->Ball.getPosition().y;
    }
    EXPECT_LT(prevY,83.f);
}

void SpinTest::SetUp()
{
    _ball = new ball();
    _ball->BowlerType = "SPIN";
    _ball->state = "To Wicket";
    _ball->x = 242.f;
    _ball->y = 36.49f;
    _ball->Ball.setPosition(242.f,36.49f);
    oldX = 242.f;
    oldY = 36.49f;
}
float SpinTest::dist()
{
    return std::sqrt(std::pow(oldX-_ball->Ball.getPosition().x,2)+std::pow(oldY-_ball->Ball.getPosition().y,2));
}
void SpinTest::TearDown()
{
    delete _ball;
}

/// PRECONDITION: None

/// POSTCONDITION:
///   -ball moves just less than a quarter circle
///   -ball moves in increasing y-direction
///   -ball moves in increasing x-direction (outward spin) or decreasing x-direction (inward spin)
///   -ball has fixed speed

/// PROCESS: 
///   -checks if the distance moved is same each time
///   -checks if the ball has moved a distance equal to the radius of the circle along both axes
TEST_F(SpinTest,InwardSpin)
{
    _ball->SPIN = spin::INWARD;
    _ball->theta = 0.002f;
    _ball->updateBallMovement();
    Dist = dist();
    while(_ball->theta<=1.57)
    {
        oldX = _ball->Ball.getPosition().x;
        oldY = _ball->Ball.getPosition().y;
        _ball->updateBallMovement();
        ASSERT_NEAR(Dist,dist(),0.001f);
    }
    ASSERT_NEAR(242.f-_ball->Ball.getPosition().x,200.f,200*sin(0.002));
    EXPECT_NEAR(_ball->Ball.getPosition().y-36.49f,200.f,200*sin(0.002));
}
TEST_F(SpinTest,OutwardSpin)
{
    _ball->SPIN = spin::OUTWARD;
    _ball->theta = 0.005f;
    _ball->updateBallMovement();
    Dist = dist();
    while(_ball->theta<=1.57)
    {
        oldX = _ball->Ball.getPosition().x;
        oldY = _ball->Ball.getPosition().y;
        _ball->updateBallMovement();
        ASSERT_NEAR(Dist,dist(),0.001f);
    }
    ASSERT_NEAR(_ball->Ball.getPosition().x-242.f,200.f,200*sin(0.002));
    EXPECT_NEAR(_ball->Ball.getPosition().y-36.49f,200.f,200*sin(0.002));
}
