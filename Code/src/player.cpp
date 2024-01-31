#include "../header/player.hpp"

//implémente la méthode moveleft si on appuie sur left et décrémente la position de x en utilisant la vitesse

void Player::moveLeft()
{
       setX(getX() - getSpeed());
       setDirection(-1);
       _view.move(-getSpeed(),0);
       
}

//implémente la méthode moveRight si on appuie sur right et incrémente la position de x en utilisant la vitesse

void Player::moveRight()
{
        setX(getX() + getSpeed());
        setDirection(1);
        _view.move(getSpeed(),0);
}

void Player::moveUp()
{
        if (getY() > 800){
        setY(getY() - getSpeed()*2);
        _view.move(0,-getSpeed()*2);
        }
}

void Player::moveDown()
{
        if (getY() < 940){
        setY(getY() + getSpeed()*2);
        _view.move(0,getSpeed()*2);
        }
}

bool Player::isCloseTo(const Player &otherPlayer, float distanceThreshold) const {
    float distance = std::sqrt(std::pow(getX() - otherPlayer.getX(), 2) + std::pow((getY() - otherPlayer.getY())*1.7, 2)); //on multiplie par 1.7 pour avoir plus de chance d'attaquer quelq'un sur notre ligne
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
         int randomValue = (std::rand() % 10);

        // Générer un nombre aléatoire entre 1 et 2
        return randomValue;

 }


void Player::reduceHealth( Player& targetPlayer, float damage)
{
    // Réduire l'Hp du joueur cible
    targetPlayer.setHp(targetPlayer.getHp() - damage);

    // Vérifier si l'Hp est tombé à zéro ou moins
    if (targetPlayer.getHp() <= 0)
    {
        targetPlayer.setHp(0); // Assurez-vous que l'Hp ne devienne pas négative
        targetPlayer.setIsAlive(false);
        std::cout << targetPlayer.getLastname() << " is dead" << std::endl;

    }
    std::cout << "Damage infligé : " << getDamage() << "par " << _lastname << std::endl;

    std::cout << targetPlayer.getLastname() << " has now " << targetPlayer.getHp() << " health points" << std::endl;
}


void Player::doFix()
{
    setIsAttacking1(false);
    setIsPicking(false);
    
}

bool Player::isTimetoAttack() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastAttackTime);

        // Check if enough time has passed since the last attack
    return elapsedTime.count() >= 5; // Adjust the cooldown period (5 seconds in this case)
}


bool Player::isTimetoPick() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastPickTime);

        // Check if enough time has passed since the last attack
    return elapsedTime.count() >= 5; // Adjust the cooldown period (5 seconds in this case)
}

bool Player::isTimeToFix() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastAttackTime);

    return elapsedTime.count() >= 1;
}

bool Player::isBehind(const Player &otherPlayer) const {
    return (getX() < otherPlayer.getX());
}

void Player::doPick(Fruit& targetFruit, float distanceThreshold)
{


    if (isCloseToFruit(targetFruit, distanceThreshold))
    {
        // Check the name of the target fruit and the specific conditions for each player
        if ((targetFruit.getName() == "Masque du Hollow" && getFirstname() == "Ichigo") ||
            (targetFruit.getName() == "Gomu Gomu fruit" && getFirstname() == "Luffy") ||
            targetFruit.getName() == "Fruit Normal")
        {
            // Check if the fruit is alive before picking
            if (targetFruit.isAlive())
            {
                std::cout << getLastname() << " is picking up " << targetFruit.getName() << std::endl;
                std::cout << "Hp avant : " << _Hp << std::endl;

                // Increase the player's Hp by the energy of the fruit
                _Hp += targetFruit.getEnergy();
                if (_Hp > _HpMax)
                {
                    _Hp = _HpMax;
                }

                std::cout << "Hp apres : " << _Hp << std::endl;

                // Set isAlive to false to mark the fruit as picked
                targetFruit.setIsAlive(false);
            }
            else
            {
                std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << " - Already picked" << std::endl;
            }
        }
        else
        {
            std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << " - Not the right player for this fruit" << std::endl;
        }
    }
    else
    {
        std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << " - Not close enough" << std::endl;
    }

    _isPicking = true;  // You may want to reconsider setting _isPicking to true here
}


