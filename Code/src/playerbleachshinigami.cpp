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

    // Calculez les dégâts spécifiques à Attack1 (à ajuster selon vos règles du jeu)
    float damage = 30.0f;

    // Infligez les dégâts au joueur ciblé
    targetPlayer.reduceHealth(damage);
}
    

void PlayerBleachShinigami::doAttack2(Player& targetPlayer)
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerBleachShinigami::doAttack3(Player& targetPlayer)
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerBleachShinigami::doAttack4(Player& targetPlayer)
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
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

