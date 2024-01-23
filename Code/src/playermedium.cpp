#include "../header/playermedium.hpp"

PlayerMedium::PlayerMedium(std::string lastname, std::string firstname, float Xp,float Xp_max,float speed, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath) 
{
    _lastname = lastname;
    _firstname = firstname;
    _Xp = Xp;
    _XpMax = Xp_max;
    _speed = speed;
    _x = x;
    _y = y;
    _damage = damage;
    addAssociations(textureAssociations);
    _deathTexturePath = deathTexturePath;
    _direction = 1;
    _isAttacking1 = false;
    _isJumping = false;
    _isPicking = false;
    std::cout << "PlayerMedium created" << std::endl;

}

void PlayerMedium::doAttack1(Player& targetPlayer)
{
    std::cout << getLastname() << " is performing Attack1 on " << targetPlayer.getLastname() << std::endl;
    targetPlayer.reduceHealth(targetPlayer);
    _isAttacking1 = true;
}

void PlayerMedium::doJump()
{
    _y += 2;
    _y -= 2;
    _isJumping = true;
}

void PlayerMedium::doPick(Fruit& targetFruit)
{ // Check if the target fruit is close enough and has the desired name
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

void PlayerMedium::randomAttack(Player& targetPlayer)
{
 doAttack1(targetPlayer);
}

