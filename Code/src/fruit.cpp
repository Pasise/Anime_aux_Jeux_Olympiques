#include "../header/fruit.hpp"

std::unordered_set<float> Fruit::usedXCoordinates;

Fruit::Fruit(std::string name, float y, float energy, std::string texturePath)
    : _name(name), _y(y), _energy(energy), _isAlive(true), _texturePath(texturePath) {
    setX(getRandomNumberForX());
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

