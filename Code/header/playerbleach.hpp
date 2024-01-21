#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class PlayerBleach : public Player
{
    public :
    void virtual doAttack1(Player& targetPlayer)=0;
    void virtual doJump()=0;
    void virtual doPick()=0;
    protected :
    float _soin;

};