#include "../header/playerplus.hpp"

PlayerPlus::PlayerPlus(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath):PlayerMedium(lastname, firstname, Xp, Xp_max, speed, x, y, damage, textureAssociations, deathTexturePath)
{

    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _XpMax = Xp_max;
    _speed = speed;
    _x = x;
    _y = y;
    addAssociations(textureAssociations);
    _direction = 1;
    _isAttacking1 = false;
    _isJumping = false;
    _isPicking = false;
    _isAttacking2 = false;
    _isAlive = true;
    std::cout << "PlayerPlus created" << std::endl;
}

void PlayerPlus::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    targetPlayer.reduceHealth(targetPlayer);
    _isAttacking1 = true;
}

void PlayerPlus::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    targetPlayer.reduceHealth(targetPlayer);
    _isAttacking2 = true;
}

void PlayerPlus::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
}

void PlayerPlus::doPick(Fruit& targetFruit)
{
    // Check if the target fruit is close enough and has the desired name
    float distanceThreshold = 1000.0f;  // Adjust the distance threshold as needed
    if (isCloseToFruit(targetFruit, distanceThreshold) && (targetFruit.getName() == "Gomu Gomu fruit" || targetFruit.getName() == "Fruit Normal"))
    {
        // Check if the fruit is alive before picking
        if (targetFruit.isAlive())
        {
            std::cout << getLastname() << " is picking up " << targetFruit.getName() << std::endl;
            std::cout << "Xp avant : " << _Xp << std::endl;
            
            // Augmenter les xp du joueur de l'énergie du fruit 
            _Xp += targetFruit.getEnergy();
            
            std::cout << "Xp apres : " << _Xp << std::endl;

            // Set isAlive to false to mark the fruit as picked
            targetFruit.setIsAlive(false);
            _isPicking = true;
        }
        else
        {
            std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << " - Already picked" << std::endl;
        }
    }
    else
    {
        std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << std::endl;
    }

}


int PlayerPlus::getRandomNumberForRandomAttack() const {
        // Obtenir le temps actuel en secondes depuis l'époque
        auto currentTime = std::chrono::system_clock::now();
        // Convertir le temps en nombre entier représentant le nombre de secondes
        auto currentTimeInSeconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
        // Obtenir la durée écoulée depuis l'époque
        auto epoch = currentTimeInSeconds.time_since_epoch();
        // Convertir la durée en secondes
        auto value = std::chrono::duration_cast<std::chrono::seconds>(epoch);
        // Obtenir le nombre de secondes écoulées depuis l'époque
        auto duration = value.count();
        // Utiliser le nombre de secondes comme graine pour le générateur de nombres aléatoires
        std::srand(duration);
        // Générer un nombre aléatoire entre 1 et 3
        int randomNumber = std::rand() % 3 + 1;
        return randomNumber;
    }
void PlayerPlus::doFix2()
{
    _isAttacking2 = false;
    
}

void PlayerPlus::randomAttack(Player& targetPlayer)
{
    int randomValue = getRandomNumberForRandomAttack();
    if (randomValue == 1)
    {
        doAttack1(targetPlayer);
    }
    else if (randomValue == 2)
    {
        doAttack2(targetPlayer);
    }
    
}


bool PlayerPlus::canAttack() const {

    // Générez une valeur aléatoire pour déterminer si le joueur peut attaquer
    int randomValue = getRandomNumberForCanAttack();

    // Le joueur peut attaquer si la valeur aléatoire est 1 donc 50% de chance
    return randomValue == 2;
}