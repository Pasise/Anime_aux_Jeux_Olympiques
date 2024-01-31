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
    static std::unordered_set<float> usedXCoordinates;  // Variable static pour stocker les x-coordonnées utilisées
    static std::unordered_set<float> usedYCoordinates;  // Variable static pour stocker les y-coordonnées utilisées

public:
    Fruit(std::string name, float energy, std::string texturePath);
    ~Fruit() {};
    std::string getName() const { return _name; }
    float getX() const { return _x; }
    float getY() const { return _y; }
    float getEnergy() const { return _energy; }
    bool isAlive() const { return _isAlive; }
    void setX(float x);
    void setY(float y);
    void setIsAlive(bool isAlive) { _isAlive = isAlive; }
    void loadTexture(){ _texture.loadFromFile(_texturePath); _sprite.setTexture(_texture);}
    void setTexturePath(std::string texturePath) { _texturePath = texturePath; loadTexture(); }
    std::string getTexturePath() const { return _texturePath; }
    sf::Sprite getSprite() const { return _sprite; }
    sf::Texture getTexture() const { return _texture; }
    int getRandomNumberForX() const;
    int getRandomNumberForY() const;
};
