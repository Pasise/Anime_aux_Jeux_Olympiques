#include "../header/fruit.hpp"
#include <random>


std::unordered_set<float> Fruit::usedXCoordinates;
std::unordered_set<float> Fruit::usedYCoordinates;

Fruit::Fruit(std::string name, float energy, std::string texturePath)
    : _name(name), _energy(energy), _isAlive(true), _texturePath(texturePath) {
    setX(getRandomNumberForX());
    setY(getRandomNumberForY());
}

void Fruit::setX(float x) {
    // Add the x-coordinate to the set of used x-coordinates
    usedXCoordinates.insert(x);
    _x = x;
}

int Fruit::getRandomNumberForX() const {
    srand(time(NULL));
    float newX;

    // Generate a new x-coordinate until a unique one is found
    do {
        newX = std::rand() % 1800;
    } while (usedXCoordinates.count(newX) > 0);

    return newX;
}

void Fruit::setY(float y) {
    // Add the y-coordinate to the set of used y-coordinates
    usedYCoordinates.insert(y);
    _y = y;
}

int Fruit::getRandomNumberForY() const {
    srand(time(NULL));
    float newY;
    int rand1= rand() % 2;
    int rand2= rand() % 2;
    int rand3= rand() % 2;


    if (_name == "Gomu Gomu fruit") {
        if (rand1 == 1) {
            newY = 627.0f;
        } else {
            newY = 627.0f;
        }
    } else if (_name == "Masque du Hollow") {
        if (rand2 == 1) {
            newY = 725.0f;
        } else {
            newY = 580.0f;
        }
    } else if (_name == "Fruit Normal") {
        if (rand3 == 1) {
            newY = 830.0f;
        } else {
            newY = 680.0f;
        }
    }

    return newY;
}


