#include "../header/player.hpp"

//implémente la méthode moveleft si on appuie sur left et décrémente la position de x en utilisant la vitesse

void Player::moveLeft()
{
        _x -= _speed;
}

//implémente la méthode moveRight si on appuie sur right et incrémente la position de x en utilisant la vitesse

void Player::moveRight()
{
        _x += _speed;
}
