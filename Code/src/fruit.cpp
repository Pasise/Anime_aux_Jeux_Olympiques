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
    // Ajouter la coordonnée x au set des x-coordonnées utilisées
    usedXCoordinates.insert(x);
    _x = x;
}

int Fruit::getRandomNumberForX() const {
    srand(time(NULL));
    float newX;

    // GGenerer une coordonnée x aléatoire entre 1250 et 3650
    do {

        newX = (rand() % 2400) + 1250;
    } while (usedXCoordinates.count(newX) > 0);

    return newX;
}

void Fruit::setY(float y) {
    // Ajouter la coordonnée y au set des y-coordonnées utilisées
    usedYCoordinates.insert(y);
    _y = y;
}

//Generer une des coordonnées y aléatoirement possibles entre les 2 lignes pour chaque fruit
int Fruit::getRandomNumberForY() const {
    srand(time(NULL));
    float newY;
    int rand1= rand() % 2;
    int rand2= rand() % 2;
    int rand3= rand() % 2;


    if (_name == "Gomu Gomu fruit") {
        if (rand1 == 1) {
            newY = 1005.0f;
        } else {
            newY = 857.0f;
        }
    } else if (_name == "Masque du Hollow") {
        if (rand2 == 0) {
            newY = 955.0f;
        } else {
            newY = 810.0f;
        }
    } else if (_name == "Fruit Normal") {
        if (rand3 == 1) {
            newY = 1060.0f;
        } else {
            newY = 910.0f;
        }
    }

    return newY;
}


