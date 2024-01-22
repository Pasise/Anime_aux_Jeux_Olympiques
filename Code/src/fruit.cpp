#include "../header/fruit.hpp"

Fruit::Fruit(std::string name, float x, float y, float energy, std::string texturePath)
{
    _name = name;
    _x = x;
    _y = y;
    _energy = energy;
    _isAlive = true;
    _texturePath = texturePath;
    
}


