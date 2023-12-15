#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.hpp"

class UserInput
{ 
public: 
    UserInput();
    UserInput(Button button);
    Button getButton(void) const {return _button;}
    void manageInput(sf::Event event, sf::RenderWindow &windown);


private: 
Button _button;

};