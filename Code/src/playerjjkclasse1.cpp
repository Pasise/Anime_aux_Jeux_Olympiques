#include "../header/playerjjkclasse1.hpp"

PlayerJJKClasse1::PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::map<std::string, int> textureAssociations) 
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _occultenergy = occultenergy;
    _color = color;
    addAssociations(textureAssociations);
    _direction = 1;
    _isAttacking1 = false;
    _isAttacking2 = false;
    _isAttacking3 = false;
    _isAttacking4 = false;
    _isJumping = false;
    _isPicking = false;
    std::cout << "PlayerJJKClasse1 created" << std::endl;

}

void PlayerJJKClasse1::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _occultenergy+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerJJKClasse1::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _occultenergy+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerJJKClasse1::doAttack3(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack3 on " << targetPlayer.getLastname() << std::endl;
    float damage = _occultenergy+3;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerJJKClasse1::doAttack4(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack4 on " << targetPlayer.getLastname() << std::endl;
    float damage = _occultenergy+4;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerJJKClasse1::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerJJKClasse1::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}