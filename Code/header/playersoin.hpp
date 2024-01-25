#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerSoin : public Player
{
protected:
    float _heal;
    bool _isHealing;
    TimePoint _lastHealTime;

public:
    PlayerSoin(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float damage, float soin, std::map<std::string, int> textureAssociations, std::string deathTexturePath);
    ~PlayerSoin() {};
    void doHeal();
    bool isHealing(){return _isHealing;};
    void doFix3();
    void doAttack1(Player& targetPlayer); //
    void doJump();
    void randomAttack(Player& targetPlayer);
    bool canAttack() const;
    bool isTimetoHeal() const;
    void setLastHealTime() {
        _lastHealTime = Clock::now();
    }
};