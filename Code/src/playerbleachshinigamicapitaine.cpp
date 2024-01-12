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
    std::cout << "PlayerBleachShinigamiCapitaine created" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+1;
    targetPlayer.reduceHealth(damage, targetPlayer);

  
}

void PlayerBleachShinigamiCapitaine::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigamiCapitaine::doAttack3(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack3 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+3;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigamiCapitaine::doAttack4(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack4 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+4;
    targetPlayer.reduceHealth(damage, targetPlayer);
}

void PlayerBleachShinigamiCapitaine::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerBleachShinigamiCapitaine::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}

