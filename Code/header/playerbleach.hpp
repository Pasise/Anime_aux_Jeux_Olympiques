#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class PlayerBleach : public Player
{
    public :
    void virtual doAttack1(Player& targetPlayer)=0;
    void virtual doAttack2()=0;
    void virtual doAttack3()=0;
    void virtual doAttack4()=0;
    void virtual doJump()=0;
    void virtual doPick()=0;
    virtual std::string getTexture()= 0;
    protected :
    float _soin;
    

};