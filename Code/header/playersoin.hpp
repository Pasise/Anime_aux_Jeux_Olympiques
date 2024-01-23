#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerSoin : public Player
{
protected:
    float _heal;
    bool _isHealing;

public:
    PlayerSoin(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations);
    ~PlayerSoin() {};
    void doHeal();
    bool isHealing(){return _isHealing;};
    void doFix3();
    void doAttack1(Player& targetPlayer); //
    void doJump();
    void doPick(Fruit& targetFruit);
    void randomAttack(Player& targetPlayer);
};