#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class PlayerJJK : public Player
{
    public :
    void virtual doAttack1(Player& targetPlayer)=0;
    void virtual doAttack2(Player& targetPlayer)=0;
    void virtual doAttack3(Player& targetPlayer)=0;
    void virtual doAttack4(Player& targetPlayer)=0;
    void virtual doJump()=0;
    void virtual doPick()=0;
    protected :
    float _occultenergy;
    float _color;

};