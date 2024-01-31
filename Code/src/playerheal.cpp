#include "../header/playerheal.hpp"
#include "../header/game.hpp"

PlayerHeal::PlayerHeal(std::string lastname, std::string firstname, float Hp,float Hp_max,float Hp_multiplier,float x, float y, float damage, float heal, std::map<std::string, int> textureAssociations, std::string deathTexturePath)
{

    _lastname = lastname;
    _firstname = firstname;
    _Hp = Hp;
    _HpMax = Hp_max;
    _HpMultiplier = Hp_multiplier;
    _speed = Hp_max*Hp_multiplier;
    _x = x;
    _y = y;
    _damage = damage;
    _heal = heal;
    addAssociations(textureAssociations);
    _deathTexturePath = deathTexturePath;
    _direction = 1;
    _isAttacking1 = false;
    _isPicking = false;
    _isHealing = false;
    _isAlive = true;
    
    // view


    std::cout << "PlayerBleachShinigami created" << std::endl;
}


void PlayerHeal::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    reduceHealth(targetPlayer, _damage);
    _isAttacking1 = true;
}
    



void PlayerHeal::randomAttack(Player& targetPlayer)
{
   doAttack1(targetPlayer);
}

void PlayerHeal::doHeal()
{
    std::cout << getLastname() << " is healing himself" << std::endl;
    _Hp += _heal;
    if (_Hp > _HpMax)
    {
        _Hp = _HpMax;
    }
    _isHealing = true;
}

void PlayerHeal::doFix(){
    _isAttacking1 = false;
    _isPicking = false;
    _isHealing = false;

}


bool PlayerHeal::canAttack() const {

    // Générez une valeur aléatoire pour déterminer si le joueur peut attaquer
    int randomValue = getRandomNumberForCanAttack();

    // Le joueur peut attaquer si la valeur aléatoire est 1 donc 50% de chance
    return randomValue == 3;
}

bool PlayerHeal::isTimetoHeal() const {
    auto currentTime = Clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - _lastHealTime);

        // Check if enough time has passed since the last attack
    return elapsedTime.count() >= 17; // Adjust the cooldown period (5 seconds in this case)
}