#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.hpp"

class UserInput
{ 
public: 
    UserInput();
    UserInput(Button button);
    UserInput(sf::Event event, sf::RenderWindow &window);
    Button getButton(void) const {return _button;}
    void manageInput(sf::Event event, sf::RenderWindow &window);


private: 
Button _button;

};