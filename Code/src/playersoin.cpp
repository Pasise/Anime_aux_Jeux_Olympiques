#include "../header/playersoin.hpp"
#include "../header/game.hpp"

PlayerSoin::PlayerSoin(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float damage, float heal, std::map<std::string, int> textureAssociations, std::string deathTexturePath)
{

    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _XpMax = Xp_max;
    _speed = speed;
    _x = x;
    _y = y;
    _damage = damage;
    _heal = heal;
    addAssociations(textureAssociations);
    _deathTexturePath = deathTexturePath;
    _direction = 1;
    _isAttacking1 = false;
    _isJumping = false;
    _isPicking = false;
    _isHealing = false;
    _isAlive = true;
    
    std::cout << "PlayerBleachShinigami created" << std::endl;
}


void PlayerSoin::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    reduceHealth(targetPlayer);
    _isAttacking1 = true;
}
    


void PlayerSoin::doJump()
{
    _y += 2;
    _y -= 2;
}



void PlayerSoin::randomAttack(Player& targetPlayer)
{
   doAttack1(targetPlayer);
}

void PlayerSoin::doHeal()
{
    std::cout << getLastname() << " is healing himself" << std::endl;
    _Xp += heal;
    if (_Xp > _XpMax)
    {
        _Xp = _XpMax;
    }
    _isHealing = true;
}

void PlayerSoin::doFix3(){
    _isHealing = false;
}


bool PlayerSoin::canAttack() const {

    // Générez une valeur aléatoire pour déterminer si le joueur peut attaquer
    int randomValue = getRandomNumberForCanAttack();

    // Le joueur peut attaquer si la valeur aléatoire est 1 donc 50% de chance
    return randomValue == 3;
}

bool PlayerSoin::isTimetoHeal() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastHealTime);

        // Check if enough time has passed since the last attack
    return elapsedTime.count() >= 15; // Adjust the cooldown period (5 seconds in this case)
}