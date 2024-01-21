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

void Player::randomAttack(Player& targetPlayer)
{
    int random = rand() % 4 + 1; // lance une attaque aléatoire entre attack1 et attack4
    if (random == 1) 
        doAttack1(targetPlayer);
}

bool Player::isCloseTo(const Player &otherPlayer, float distanceThreshold) const {
    float distance = std::sqrt(std::pow(getX() - otherPlayer.getX(), 2) + std::pow(getY() - otherPlayer.getY(), 2));
    //std::cout << "Distance between " << " is " << distance << std::endl;
    return (distance < distanceThreshold);
}

bool Player::canAttack() const
{
    // Initialisation de la graine pour la génération de nombres aléatoires
    std::srand(std::time(0));

    // Générer un nombre aléatoire entre 0 et 1
    int randomValue = std::rand() % 2;

    if(randomValue == 1)
        std::cout << "Attack possible" << std::endl;
    else
        std::cout << "Attack impossible" << std::endl;

    // Si la valeur aléatoire est 1, le personnage peut attaquer, sinon non
    return (randomValue == 1);
}

bool Player::canAttackNow() const {
        // Générer un nombre aléatoire entre 0 et 1
        int randomValue = std::rand() % 2;
        return (randomValue == 1 && _canAttack);
}

void Player::reduceHealth(float damage,Player& targetPlayer)
{
    targetPlayer.setXp(targetPlayer.getXp()-damage);
    std::cout << targetPlayer.getLastname() << " has lost " << damage << " health points" << std::endl;
    std::cout << targetPlayer.getLastname() << " has now " << targetPlayer.getXp() << " health points" << std::endl;
}

void Player::doFix()
{
    setIsAttacking1(false);
    setIsJumping(false);
    setIsPicking(false);
    
}

int Player::getRandomNumberForCanAttack() const {
        // Obtenir le temps actuel en secondes depuis l'époque
        auto currentTime = std::chrono::system_clock::now();
        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
        auto timeInSeconds = seconds.time_since_epoch().count();

        // Utiliser le temps comme graine pour la génération de nombres aléatoires
        std::srand(static_cast<unsigned int>(timeInSeconds));
         int randomValue = (std::rand() % 3);
        std::cout << "random value far Can Attack: " << randomValue << std::endl;

        // Générer un nombre aléatoire entre 1 et 2
        return randomValue;

 }