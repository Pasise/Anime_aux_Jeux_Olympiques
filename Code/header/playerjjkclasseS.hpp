#pragma once

#include "playerjjkclasse1.hpp"
#include <SFML/Graphics.hpp>

class PlayerJJKClasseS : public PlayerJJKClasse1
{
protected:
    float _occultenergy;
    float _color;
    std::string _texture; 

public:
    PlayerJJKClasseS(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::string texturepath);
    ~PlayerJJKClasseS() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(); //Invocation
    void doAttack2();
    void doAttack3(); //Extension
    void doAttack4();
    void doJump();
    void doPick();
};

