#include "../header/playeronepiecemugiwara.hpp"

PlayerOnePieceMugiwara::PlayerOnePieceMugiwara(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float vol, std::map<std::string, int> textureAssociations)
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
    std::cout << "PlayerOnepieceMugiwara created" << std::endl;

}

void PlayerOnePieceMugiwara::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+1;
    targetPlayer.reduceHealth(damage, targetPlayer);

}

void PlayerOnePieceMugiwara::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerOnePieceMugiwara::doAttack3(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack3 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+3;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerOnePieceMugiwara::doAttack4(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack4 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+4;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerOnePieceMugiwara::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerOnePieceMugiwara::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}