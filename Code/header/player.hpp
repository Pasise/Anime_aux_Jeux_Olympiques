#pragma once 
#include <iostream>
#include "userinput.hpp"
class Player{
    protected :
    std::string _lastname;
    std::string _firstname;
    float _Xp;
    float _speed;
    float _x;
    float _y;

    public : 
    void moveLeft();
    void moveRight();
    void virtual run() = 0; 
    void virtual doAttack1()=0;
    void virtual doAttack2()=0;
    void virtual doAttack3()=0;
    void virtual doAttack4()=0;
    void jump();
    void pick();




}; 