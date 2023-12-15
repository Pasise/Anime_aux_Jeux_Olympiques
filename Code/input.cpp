#include "input.hpp"

Input::Input()  // On initialise les bouttons à false
{
    boutton.left = false;
    boutton.right = false;
    boutton.up = false;
    boutton.down = false;
    boutton.space = false;
    boutton.escape = false;
}

//Accéder aux inormations private de bouttons
Input::Boutton Input::getBoutton(void) const
{
    return boutton;
}

//Gestion des inputs

void Input::GestionDesInputs(sf::Event event, sf::RenderWindow &windown)
{
    //On ferme la fenêtre si on appuie sur la croix
    if(event.type == sf::Event::Closed)
    {
        windown.close();
    }

    //On gère les inputs 
    //Si on appuie sur une touche, on met le boutton correspondant à true
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Left:
                boutton.left = true;
                break;

            case sf::Keyboard::Right:
                boutton.right = true;
                break;

            case sf::Keyboard::Up:
                boutton.up = true;
                break;

            case sf::Keyboard::Down:
                boutton.down = true;
                break;

            case sf::Keyboard::Space:
                boutton.space = true;
                break;

            case sf::Keyboard::Escape:
                boutton.escape = true;
                break;

            default:
                break;
        }
    }

    //Si on relâche une touche, on met le boutton correspondant à false
    if(event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Left:
                boutton.left = false;
                break;

            case sf::Keyboard::Right:
                boutton.right = false;
                break;

            case sf::Keyboard::Up:
                boutton.up = false;
                break;

            case sf::Keyboard::Down:
                boutton.down = false;
                break;

            case sf::Keyboard::Space:
                boutton.space = false;
                break;

            case sf::Keyboard::Escape:
                boutton.escape = false;
                break;

            default:
                break;
        }
    }

    //On gère la souris
    if(event.type == sf::Event::MouseButtonPressed)
    {
       if(event.mouseButton.button == sf::Mouse::Left)
       {
           boutton.attack = true;
       }
    }

    if(event.type == sf::Event::MouseButtonReleased)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
       {
           boutton.attack = false;
       }
    }
      
}