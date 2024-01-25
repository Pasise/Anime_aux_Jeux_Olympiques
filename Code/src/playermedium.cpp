#include "../header/playermedium.hpp"

PlayerMedium::PlayerMedium(std::string lastname, std::string firstname, float Xp,float Xp_max,float speed, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath) 
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _XpMax = Xp_max;
    _speed = speed;
    _x = x;
    _y = y;
    _damage = damage;
    addAssociations(textureAssociations);
    _deathTexturePath = deathTexturePath;
    _direction = 1;
    _isAttacking1 = false;
    _isJumping = false;
    _isPicking = false;
    _isAlive = true;
    std::cout << "PlayerMedium created" << std::endl;

}

void PlayerMedium::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    reduceHealth(targetPlayer);
    _isAttacking1 = true;
}

void PlayerMedium::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
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