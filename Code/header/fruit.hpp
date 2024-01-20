#pragma once 
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "userinput.hpp"
#include "object.hpp"

class Fruit: public Object{
    protected : 
    std::string _name;
    float _x;
    float _y;
    float _energy;
    bool _isAlive;

};