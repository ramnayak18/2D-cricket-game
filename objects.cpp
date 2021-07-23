#include "objects.h"

tile::tile()
{
    /// initialising the tile
    tiles.setPointCount(4);
    tiles.setPoint(0,sf::Vector2f(0.f,0.f));
    tiles.setPoint(1,sf::Vector2f(500.f,0.f));
    tiles.setPoint(2,sf::Vector2f(450.f,150.f));
    tiles.setPoint(3,sf::Vector2f(0.f,150.f));
    tiles.setFillColor(sf::Color::Yellow);
    tiles.setOutlineColor(sf::Color::White);
    tiles.setOutlineThickness(20.f);
    state = "NULL";
}
sf::ConvexShape tile::getObject()
{
    return this->tiles;
}

void tile::setText(sf::Text Text)
{
    text = Text;
}

void tile::updateColor()
{
    if(state == "Hover")
    {
        tiles.setOutlineColor(sf::Color::Green);
    }

    else if(state == "NULL")
    {
        tiles.setOutlineColor(sf::Color::White);
    }
}

stump::stump()
{
    this->stump1.setSize(sf::Vector2f(8.f,100.f));
    this->stump1.setFillColor(sf::Color::White);
}
sf::RectangleShape stump::getObject() const
{
    return this->stump1;
}

pitch::pitch()
{
    /// initialising the pitch
    pitch1.setPointCount(4);
    pitch1.setPoint(0,sf::Vector2f(190,560));
    pitch1.setPoint(1,sf::Vector2f(630,560));
    pitch1.setPoint(2,sf::Vector2f(470,100));
    pitch1.setPoint(3,sf::Vector2f(280,100));
    pitch1.setFillColor(sf::Color(210,105,30));
}
sf::ConvexShape pitch::getObject() const
{
    return this->pitch1;
}

marker::marker()
{
    /// initialising the marker
    this->Marker.setPosition(300.f,200.f);
    this->Marker.setFillColor(sf::Color::White);
    this->Marker.setRadius(5.f);
}
sf::CircleShape marker::getObject() const
{
    return this->Marker;
}

crease::crease()
{
    /// Two big lines   
    this->line.setSize(sf::Vector2f(420,2));
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(210,2));
    this->lines.push_back(this->line);
    /// Four Small Ones
    this->line.setSize(sf::Vector2f(2,40));
    this->lines.push_back(this->line);
    this->lines.push_back(this->line);
    this->line.setSize(sf::Vector2f(2,30));
    this->lines.push_back(this->line);
    this->lines.push_back(this->line);
   
}

std::vector<sf::RectangleShape> crease::getObject() const
{
    return this->lines;
}

batsman::batsman()
{
    /// loading texture from file
    if(!this->texturebatsman.loadFromFile("Textures/batsman.png"))
    {
        std::cout << "ERROR::OBJECTS::BATSMAN::BATSMAN::Could not load texture file." << "\n";
    }
    /// setting texture to the sprite
    this->spritebatsman.setTexture(this->texturebatsman);
    spritebatsman.setScale(0.7f,0.7f);
}
sf::Sprite batsman::getObject()
{
    return this->spritebatsman;
}

bat::bat()
{
    this->Bat.setPosition(415.f,440.f);
    this->Bat.setFillColor(sf::Color(240,230,140));
    this->Bat.setSize(sf::Vector2f(10,30));
    this->Bats.push_back(this->Bat);
    this->Bat.setPosition(410.f,460.f);
    this->Bat.setSize(sf::Vector2f(20,80));
    this->Bats.push_back(this->Bat);

}
std::vector<sf::RectangleShape> bat::getObject() const
{
    return this->Bats;
}

ball::ball()
{
    
    Ball.setRadius(10.f);
    Ball.setFillColor(sf::Color::Red);
    theta = 0;
    movementSpeed = 5;
    state = "To Marker";
}
sf::CircleShape ball::getObject()
{
    return this->Ball;
}

void ball::getBowlerType(std::string B)
{
    BowlerType = B;
}

void ball::getKeyPressed(std::string S)
{
    keypressed = S;
}

void ball::getMarkerPositions(float MarkerPosx, float MarkerPosy)
{
    x = MarkerPosx;
    y = MarkerPosy;
}

void ball::updateSwing()
{
    SWING = rand() % 3;
}

void ball::updateSpin()
{
    SPIN = rand() % 3;
}

void ball::updateBallMovement()
{
    if(state == "To Marker")
    {
        float x1 = x - this->Ball.getPosition().x;
        float y1 = y - this->Ball.getPosition().y;
        if(x1>y1)
        {
          float z = y1/(2*x1);
          this->Ball.move(0.5f,z);
        }
        else if(y1>x1)
        {
          float z = x1/(2*y1);
          this->Ball.move(z,0.5f);
        }
    }

    if(state == "To Wicket")
    {
        if(BowlerType == "FAST")
        {
            switch(SWING)
            {
              case INSWING:
              this->Ball.move(-0.5f,0.5f); break;
              case STRAIGHT:
              this->Ball.move(0.f,0.5f); break;
              case OUTSWING:
              this->Ball.move(0.5f,0.5f); break;
            }
        }
        else if(BowlerType == "SPIN")
        {
            switch(SPIN)
            {
                case INWARD:
                {
                    float x1;
                    x1 = x - 200.f;
                    if(theta < 1.57)
                    {
                       this->Ball.setPosition(x1+200*cos(theta),y+200*sin(theta));
                    }
                    else
                    {
                       this->Ball.move(-0.5f,0.5f);
                    }
                    theta = theta + 0.002; break;
                }
                case STRAIGHTWARD:
                this->Ball.move(0,0.5f); break;
                case OUTWARD:
                {
                    float x1;
                    x1 = x + 200.f;
                    if(theta < 1.57)
                    {
                       this->Ball.setPosition(x1-200*cos(theta),y+200*sin(theta));
                    }
                    else
                    {
                       this->Ball.move(-0.5f,0.5f);
                    }
                    theta = theta + 0.005; break;
                }
            }
        }
    }

    if(state == "Hitted Bat")
    {
        if(keypressed == "G")
        {
            Ball.move(-movementSpeed,-movementSpeed);
        }
        else if(keypressed == "H")
        {
            Ball.move(-(movementSpeed*(0.5)),-movementSpeed);
        }
        else if(keypressed == "K")
        {
            Ball.move(movementSpeed*(0.5),-movementSpeed);
        }
        else if(keypressed == "L")
        {
            Ball.move(movementSpeed,-movementSpeed);
        }
        else
        {
            Ball.move(0.f,-movementSpeed);
        }
    }
}


bail::bail()
{
    this->bail1.setSize(sf::Vector2f(15.f,2.5f));
    this->bail1.setFillColor(sf::Color::White);
}
sf::RectangleShape bail::getObject() const
{
    return this->bail1;
}
