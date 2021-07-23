#include "helpWindow.h"
#include "menuWindow.h"
#include "levelsWindow.h"
#include "playWindow.h"
#include "aboutWindow.h"
#include "testobjects.h"
int main(int argc,char** argv)
{
    /// creating object for window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Crazy Cricketing Champs",sf::Style::Fullscreen);
    
    /// creating objects for the various windows
    helpWindow help;
    menuWindow menu;
    levelsWindow levels;
    playWindow play;
    aboutWindow about;
    unsigned* arr;
    play.startmusic();
    play.renderwelcome(*window);
    /// switching between the various windows
    jump_t jumpTo;
    Menu: jumpTo = menu.call(*window);
    switch(jumpTo)
    {
        case jump_t::CLOSE: goto Close;
        case jump_t::LEVELS: goto lvl;
        case jump_t::HELP: goto Help;
        case jump_t::ABOUT: goto About;
    }
    lvl: arr = levels.call(*window);
    Play: play.call(arr,*window);
    goto Menu;
    Help: help.call(*window);
    goto Menu;
    About: about.call(*window);
    goto Menu;
    Close: return 0;

    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}