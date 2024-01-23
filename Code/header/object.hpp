#pragma once 
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "userinput.hpp"

class Object{
    protected :
    std::string _name;
    float _x;
    float _y;
    
    bool _isAlive;
    public : 
    void setIsAlive(bool value){
        _isAlive = value;
    }
    bool isAlive() const {
        return _isAlive;
    }
    
};