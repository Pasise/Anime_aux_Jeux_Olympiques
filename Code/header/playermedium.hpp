#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerMedium : public Player
{
    public: 
        PlayerMedium(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, std::map<std::string, int> textureAssociations);
        ~PlayerMedium() {};
        void doAttack1(Player& targetPlayer); //
        void doJump();
        void doPick(Fruit& targetFruit);
        void randomAttack(Player& targetPlayer);

};