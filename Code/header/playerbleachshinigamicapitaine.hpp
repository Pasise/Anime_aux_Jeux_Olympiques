#pragma once 

#include "playerbleachshinigami.hpp"
#include <SFML/Graphics.hpp>

class PlayerBleachShinigamiCapitaine : public PlayerBleachShinigami
{
protected:
    float _soin;
    std::string _texture;

public:
    PlayerBleachShinigamiCapitaine(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::string texturepath);
    ~PlayerBleachShinigamiCapitaine() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(); //
    void doAttack2();
    void doAttack3(); //
    void doAttack4();
    void doJump();
    void doPick();

};