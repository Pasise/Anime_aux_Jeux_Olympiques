#pragma once

#include "playerjjk.hpp"
#include <SFML/Graphics.hpp>

class PlayerJJKClasse1 : public PlayerJJK
{
protected:
    float _occultenergy;
    float _color;
    std::string _texture;  // Ajout de l'attribut texture

public:
    PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::string texturepath);
    ~PlayerJJKClasse1() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(); //Invocation
    void doAttack2();
    void doAttack3(); //Extension
    void doAttack4();
    void doJump();
    void doPick();
};

