#pragma once
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "userinput.hpp"
#include "object.hpp"

class Fruit : public Object {
protected:
    std::string _name;
    float _x;
    float _y;
    float _energy;
    bool _isAlive;
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _texturePath;
    static std::unordered_set<float> usedXCoordinates;  // Static set to store used x-coordinates

public:
    Fruit(std::string name, float y, float energy, std::string texturePath);
    ~Fruit() {};
    std::string getName() const { return _name; }
    float getX() const { return _x; }
    float getY() const { return _y; }
    float getEnergy() const { return _energy; }
    bool isAlive() const { return _isAlive; }
    void setX(float x);
    void setY(float y) { _y = y; }
    void setIsAlive(bool isAlive) { _isAlive = isAlive; }
    void reduceEnergy(float damage);
    void loadTexture();
    void setTexturePath(std::string texturePath) { _texturePath = texturePath; loadTexture(); }
    std::string getTexturePath() const { return _texturePath; }
    sf::Sprite getSprite() const { return _sprite; }
    sf::Texture getTexture() const { return _texture; }
    int getRandomNumberForX() const;
};
