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
    std::cout << "PlayerOnepieceMugiwara created" << std::endl;

}

void PlayerOnePieceMugiwaraFD::doAttack1()
{
    std::cout << "Attack1 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwaraFD::doAttack2()
{
    std::cout << "Attack2 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwaraFD::doAttack3()
{
    std::cout << "Attack3 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwaraFD::doAttack4()
{
    std::cout << "Attack4 Not Implemented Yet" << std::endl;
}

void PlayerOnePieceMugiwaraFD::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerOnePieceMugiwaraFD::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
}