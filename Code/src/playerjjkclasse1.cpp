#include "../header/playerjjkclasse1.hpp"

PlayerJJKClasse1::PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color, std::string texturepath) 
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _occultenergy = occultenergy;
    _color = color;
    setTexture(texturepath);
    _direction = 1;
    std::cout << "PlayerJJKClasse1 created" << std::endl;

}

void PlayerJJKClasse1::doAttack1()
{
    std::cout << "Attack1 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasse1::doAttack2()
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasse1::doAttack3()
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerJJKClasse1::doAttack4()
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
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