#pragma once

#include "player.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerMedium : public Player
{
    public: 
        PlayerMedium(std::string lastname, std::string firstname, float Hp,float Hp_max,float Hp_multiplier, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath);
        ~PlayerMedium() {};
        void doAttack1(Player& targetPlayer); 
        void randomAttack(Player& targetPlayer);
        bool canAttack() const;
        PlayerMedium& operator=(const PlayerMedium& other);
        PlayerMedium& operator=(bool isAlive);

};