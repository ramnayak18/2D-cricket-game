#include "playWindow.h"
/// @file playWindow.cpp
/// @brief implements the actual game window where the game is played by executing the game event loop
playWindow::playWindow()
{
    this->initvariables();
}

void playWindow::initvariables()
{
    this->texturebg.loadFromFile("Background/bg.jpg");
    this->spritebg.setTexture(this->texturebg);
    this->texturefour.loadFromFile("Textures/Four Message.png");
    this->spritefour.setTexture(this->texturefour);
    this->texturesix.loadFromFile("Textures/Six message.png");
    this->spritesix.setTexture(this->texturesix);
    this->texturewicket.loadFromFile("Textures/Wicket message.jpg");
    this->spritewicket.setTexture(this->texturewicket);
    this->texturelost.loadFromFile("Textures/Lost message.jpg");
    this->spritelost.setTexture(this->texturelost);
    this->texturewon.loadFromFile("Textures/Winning Message.png");
    this->spritewon.setTexture(this->texturewon);
    if(!this->bathitballbuffer.loadFromFile("Sounds/bat_hit_ball.ogg"))
    {
        std::cout << "Error!" << std::endl;
    }
    this->bathitballsound.setBuffer(bathitballbuffer);
    if(!this->KidsCheersbuffer.loadFromFile("Sounds/Kids Cheers.ogg"))
    {
        std::cout << "Error!" << std::endl;
    }
    this->KidsCheerssound.setBuffer(KidsCheersbuffer);
    if(!this->disappointedchildrenbuffer.loadFromFile("Sounds/disappointed-children.ogg"))
    {
        std::cout << "Error!" << std::endl;
    }
    this->disappointedchildrensound.setBuffer(disappointedchildrenbuffer);


    sf::Vector2u bgsize=this->texturebg.getSize();
    sf::Vector2u foursize=this->texturefour.getSize();
    sf::Vector2u sixsize=this->texturesix.getSize();
    sf::Vector2u wicketsize=this->texturewicket.getSize();
    sf::Vector2u lostsize=this->texturelost.getSize();
    sf::Vector2u wonsize=this->texturewon.getSize();
    spritebg.setScale(1920/static_cast<float>(bgsize.x),1080/static_cast<float>(bgsize.y));
    spritefour.setScale(400/static_cast<float>(foursize.x),300/static_cast<float>(foursize.y));
    spritesix.setScale(400/static_cast<float>(sixsize.x),300/static_cast<float>(sixsize.y));
    spritewicket.setScale(400/static_cast<float>(wicketsize.x),300/static_cast<float>(wicketsize.y));
    spritelost.setScale(1920/static_cast<float>(lostsize.x),1080/static_cast<float>(lostsize.y));
    spritewon.setScale(1920/static_cast<float>(wonsize.x),1080/static_cast<float>(wonsize.y));
    spritebg.setPosition(0.f,0.f);
    spritefour.setPosition(250.f,150.f);
    spritesix.setPosition(250.f,150.f);
    spritewicket.setPosition(250.f,150.f);
    spritelost.setPosition(0.f,0.f);
    spritewon.setPosition(0.f,0.f);

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
    
    _ball.movementSpeed = 8.f;
    xupdate = false;

    this->bat_ = this->_bat.getObject();

    this->batsman_ = this->_batsman.getObject();
    this->batsman_.setPosition(195.f,330.f);

    this->pitch_ = this->_pitch.getObject();

    this->marker_ = this->_marker.getObject();
    marker_.setPosition(408.f,380.f);

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

    _ball.Ball.setPosition(450.f,30.f);
    _ball.state = "To Marker";

    this->tile_ = this->_tile.getObject();
    tile_.setScale(0.3f,0.3f);
    tile_.setPosition(640.f,540.f);
    tile_.setOutlineColor(sf::Color::Yellow);
    tile_.setFillColor(sf::Color::Red);
    tile_.setOutlineThickness(10);

    font.loadFromFile("Fonts/LibreBaskerville-Italic.ttf");
    back.setFillColor(sf::Color::Blue);
    back.setString("Back(Esc)");
    back.setCharacterSize(20);
    back.setFont(font);
    back.setPosition(670.f,550.f); 

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
    Shot.setFillColor(sf::Color::Blue);
    Shot.setString("0");
    this->BowlerType.setPosition(300.f,300.f);
    BowlerType.setFont(this->font);
    BowlerType.setFillColor(sf::Color::Yellow);

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
    BowlerTypeShown = false;
    soundplayed = false;
}

void playWindow::updateBowlerType()
{
    int x = rand() % 2;
    if(x == 0)
    {
        _ball.getBowlerType("FAST");
        BowlerType.setString("FAST");
    }
    if(x == 1)
    {
        _ball.getBowlerType("SPIN");
        BowlerType.setString("SPIN");
    }
}

void playWindow::updateMarker()
{
    float x,y;

    if(_ball.BowlerType == "SPIN")
    {
        x = rand() % 90 + 340;
        y = rand() % 140 + 380;
    }
    if(_ball.BowlerType == "FAST")
    {
        x = rand() % 100 + 325;
        y = rand() % 210 + 310;
    }
    this->marker_.setPosition(x,y);
    _ball.getMarkerPositions(marker_.getPosition().x, marker_.getPosition().y);
}

void playWindow::update()
{
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->batsman_.move(-0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.05f,-0.05f);
        }
        keypressed = "Q";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->batsman_.move(-0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(-0.025f,-0.05f);
        }
        keypressed = "W";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->batsman_.move(0.f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.f,-0.05f);
        }
        keypressed = "E";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {   
        this->batsman_.move(0.025f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.025f,-0.05f);
        }
        keypressed = "R";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        this->batsman_.move(0.05f,-0.05f);
        for(int i=0;i<2;i++)
        {
            this->bat_[i].move(0.05f,-0.05f);
        }
        keypressed = "T";
    }
}

void playWindow::renderwelcome(sf::RenderWindow& window)
{
    this->texturewelcome.loadFromFile("Background/welcome.png");
    this->spritewelcome.setTexture(this->texturewelcome);
    sf::Vector2u welcomesize=this->texturewelcome.getSize();
    spritewelcome.setScale(1920/static_cast<float>(welcomesize.x),1080/static_cast<float>(welcomesize.y));
    spritewelcome.setPosition(0.f,0.f);
    window.clear(sf::Color::Magenta);
    window.draw(spritewelcome);
    window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
    window.display();
    sf::Time t1 = sf::seconds(4);
    sleep(t1);
}


void playWindow::startmusic()
{
    music.openFromFile("Sounds/Game Music.ogg");
    music.play();
    music.setLoop(true);
}

void playWindow::defaultscr(sf::RenderWindow& window,unsigned* tgt)
{
    std::string num_text = std::to_string(Overs);
    std::string rounded = num_text.substr(0, num_text.find(".")+2);
    score.setString("Score: "+std::to_string(Score));
    if(tgt[1] == 2)
    {
        wicket.setString("Wickets: "+std::to_string(Wickets)+"/5");
        overs.setString("Overs: "+rounded+" (2.0)");
    }
    if(tgt[1] == 5)
    {
        wicket.setString("Wickets: "+std::to_string(Wickets)+"/10");
        overs.setString("Overs: "+rounded+" (5.0)");
    }
    target.setString("Target: "+std::to_string(chase));
    sf::Time t1 = sf::seconds(2);

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
    window.draw(_ball.Ball);
    window.draw(score);
    window.draw(wicket);
    window.draw(overs);
    window.draw(target);
    if(BowlerTypeShown == false)
    {
        BowlerType.setPosition(350.f,200.f);
        BowlerType.setCharacterSize(50.f);
        window.draw(BowlerType);
    }
    window.setView(sf::View(sf::Vector2f(400.f,300.f),sf::Vector2f(800.f,600.f)));
    window.draw(tile_);
    window.draw(back);
    window.display();
    if(BowlerTypeShown == false)
    {
        sleep(t1);
        BowlerTypeShown = true;
    }
}

void playWindow::call(unsigned* tgt,sf::RenderWindow& window)
{
    this->chase = tgt[0];
    event.key.code = sf::Keyboard::Space;  
    this->initvariables();
    sf::Clock clock;
    gameOver = false;
    _ball.getMarkerPositions(marker_.getPosition().x, marker_.getPosition().y);
    updateBowlerType();
    BowlerTypeShown = false;
    if(_ball.BowlerType == "FAST")
    {
        _ball.updateSwing();
    }
    if(_ball.BowlerType == "SPIN")
    {
        _ball.updateSpin();
    }
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
        if(tgt[1] == 2)
        {
            idealWickets = 5;
        }
        else if(tgt[1] = 5)
        {
            idealWickets = 10;
        }
        if((Score >= chase) || (Overs == tgt[1]) || (Wickets==idealWickets))
        {
            gameOver = true;
        }
        BallHitWicket = false; 
        if(gameOver == false)
        {
            if(_ball.Ball.getPosition().y < window.getSize().y)
            {
                this->defaultscr(window,tgt);
                _ball.updateBallMovement();
                float x = marker_.getPosition().y;
                if(((_ball.Ball.getPosition().y>x-5) && (_ball.Ball.getPosition().y<x+5)) && (BallHitBat == false))
                {
                  _ball.state = "To Wicket";
                  if(clockrestarted == false)
                  {
                    clock.restart();
                    clockrestarted = true;
                  }
                  BallHitMark = true;
                }

                if((bat_[1].getGlobalBounds().contains(_ball.Ball.getPosition())) && (BallHitWicket == false))
                {
                    BallHitBat = true;
                    _ball.state = "Hitted Bat";
                    _ball.getKeyPressed(keypressed);
                }
                if(BallHitBat == true)
                {
                    if(soundplayed == false)
                    {
                        bathitballsound.play();
                        soundplayed = true;
                    }
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
                            Shot.setString("6");
                        }
                        else if(i == 1)
                        {
                            Score = Score + 4;
                            _ball.movementSpeed = _ball.movementSpeed*(0.5);
                            Shot.setString("4");
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
                            _ball.movementSpeed = _ball.movementSpeed*(0.25);
                            Shot.setString("2");
                        }
                        if(i==1)
                        {
                            Score = Score + 1;
                            _ball.movementSpeed = _ball.movementSpeed*(0.125);
                            Shot.setString("1");
                        }
                        scoreUpdated = true;
                        }
                    }
                }
                if(((_ball.Ball.getPosition().y == 550.f) && (_ball.Ball.getPosition().x < 429.f) && (_ball.Ball.getPosition().x > 389.f)) && (BallHitBat == false))
                {
                  this->bail_[0].setPosition(369.f,420.f);
                  this->bail_[1].setPosition(425.f,420.f);
                  BallHitWicket = true;
                  if(wicketUpdated == false)
                  {
                     Wickets = Wickets + 1;
                     wicketUpdated = true;
                  }
                  Shot.setString("Out");
                }
                if(scoreUpdated == false)
                {
                    sf::Vector2f creasepos1 = (*(this->crease_.begin()+2)).getPosition();
                    sf::Vector2f creasepos2 = (*(this->crease_.begin()+3)).getPosition();
                    if((_ball.Ball.getPosition().y == creasepos1.y) && ((_ball.Ball.getPosition().x >= creasepos2.x) || (_ball.Ball.getPosition().x <= creasepos1.x)))
                   {
                      Shot.setString("Wide");
                      Score = Score + 1;
                   }
                }
            }
            if((this->_ball.Ball.getPosition().y >= window.getSize().y) || (this->_ball.Ball.getPosition().y < 0) || (this->_ball.Ball.getPosition().x > window.getSize().x) || (this->_ball.Ball.getPosition().x < 0) || (_ball.Ball.getPosition().x > window.getSize().x))
            {
                bool OverCompleted = false;
                int x = Overs*10;
                if(!(Shot.getString() == "Wide"))
                {
                    if((x-5) % 10 == 0)
                    {
                      Overs = (x+5)/10;
                      OverCompleted = true;
                    }
                else
                {
                  Overs = (x+1)/(float)10;
                }
                }
                Shot.setPosition(400.f,250.f);
                Shot.setCharacterSize(50.f);
                if(Shot.getString() == "4")
                {
                    Shot.setPosition(400.f,500.f);
                    window.draw(this->spritefour);
                    KidsCheerssound.play();
                }
                if(Shot.getString() == "6")
                {
                    Shot.setPosition(400.f,500.f);
                    window.draw(this->spritesix);
                    KidsCheerssound.play();
                }
                if(Shot.getString() == "Out")
                {
                    Shot.setPosition(400.f,500.f);
                    window.draw(this->spritewicket);
                    disappointedchildrensound.play();
                }
                window.draw(Shot);
                window.display();
                sf::Time t1 = sf::seconds(2);
                sleep(t1);
                if(OverCompleted == true)
                {
                    updateBowlerType();
                    BowlerType.setPosition(350.f,200.f);
                    BowlerType.setCharacterSize(50.f);
                    window.draw(BowlerType);
                    window.display();
                    sleep(t1);
                }
                Shot.setString("0");
                _ball.Ball.setPosition(450.f,30.f);
                _ball.state = "To Marker";
                this->updateMarker();
                this->bat_[0].setPosition(415.f,440.f);
                this->bat_[1].setPosition(410.f,460.f);
                this->batsman_.setPosition(195.f,330.f);
                this->bail_[0].setPosition(390.f,450.f);
                this->bail_[1].setPosition(410.f,450.f);
                if(_ball.BowlerType == "FAST")
                {
                  _ball.updateSwing();
                }
                else if(_ball.BowlerType == "SPIN")
                {
                  _ball.updateSpin();
                }
                _ball.updateSwing();
                BallHitMark = false;
                wicketUpdated = false;
                scoreUpdated = false;
                xupdate = false;
                BallHitBat = false;
                soundplayed = false;
                _ball.movementSpeed = 8;
                _ball.theta = 0;
            }
        }

        else
        {
            window.clear(sf::Color::Blue);
            if(Score >= chase)
            {
                window.draw(spritewon);
            }
            else
            {
                window.draw(spritelost);
            }
            window.setView(sf::View(sf::Vector2f(960.f,540.f),sf::Vector2f(1920.f,1080.f)));
            window.display(); 
        }
        this->update();
    }
}        