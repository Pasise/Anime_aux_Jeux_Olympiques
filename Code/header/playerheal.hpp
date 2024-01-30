#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerHeal : public Player
{
protected:
    float _heal;
    bool _isHealing;
    TimePoint _lastHealTime;

public:
    PlayerHeal(std::string lastname, std::string firstname, float Xp,float Xp_max,float Xp_multiplier, float x, float y, float damage, float Heal, std::map<std::string, int> textureAssociations, std::string deathTexturePath);
    ~PlayerHeal() {};
    void doHeal();
    bool isHealing(){return _isHealing;};
    void doFix() override;
    void doAttack1(Player& targetPlayer); //
    void randomAttack(Player& targetPlayer);
    bool canAttack() const;
    bool isTimetoHeal() const;
    void setLastHealTime() {
        _lastHealTime = Clock::now();
    }
};