#pragma once

#include "playerbleach.hpp"
#include <SFML/Graphics.hpp>

class PlayerBleachShinigami : public PlayerBleach
{
protected:
    float _occultenergy;
    float _color;
    std::string _texture;  // Ajout de l'attribut texture

public:
    PlayerBleachShinigami(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::string texturepath);
    ~PlayerBleachShinigami() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(); //
    void doAttack2();
    void doAttack3(); //
    void doAttack4();
    void doJump();
    void doPick();
};

