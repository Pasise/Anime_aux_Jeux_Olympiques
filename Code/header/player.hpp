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
    int _direction;

    public : 
    void moveLeft();
    void moveRight();
    float getX(){return _x;}
    float getY(){return _y;}
    float getSpeed(){return _speed;}
    float getXp(){return _Xp;}
    int getDirection(){return _direction;}
    std::string getLastname(){return _lastname;}
    std::string getFirstname(){return _firstname;}
    void setX(float x){_x = x;}
    void setY(float y){_y = y;}
    void setSpeed(float speed){_speed = speed;}
    void setXp(float Xp){_Xp = Xp;}
    void setDirection(int direction){_direction = direction;}
    void virtual doAttack1()=0;
    void virtual doAttack2()=0;
    void virtual doAttack3()=0;
    void virtual doAttack4()=0;
    void virtual doJump()=0;
    void virtual doPick()=0;
    virtual std::string getTexture() = 0;




}; 