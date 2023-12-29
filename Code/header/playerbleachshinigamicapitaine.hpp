#pragma once 

#include "playerbleachshinigami.hpp"
#include <SFML/Graphics.hpp>

class PlayerBleachShinigamiCapitaine : public PlayerBleachShinigami
{
protected:
    float _soin;

public:
    PlayerBleachShinigamiCapitaine(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations);
    ~PlayerBleachShinigamiCapitaine() {};
    void doAttack1(Player& targetPlayer); //
    void doAttack2(Player& targetPlayer);
    void doAttack3(Player& targetPlayer); //
    void doAttack4(Player& targetPlayer);
    void doJump();
    void doPick();

};