#include "../header/playeronepiecemugiwarafd.hpp"

PlayerOnePieceMugiwaraFD::PlayerOnePieceMugiwaraFD(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float vol, std::map<std::string, int> textureAssociations) 
: PlayerOnePieceMugiwara(lastname, firstname, Xp, speed, x, y, vol, textureAssociations)
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _vol = vol;
    addAssociations(textureAssociations);
    _direction = 1;
    _isAttacking1 = false;
    _isAttacking2 = false;
    _isAttacking3 = false;
    _isAttacking4 = false;
    _isJumping = false;
    _isPicking = false;
    std::cout << "PlayerOnepieceMugiwara created" << std::endl;

}

void PlayerOnePieceMugiwaraFD::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking1 = true;
}

void PlayerOnePieceMugiwaraFD::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking2 = true;
}

void PlayerOnePieceMugiwaraFD::doAttack3(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack3 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+3;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking3 = true;
}

void PlayerOnePieceMugiwaraFD::doAttack4(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack4 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+4;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking4 = true;
}

void PlayerOnePieceMugiwaraFD::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
}

void PlayerOnePieceMugiwaraFD::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
    _isPicking = true;
}