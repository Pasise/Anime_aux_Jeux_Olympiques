#include "../header/userinput.hpp"

Input::Input() {}

//Gestion des inputs

void Input::GestionDesInputs(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Q)
        {
            _button = Button::left;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            _button = Button::right;
        }
        else if (event.key.code == sf::Keyboard::A)
        {
            _button = Button::attack1;
        }
        else if (event.key.code == sf::Keyboard::Z)
        {
            _button = Button::attack2;
        }
        else if (event.key.code == sf::Keyboard::E)
        {
            _button = Button::attack3;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            _button = Button::attack4;
        }
        else if (event.key.code == sf::Keyboard::R)
        {
            _button = Button::pick;
        }
    }
}