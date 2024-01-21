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
    _isAttacking1 = false;
    _isAttacking2 = false;
    _isJumping = false;
    _isPicking = false;
    std::cout << "PlayerOnepieceMugiwara created" << std::endl;

}

void PlayerOnePieceMugiwaraFD::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking1 = true;
}

void PlayerOnePieceMugiwaraFD::doAttack2(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack2 on " << targetPlayer.getLastname() << std::endl;
    float damage = _vol+2;
    targetPlayer.reduceHealth(damage, targetPlayer);
    _isAttacking2 = true;
}

void PlayerOnePieceMugiwaraFD::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
}

void PlayerOnePieceMugiwaraFD::doPick()
{
    //std::cout << "Pick Not Implemented Yet" << std::endl;
    _isPicking = true;
}

int PlayerOnePieceMugiwaraFD::getRandomNumberForRandomAttack() const {
        // Obtenir le temps actuel en secondes depuis l'époque
        auto currentTime = std::chrono::system_clock::now();
        // Convertir le temps en nombre entier représentant le nombre de secondes
        auto currentTimeInSeconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
        // Obtenir la durée écoulée depuis l'époque
        auto epoch = currentTimeInSeconds.time_since_epoch();
        // Convertir la durée en secondes
        auto value = std::chrono::duration_cast<std::chrono::seconds>(epoch);
        // Obtenir le nombre de secondes écoulées depuis l'époque
        auto duration = value.count();
        // Utiliser le nombre de secondes comme graine pour le générateur de nombres aléatoires
        std::srand(duration);
        // Générer un nombre aléatoire entre 1 et 3
        int randomNumber = std::rand() % 3 + 1;
        return randomNumber;
    }