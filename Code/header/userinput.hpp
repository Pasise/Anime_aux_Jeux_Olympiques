#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "boutton.hpp"

class Input
{ 
public: 
    Input();
    Boutton getBoutton(void) const {return boutton;}
    void GestionDesInputs(sf::Event event, sf::RenderWindow &windown);


private: 
Boutton boutton;

};