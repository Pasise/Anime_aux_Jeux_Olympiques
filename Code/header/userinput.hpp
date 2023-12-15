#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.hpp"

class Input
{ 
public: 
    Input();
    Button getButton(void) const {return _button;}
    void GestionDesInputs(sf::Event event, sf::RenderWindow &windown);


private: 
Button _button;

};