#include "playWindow.h"
playWindow::playWindow()
{
    this->initvariables();
}

void playWindow::initvariables()
{
    this->texturebg.loadFromFile("Background/bg.jpg");
    this->spritebg.setTexture(this->texturebg);
    sf::Vector2u bgsize=this->texturebg.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritebg.setPosition(0.f,0.f);
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
    movementSpeed = 5.f;
    xupdate = false;
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
    overs.setPosition(0.f,40.f);
    this->wicket.setFont(this->font);
    wicket.setCharacterSize(20);
    wicket.setPosition(0.f,20.f);
    this->target.setPosition(700.f,0.f);
    target.setCharacterSize(20);
    target.setFont(this->font);
    GameOver.setPosition(300.f,300.f);
    GameOver.setCharacterSize(80);
    GameOver.setFont(this->font); 
    this->Shot.setPosition(600.f,30.f);
    Shot.setCharacterSize(20);
    Shot.setFont(this->font);
    Shot.setFillColor(sf::Color::Red);
    Shot.setString("Previous Shot:");

    /// Ball didn't hit the marker yet
    BallHitMark = false;  
    BallHitBat = false;
    BallHitWicket = false;
    keypressed = "O";
    Score = 0;
    Overs = 0;
    Wickets = 0;
    gameOver = false;
    wicketUpdated = false;
    scoreUpdated = false;
    clockrestarted = false;
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
    float x = rand() % 190 + 280;
    float y = rand() % 200 + 300;
    this->marker_.setPosition(x,y);
}

void playWindow::update()
{
    ///moving the batsman
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->batsman_.move(-0.25f, 0.f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.25f, 0.f);
        }
        keypressed = "A";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->batsman_.move(0.25f, 0.f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.25f, 0.f);
        }
        keypressed = "D";
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        this->batsman_.move(-0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.05f,-0.05f);
        }
        keypressed = "G";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        this->batsman_.move(-0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.025f,-0.05f);
        }
        keypressed = "H";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        this->batsman_.move(0.f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.f,-0.05f);
        }
        keypressed = "J";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {   
        this->batsman_.move(0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.025f,-0.05f);
        }
        keypressed = "K";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        this->batsman_.move(0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.05f,-0.05f);
        }
        keypressed = "L";
    }
}

void playWindow::defaultscr(sf::RenderWindow& window)
{
    /// resetting scores, overs and targets
    score.setString("Score: "+std::to_string(Score));
    wicket.setString("Wickets"+std::to_string(Wickets));
    overs.setString("Overs: "+std::to_string(Overs));
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
    window.draw(wicket);
    window.draw(overs);
    window.draw(target);
    window.draw(Shot);
    window.setView(sf::View(sf::Vector2f(400.f,300.f),sf::Vector2f(800.f,600.f)));
    window.draw(tile_);
    window.draw(back);
    window.display();
}

void playWindow::call(unsigned* tgt,sf::RenderWindow& window)
{
    this->chase = tgt[0];
    std::cout << "Overs is: " << tgt[1] << std::endl;
    event.key.code = sf::Keyboard::Space;  
    this->initvariables();
    sf::Clock clock;
    gameOver = false;
    while(true)
    {
        while(window.pollEvent(this->event))
        {
            if(this->event.type==sf::Event::KeyPressed && this->event.key.code==sf::Keyboard::Escape)
            {
                window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
                gameOver = false;
                return;
            }
        }
        if((Score >= chase) || (Overs == tgt[1]))
        {
            gameOver = true;
        }
        BallHitWicket = false; 
        if(gameOver == false)
        {
            this->defaultscr(window);
        if(this->ball_.getPosition().y < window.getSize().y)
        {
            if(this->ball_.getPosition().y < marker_.getPosition().y)
            {
                this->updateBallMovement();
                if(xupdate == false)
                {
                    x = movementSpeed;
                    xupdate = true;
                }
                if(BallHitBat == true)
                {
                    if(keypressed == "G")
                    {
                        ball_.move(-x,-x);
                    }
                    else if(keypressed == "H")
                    {
                        ball_.move(-x*(0.5),-x);
                    }
                    else if(keypressed == "K")
                    {
                        ball_.move(x*(0.5),-x);
                    }
                    else if(keypressed == "L")
                    {
                        ball_.move(x,-x);
                    }
                    else
                    {
                        ball_.move(0.f,-x);
                    }
                }
                
            }
            else if(this->ball_.getPosition().y >= marker_.getPosition().y)
            {
                if(clockrestarted == false)
                {
                    clock.restart();
                    clockrestarted = true;
                }
                if(BallHitMark == false)
                {
                    SWING = rand() % 3;
                    BallHitMark = true;
                }
                if((BallHitMark == true) && (bat_[1].getGlobalBounds().contains(ball_.getPosition())))
                {
                    BallHitBat = true;
                }
                if(BallHitBat == true)
                {

                    sf::Time timeelapsed = clock.restart();
                    float x = 520-marker_.getPosition().y;
                    int i;
                    i = rand()%2;
                    sf::Time halfidealTime = sf::seconds(x/30);
                    sf::Time onehalfidealTime = sf::seconds(x/10);
                    if((timeelapsed>halfidealTime) && (timeelapsed<onehalfidealTime))
                    {
                        if(scoreUpdated == false)
                        {
                        if(i==0)
                        {
                            Score = Score + 6;
                            Shot.setString("Previous Shot:6");
                        }
                        else if(i == 1)
                        {
                            Score = Score + 4;
                            movementSpeed = movementSpeed*(0.5);
                            Shot.setString("Previous Shot:4");
                        }
                        scoreUpdated = true;
                        }
                    }
                    else
                    {
                        if(scoreUpdated == false)
                        {
                        if(i==0)
                        {
                            Score = Score + 2;
                            movementSpeed = movementSpeed*(0.25);
                            Shot.setString("Previous Shot:2");
                        }
                        if(i==1)
                        {
                            Score = Score + 1;
                            movementSpeed = movementSpeed*(0.125);
                            Shot.setString("Previous Shot:1");
                        }
                        scoreUpdated = true;
                        }
                    }
                    if(keypressed == "G")
                    {
                        ball_.move(-movementSpeed,-movementSpeed);
                    }
                    else if(keypressed == "H")
                    {
                        ball_.move(-(movementSpeed*(0.5)),-movementSpeed);
                    }
                    else if(keypressed == "K")
                    {
                        ball_.move(movementSpeed*(0.5),-movementSpeed);
                    }
                    else if(keypressed == "L")
                    {
                        ball_.move(movementSpeed,-movementSpeed);
                    }
                    else
                    {
                        ball_.move(0.f,-movementSpeed);
                    }
                }
                else
                {
                    this->updateBallSwing();
                    if((ball_.getPosition().y > 450.f) && (ball_.getPosition().y < 550.f) && (ball_.getPosition().x < 437.f) && (ball_.getPosition().x > 389.f))
                    {
                        this->bail_[0].setPosition(369.f,420.f);
                        this->bail_[1].setPosition(425.f,420.f);
                        BallHitWicket = true;
                        if(wicketUpdated == false)
                        {
                            Wickets = Wickets + 1;
                            wicketUpdated = true;
                        }
                    }
                }
            }
            
        }
        else
        { 
            int x = Overs*10;
            if((x-5) % 10 == 0)
            {
                Overs = (x-5)/10 + 1;
            }
            else
            {
                Overs = Overs + 0.1;
            }
            this->ball_.setPosition(450.f,30.f);
            this->updateMarker();
            this->bat_[0].setPosition(415.f,440.f);
            this->bat_[1].setPosition(410.f,460.f);
            this->batsman_.setPosition(195.f,330.f);
            this->bail_[0].setPosition(390.f,450.f);
            this->bail_[1].setPosition(410.f,450.f);
            BallHitMark = false;
            wicketUpdated = false;
            scoreUpdated = false;
            xupdate = false;
        }
        if(((this->ball_.getPosition().y < -150.f) || (this->ball_.getPosition().x > window.getSize().x) || (this->ball_.getPosition().x < 0)) && BallHitBat == true)
        {
            int x = Overs*10;
            if((x-5) % 10 == 0)
            {
                Overs = (x-5)/10 + 1;
            }
            else
            {
                Overs = Overs + 0.1;
            }
            this->ball_.setFillColor(sf::Color::Red);
            this->ball_.setPosition(450.f,30.f);
            BallHitBat = false;
            this->updateMarker();
            this->bat_[0].setPosition(415.f,440.f);
            this->bat_[1].setPosition(410.f,460.f);
            this->bail_[0].setPosition(390.f,450.f);
            this->bail_[1].setPosition(410.f,450.f);
            this->batsman_.setPosition(195.f,330.f);
            BallHitMark = false;
            wicketUpdated = false;
            scoreUpdated = false;
            xupdate = false;
            movementSpeed = 5.f;
        }
        this->update();
        }
        else
        {
            GameOver.setPosition(300.f,380.f);
            GameOver.setCharacterSize(120);
            GameOver.setFont(this->font); 
            GameOver.setFillColor(sf::Color::Yellow);
            if(Score >= chase)
            {
                GameOver.setString("Good Game Champ! \nYou saved the children");
            }
            else
            {
                GameOver.setString("Bad luck Champ \nChildren lost their ground");
            }
            window.clear();
            window.draw(spritebg);
            window.draw(GameOver);
            window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
            window.display();
        }
    }
}