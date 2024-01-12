#include "../header/playerbleachshinigami.hpp"

PlayerBleachShinigami::PlayerBleachShinigami(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations)
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
    std::cout << "PlayerBleachShinigami created" << std::endl;
}


void PlayerBleachShinigami::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
}
    

void PlayerBleachShinigami::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigami::doAttack3(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack3 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+3;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigami::doAttack4(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack4 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+4;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigami::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerBleachShinigami::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}

