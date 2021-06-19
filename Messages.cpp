#include "Messages.h"
#include <iostream>
messagesWindow::messagesWindow()
{
    /// setting up welcome background

    if (!this->Wlcmtexture.loadFromFile("images/welcome.jpg"))
        ;
    this->Wlcmsprite.setTexture(this->Wlcmtexture);
    sf::Vector2u bgsize = this->Wlcmtexture.getSize();
    Wlcmsprite.setScale(960 / static_cast<float>(bgsize.x), 540 / static_cast<float>(bgsize.y));
    Wlcmsprite.setPosition(200.f, 100.f);
}
void messagesWindow::call(sf::RenderWindow &window)
{
    window.clear();
    window.draw(Wlcmsprite);
    window.setView(sf::View(sf::Vector2f(960.f, 540.f), sf::Vector2f(1920.f, 1080.f)));
    window.display();
    event.key.code = sf::Keyboard::Space;
    while (true)
    {
        if (window.pollEvent(this->event))
            if (this->event.type == sf::Event::KeyPressed || this->event.key.code == sf::Keyboard::Escape)
                break;
    }
}