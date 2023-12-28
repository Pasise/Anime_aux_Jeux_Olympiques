#include "../header/playeronepiecemugiwara.hpp"

PlayerOnePieceMugiwara::PlayerOnePieceMugiwara(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float vol, std::string texturepath)
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _speed = speed;
    _x = x;
    _y = y;
    _vol = vol;
    setTexture(texturepath);
    _direction = 1;
    std::cout << "PlayerOnepieceMugiwara created" << std::endl;

}

void PlayerOnePieceMugiwara::doAttack1()
{
    std::cout << "Attack1 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwara::doAttack2()
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwara::doAttack3()
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwara::doAttack4()
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
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