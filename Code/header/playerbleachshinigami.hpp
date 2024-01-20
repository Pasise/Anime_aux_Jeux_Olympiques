#pragma once

#include "playerbleach.hpp"
#include <SFML/Graphics.hpp>

class PlayerBleachShinigami : public PlayerBleach
{
protected:
    float _soin;

public:
    PlayerBleachShinigami(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations);
    ~PlayerBleachShinigami() {};
    void doAttack1(Player& targetPlayer); //
    void doJump();
    void doPick();
};

