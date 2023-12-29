#pragma once

#include "playeronepiece.hpp"
#include <SFML/Graphics.hpp>

class PlayerOnePieceMugiwara : public PlayerOnePiece 
{
protected:
    float _vol;

public:
    PlayerOnePieceMugiwara(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float vol, std::map<std::string, int> textureAssociations);
    ~PlayerOnePieceMugiwara() {};
    void doAttack1(Player& targetPlayer); //
    void doAttack2(Player& targetPlayer);
    void doAttack3(Player& targetPlayer); //
    void doAttack4(Player& targetPlayer);
    void doJump();
    void doPick();
};

