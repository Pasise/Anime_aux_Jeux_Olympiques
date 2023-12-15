#pragma once 
#include <iostream>

class Player{
    protected :
    std::string _lastname;
    std::string _firstname;
    float _Xp;
    float _speed;
    float _x;
    float _y;

    public : 
    void virtual run() = 0; 
    void virtual toAttack() = 0;
    void virtual beAttacked() = 0; 



}; 