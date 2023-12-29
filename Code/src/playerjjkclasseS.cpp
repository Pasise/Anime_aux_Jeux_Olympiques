#include "../header/playerjjkclasseS.hpp"


PlayerJJKClasseS::PlayerJJKClasseS(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::map<std::string, int> textureAssociations)
    : PlayerJJKClasse1(lastname, firstname, Xp, speed, x, y, occultenergy, color, textureAssociations)
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
    _direction = -1;
    std::cout << "PlayerJJKClasseS created" << std::endl;

}

void PlayerJJKClasseS::doAttack1(Player& targetPlayer)
{
    std::cout << "Attack1 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasseS::doAttack2(Player& targetPlayer)
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasseS::doAttack3(Player& targetPlayer)
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasseS::doAttack4(Player& targetPlayer)
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasseS::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerJJKClasseS::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}

bool PlayerJJKClasseS::checkCollision(PlayerJJK* otherPlayer)
{
    if (otherPlayer->getX() < _x + 50 && otherPlayer->getX() > _x - 50 && otherPlayer->getY() < _y + 50 && otherPlayer->getY() > _y - 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}