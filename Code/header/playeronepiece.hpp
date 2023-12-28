#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class PlayerOnePiece : public Player
{
    public :
    void virtual doAttack1()=0;
    void virtual doAttack2()=0;
    void virtual doAttack3()=0;
    void virtual doAttack4()=0;
    void virtual doJump()=0;
    void virtual doPick()=0;

    protected :
    float _vol;

};