#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerSoin : public Player
{
protected:
    float _soin;

public:
    PlayerSoin(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations);
    ~PlayerSoin() {};
    void doAttack1(Player& targetPlayer); //
    void doJump();
    void doPick(Fruit& targetFruit);
    void randomAttack(Player& targetPlayer);
};