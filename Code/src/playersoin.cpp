#include "../header/playersoin.hpp"

PlayerSoin::PlayerSoin(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations)
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
    _isAttacking1 = false;
    _isJumping = false;
    _isPicking = false;
    
    std::cout << "PlayerBleachShinigami created" << std::endl;
}


void PlayerSoin::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    float damage = _soin+1;
    targetPlayer.reduceHealth(damage, targetPlayer);
}
    


void PlayerSoin::doJump()
{
    _y += 2;
    _y -= 2;
}

void PlayerSoin::doPick(Fruit& targetFruit)
{
    // Check if the target fruit is close enough and has the desired name
    float distanceThreshold = 50.0f;  // Adjust the distance threshold as needed
    if (isCloseToFruit(targetFruit, distanceThreshold) && targetFruit.getName() == "Masque du Hollow")
    {
        std::cout << getLastname() << " is picking up " << targetFruit.getName() << std::endl;

        //Augmenter les xp du joueur de l'néergie du fruit 
        _Xp += targetFruit.getEnergy();

        
    }
    else
    {
        std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << std::endl;
    }

    _isPicking = true;  // You may want to reconsider setting _isPicking to true here
}

void PlayerSoin::randomAttack(Player& targetPlayer)
{
   doAttack1(targetPlayer);
}