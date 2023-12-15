#include "input.hpp"

Input::Input() {}

//Gestion des inputs

void Input::GestionDesInputs(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            boutton = Boutton::left;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            boutton = Boutton::right;
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            boutton = Boutton::up;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            boutton = Boutton::down;
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            boutton = Boutton::space;
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            boutton = Boutton::escape;
        }
        else if (event.key.code == sf::Keyboard::A)
        {
            boutton = Boutton::attack;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            boutton = Boutton::left;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            boutton = Boutton::right;
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            boutton = Boutton::up;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            boutton = Boutton::down;
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            boutton = Boutton::space;
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            boutton = Boutton::escape;
        }
        else if (event.key.code == sf::Keyboard::A)
        {
            boutton = Boutton::attack;
        }
    }
    else if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}