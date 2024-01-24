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

std::default_random_engine generator;  // Initialisation du générateur de nombres aléatoires
int Fruit::getRandomNumberForY() const {
  std::uniform_int_distribution<int> distribution(0, 1); // Distribution pour obtenir 0 ou 1

    float newY;
    if (distribution(generator) == 0) {
        newY = 600.0f;
    } else {
        newY = 740.0f;
    }

    return newY;

    return newY;
}

