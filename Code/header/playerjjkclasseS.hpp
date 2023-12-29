#pragma once

#include "playerjjkclasse1.hpp"
#include <SFML/Graphics.hpp>

class PlayerJJKClasseS : public PlayerJJKClasse1
{
protected:
    float _occultenergy;
    float _color;

public:
    PlayerJJKClasseS(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::map<std::string, int> textureAssociations);
    ~PlayerJJKClasseS() {};
    void doAttack1(Player& targetPlayer); //Invocation
    void doAttack2();
    void doAttack3(); //Extension
    void doAttack4();
    void doJump();
    void doPick();

    bool checkCollision(PlayerJJK* otherPlayer);
};

