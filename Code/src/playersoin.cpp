#include "../header/playersoin.hpp"

PlayerSoin::PlayerSoin(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations)
{

    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _XpMax = Xp_max;
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
    float distanceThreshold = 1000.0f;  // Adjust the distance threshold as needed
    if (isCloseToFruit(targetFruit, distanceThreshold) && (targetFruit.getName() == "Masque du Hollow" || targetFruit.getName() == "Fruit normal"))
    {
        // Check if the fruit is alive before picking
        if (targetFruit.isAlive())
        {
            std::cout << getLastname() << " is picking up " << targetFruit.getName() << std::endl;
            std::cout << "Xp avant : " << _Xp << std::endl;
            
            // Augmenter les xp du joueur de l'énergie du fruit 
            _Xp += targetFruit.getEnergy();
            
            std::cout << "Xp apres : " << _Xp << std::endl;

            // Set isAlive to false to mark the fruit as picked
            targetFruit.setIsAlive(false);
        }
        else
        {
            std::cout << getLastname() << " cannot pick up " << targetFruit.getName() << " - Already picked" << std::endl;
        }
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