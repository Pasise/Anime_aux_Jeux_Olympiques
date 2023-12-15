#include "userinput.hpp"

Input::Input() {}

//Gestion des inputs

void Input::GestionDesInputs(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            _button = Button::left;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            _button = Button::right;
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            _button = Button::up;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            _button = Button::down;
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            _button = Button::space;
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            _button = Button::escape;
        }
        else if (event.key.code == sf::Keyboard::A)
        {
            _button = Button::attack;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            _button = Button::left;
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            _button = Button::right;
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            _button = Button::up;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            _button = Button::down;
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            _button = Button::space;
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            _button = Button::escape;
        }
        else if (event.key.code == sf::Keyboard::A)
        {
            _button = Button::attack;
        }
    }
    else if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}