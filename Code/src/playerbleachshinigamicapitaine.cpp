#include "../header/playerbleachshinigamicapitaine.hpp"

PlayerBleachShinigamiCapitaine::PlayerBleachShinigamiCapitaine(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations)
: PlayerBleachShinigami(lastname, firstname, Xp, speed, x, y, soin, textureAssociations)
{

    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _soin = soin;
    addAssociations(textureAssociations);
    _direction = 1;
    _isAttacking1 = false;
    _isAttacking2 = false;
    _isJumping = false;
    _isPicking = false;
    std::cout << "PlayerBleachShinigamiCapitaine created" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking1 = true;
    if (_isAttacking1 == true)
    {
        printf("%s is attacking %s\n", getLastname().c_str(), targetPlayer.getLastname().c_str());
    }

  
}

void PlayerBleachShinigamiCapitaine::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking2 = true;
}

void PlayerBleachShinigamiCapitaine::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
}

void PlayerBleachShinigamiCapitaine::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
    _isPicking = true;
}

int PlayerBleachShinigamiCapitaine::getRandomNumberForRandomAttack() const {
        // Obtenir le temps actuel en secondes depuis l'époque
        auto currentTime = std::chrono::system_clock::now();
        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
        auto timeInSeconds = seconds.time_since_epoch().count();

        // Utiliser le temps comme graine pour la génération de nombres aléatoires
        std::srand(static_cast<unsigned int>(timeInSeconds));
         int randomValue = (std::rand() % 2)+1;
        std::cout << "random value for Random Attack: " << randomValue << std::endl;

        // Générer un nombre aléatoire entre 1 et 2
        return randomValue;

 }


void PlayerBleachShinigamiCapitaine::doFix2()
{
    _isAttacking2 = false;
    
}