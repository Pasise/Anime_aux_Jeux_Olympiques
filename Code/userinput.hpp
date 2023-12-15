#pragma once 
#include <SFML/Graphics.hpp>

class Input
{ 
    struct Boutton { bool left, right, up, down, space, escape,attack; };

public: 
    Input();
    Boutton getBoutton(void) const;
    void GestionDesInputs(sf::Event event, sf::RenderWindow &windown);


private: 
Boutton boutton;


};