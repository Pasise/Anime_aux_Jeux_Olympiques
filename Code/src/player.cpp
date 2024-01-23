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


bool Player::isCloseTo(const Player &otherPlayer, float distanceThreshold) const {
    float distance = std::sqrt(std::pow(getX() - otherPlayer.getX(), 2) + std::pow(getY() - otherPlayer.getY(), 2));
    //std::cout << "Distance between " << " is " << distance << std::endl;
    return (distance < distanceThreshold);
}

bool Player::isCloseToFruit(const Fruit &targetFruit, float distanceThreshold) const {
    float distance = std::sqrt(std::pow(getX() - targetFruit.getX(), 2) + std::pow(getY() - targetFruit.getY(), 2));
    //std::cout << "Distance between " << " is " << distance << std::endl;
    return (distance < distanceThreshold);
}

int Player::getRandomNumberForCanAttack() const {
        // Obtenir le temps actuel en secondes depuis l'époque
        auto currentTime = std::chrono::system_clock::now();
        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
        auto timeInSeconds = seconds.time_since_epoch().count();

        // Utiliser le temps comme graine pour la génération de nombres aléatoires
        std::srand(static_cast<unsigned int>(timeInSeconds));
         int randomValue = (std::rand() % 3);

        // Générer un nombre aléatoire entre 1 et 2
        return randomValue;

 }

bool Player::canAttack() const {

    // Générez une valeur aléatoire pour déterminer si le joueur peut attaquer
    int randomValue = getRandomNumberForCanAttack();

    // Le joueur peut attaquer si la valeur aléatoire est 1 donc 50% de chance
    return randomValue == 1;
}


void Player::reduceHealth( Player& targetPlayer)
{
    // Réduire l'XP du joueur cible
    targetPlayer.setXp(targetPlayer.getXp() - getDamage());

    // Vérifier si l'XP est tombé à zéro ou moins
    if (targetPlayer.getXp() <= 0)
    {
        targetPlayer.setXp(0); // Assurez-vous que l'XP ne devienne pas négative
        targetPlayer.setIsAlive(false);
        std::cout << targetPlayer.getLastname() << " is dead" << std::endl;

    }

    std::cout << targetPlayer.getLastname() << " has now " << targetPlayer.getXp() << " health points" << std::endl;
}


void Player::doFix()
{
    setIsAttacking1(false);
    setIsJumping(false);
    setIsPicking(false);
    
}

bool Player::isTimetoAttack() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastAttackTime);

        // Check if enough time has passed since the last attack
    return elapsedTime.count() >= 5; // Adjust the cooldown period (5 seconds in this case)
}




