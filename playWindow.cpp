#include "playWindow.h"
playWindow::playWindow()
{
    /// position the crease
    this->crease_ = this->_crease.getObject();
    (*this->crease_.begin()).setPosition(198.f,520.f);
    (*(this->crease_.begin()+1)).setPosition(272.f,130.f);
    (*(this->crease_.begin()+2)).rotate(10.f);
    (*(this->crease_.begin()+2)).setPosition(240.f,520.f);
    (*(this->crease_.begin()+3)).rotate(350.f);
    (*(this->crease_.begin()+3)).setPosition(580.f,520.f);
    (*(this->crease_.begin()+4)).rotate(10.f);
    (*(this->crease_.begin()+4)).setPosition(310.f,100.f);
    (*(this->crease_.begin()+5)).rotate(350.f);
    (*(this->crease_.begin()+5)).setPosition(440.f,100.f);
    
    /// initialise the movement speed
    movementSpeed = 0.25f;
    /// position the bat
    this->bat_ = this->_bat.getObject();

    /// position the batsman
    this->batsman_ = this->_batsman.getObject();
    this->batsman_.setPosition(195.f,330.f);

    /// position the pitch
    this->pitch_ = this->_pitch.getObject();

    /// position the marker
    this->marker_ = this->_marker.getObject();
    
    /// position the stumps
    for(int i=0;i<3;i++)
    {
        this->stump_[i] = this->_stump.getObject();
        this->stump_[i].setPosition(389.f+(float)i*16,450.f);
    }
    for(int i=3;i<6;i++)
    {
        this->stump_[i] = this->_stump.getObject();
        this->stump_[i].setSize(sf::Vector2f(7.f,75.f));
        this->stump_[i].setPosition(309.f+(float)i*16,45.f);
    }

    /// position the bails
    for(int i=0;i<2;i++)
    {
        this->bail_[i] = this->_bail.getObject();
        this->bail_[i].setPosition(390.f+(float)i*20,450.f);
    }
    for(int i=2;i<4;i++)
    {
        this->bail_[i] = this->_bail.getObject();
        this->bail_[i].setPosition(319.f+(float)i*20,45.f);
    }

    ///position the ball
    this->ball_ = this->_ball.getObject();
    this->ball_.setPosition(450.f,30.f);
    /// position the tile
    this->tile_ = this->_tile.getObject();
    tile_.setScale(0.3f,0.3f);
    tile_.setPosition(640.f,540.f);
    tile_.setOutlineColor(sf::Color::Yellow);
    tile_.setFillColor(sf::Color::Red);
    tile_.setOutlineThickness(10);

    /// setting up "back" text
    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    back.setFillColor(sf::Color::Blue);
    back.setString("Back(Esc)");
    back.setCharacterSize(20);
    back.setFont(font);
    back.setPosition(670.f,550.f); 

    /// setting up scores, overs and targets
    this->score.setFont(font);
    score.setCharacterSize(20);
    this->overs.setFont(this->font);
    overs.setCharacterSize(20);
    overs.setPosition(0.f,20.f);
    this->target.setPosition(700.f,0.f);
    target.setCharacterSize(20);
    target.setFont(font); 

    /// Ball didn't hit the marker yet
    BallHitMark = false;  
}

void playWindow::updateBallMovement()
{
    float x1 = marker_.getPosition().x - this->ball_.getPosition().x;
    float y1 = marker_.getPosition().y - this->ball_.getPosition().y;
    if(x1>y1)
    {
        float z = y1/(2*x1);
        this->ball_.move(0.5f,z);
    }
    else if(y1>x1)
    {
        float z = x1/(2*y1);
        this->ball_.move(z,0.5f);
    }
}

void playWindow::updateBallSwing()
{
    switch(SWING)
    {
        case INSWING:
        this->ball_.move(-0.5f,0.5f); break;
        case STRAIGHT:
        this->ball_.move(0.f,0.5f); break;
        case OUTSWING:
        this->ball_.move(0.5f,0.5f); break;
    }
}

void playWindow::updateMarker()
{
    ///initialisng random position of marker
    float x = rand() % 225 + 228;
    float y = rand() % 331 + 160;
    this->marker_.setPosition(x,y);
}

void playWindow::update()
{
    ///moving the batsman
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->batsman_.move(-this->movementSpeed, 0.f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-this->movementSpeed, 0.f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->batsman_.move(this->movementSpeed, 0.f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(this->movementSpeed, 0.f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        this->batsman_.move(-0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.05f,-0.05f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        this->batsman_.move(-0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.025f,-0.05f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        this->batsman_.move(0.f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.f,-0.05f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {   
        this->batsman_.move(0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.025f,-0.05f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        this->batsman_.move(0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.05f,-0.05f);
        }
    }
    
}

void playWindow::defaultscr(sf::RenderWindow& window)
{
    /// resetting scores, overs and targets
    score.setString("Score: 0/0");
    overs.setString("Overs: 0.0");
    target.setString("Target: "+std::to_string(chase));

    /// rendering default screen
    window.clear(sf::Color::Green);
    window.draw(pitch_);
    window.draw(marker_);
    for(auto& c: crease_)
        window.draw(c);
    for(auto& b: bat_)
    {
        window.draw(b);
    }
    window.draw(batsman_);
    for(int i=0;i<6;i++)
        window.draw(stump_[i]);
    for(int i=0;i<4;i++)
        window.draw(bail_[i]);
    window.draw(ball_);
    window.draw(score);
    window.draw(overs);
    window.draw(target);
    window.setView(sf::View(sf::Vector2f(400.f,300.f),sf::Vector2f(800.f,600.f)));
    window.draw(tile_);
    window.draw(back);
    window.display();
}

void playWindow::call(unsigned tgt,sf::RenderWindow& window)
{
    this->chase = tgt;
    event.key.code = sf::Keyboard::Space;  
    while(true)
    {
        while(window.pollEvent(this->event))
        {
            if(this->event.type==sf::Event::KeyPressed && this->event.key.code==sf::Keyboard::Escape)
            {
                window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
                return;
            }
        }
        this->defaultscr(window);    
        if(this->ball_.getPosition().y < window.getSize().y)
        {
            if(this->ball_.getPosition().y < marker_.getPosition().y)
            {
                this->updateBallMovement();
            }
            else if(this->ball_.getPosition().y >= marker_.getPosition().y)
            {
                if(BallHitMark == false)
                {
                    SWING = rand() % 3;
                    std::cout << SWING << std::endl;
                    BallHitMark = true;
                }
                this->updateBallSwing();
            }
            
        }
        else
        {
            this->ball_.setPosition(450.f,30.f);
            this->updateMarker();
            this->bat_[0].setPosition(415.f,440.f);
            this->bat_[1].setPosition(410.f,460.f);
            this->batsman_.setPosition(195.f,330.f);
            BallHitMark = false;
        }
        this->update();
    }
}