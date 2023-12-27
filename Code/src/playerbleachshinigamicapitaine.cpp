#include "../header/playerbleachshinigamicapitaine.hpp"

PlayerBleachShinigamiCapitaine::PlayerBleachShinigamiCapitaine(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::string texturepath)
: PlayerBleachShinigami(lastname, firstname, Xp, speed, x, y, soin, texturepath)
{

    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _soin = soin;
    setTexture(texturepath);
    _direction = 1;
    std::cout << "PlayerBleachShinigamiCapitaine created" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack1()
{
    std::cout << "Attack1 Not Implemented Yet" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack2()
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack3()
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerBleachShinigamiCapitaine::doAttack4()
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
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

