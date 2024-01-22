#include "../header/fruit.hpp"

Fruit::Fruit(std::string name,float y,float energy, std::string texturePath)
{
    srand(time(NULL));
    _name = name;
    _x = std::rand() % 1920;
    _y = y;
    _energy = energy;
    _isAlive = true;
    _texturePath = texturePath;
    
}

