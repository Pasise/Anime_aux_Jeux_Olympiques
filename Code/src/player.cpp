#include "../header/player.hpp"

//implémente la méthode moveleft si on appuie sur left et décrémente la position de x en utilisant la vitesse

void Player::moveLeft()
{
       setX(getX() - getSpeed());
       setDirection(-1);
}

//implémente la méthode moveRight si on appuie sur right et incrémente la position de x en utilisant la vitesse

void Player::moveRight()
{
        setX(getX() + getSpeed());
        setDirection(1);
}

void Player::randomAttack()
{
    int random = rand() % 4 + 1; // lance une attaque aléatoire entre attack1 et attack4
    if (random == 1) 
        doAttack1();
    else if (random == 2)
        doAttack2();
    else if (random == 3)
        doAttack3();
    else
        doAttack4();
}

bool Player::isCloseTo(const Player &otherPlayer, float distanceThreshold) const {
    float distance = std::sqrt(std::pow(getX() - otherPlayer.getX(), 2) + std::pow(getY() - otherPlayer.getY(), 2));
    //std::cout << "Distance between " << " is " << distance << std::endl;
    return (distance < distanceThreshold);
}