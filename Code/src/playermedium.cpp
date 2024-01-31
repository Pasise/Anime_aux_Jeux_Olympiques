#include "../header/playermedium.hpp"

PlayerMedium::PlayerMedium(std::string lastname, std::string firstname, float Hp,float Hp_max,float Hp_multiplier, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath) 
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
    addAssociations(textureAssociations);
    _deathTexturePath = deathTexturePath;
    _direction = 1;
    _isAttacking1 = false;
    _isPicking = false;
    _isAlive = true;
    std::cout << "PlayerMedium created" << std::endl;

}

void PlayerMedium::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    reduceHealth(targetPlayer, _damage);
    _isAttacking1 = true;
}


void PlayerMedium::randomAttack(Player& targetPlayer)
{
 doAttack1(targetPlayer);
}


bool PlayerMedium::canAttack() const {

    // Générez une valeur aléatoire pour déterminer si le joueur peut attaquer
    int randomValue = getRandomNumberForCanAttack();

    // Le joueur peut attaquer si la valeur aléatoire est 1 donc 50% de chance
    return randomValue == 1;
}




PlayerMedium& PlayerMedium::operator=(const PlayerMedium& other)
{
    if (this != &other)
    {
        // Copier les membres de other vers this
        _lastname = other._lastname;
        _firstname = other._firstname;
        _Hp = other._Hp;
        _HpMax = other._HpMax;
        _HpMultiplier = other._HpMultiplier;
        _speed = other._speed;
        _x = other._x;
        _y = other._y;
        _damage = other._damage;
        _direction = other._direction;
        _isAttacking1 = other._isAttacking1;
        _lastAttackTime = other._lastAttackTime;
        _lastPickTime = other._lastPickTime;
        _isPicking = other._isPicking;
        _textureAssociations = other._textureAssociations;
        _deathTexturePath = other._deathTexturePath;
    }

    return *this;
}

// Surcharge supplémentaire pour changer l'état de isAlive
PlayerMedium& PlayerMedium::operator=(bool isAlive)
{
    _isAlive = isAlive;
    return *this;
}