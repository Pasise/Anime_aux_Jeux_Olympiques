#pragma once

#include "playerjjk.hpp"
#include <SFML/Graphics.hpp>

class PlayerJJKClasse1 : public PlayerJJK
{
protected:
    float _occultenergy;
    float _color;

public:
    PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color,std::map<std::string, int> textureAssociations);
    ~PlayerJJKClasse1() {};
    void doAttack1(Player& targetPlayer); //Invocation
    void doAttack2(Player& targetPlayer);
    void doAttack3(Player& targetPlayer); //Extension
    void doAttack4(Player& targetPlayer);
    void doJump();
    void doPick();
};

