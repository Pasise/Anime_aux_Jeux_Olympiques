#pragma once

#include "playermedium.hpp"
#include "fruit.hpp"
#include <SFML/Graphics.hpp>

class PlayerPlus : public PlayerMedium
{
    
protected:
    std::string _texture;  // Ajout de l'attribut texture
    bool _isAttacking2; // Ajout de l'attribut _isAttacking1

public:
    PlayerPlus(std::string lastname, std::string firstname, float Xp,float Xp_max, float speed, float x, float y, float damage, std::map<std::string, int> textureAssociations, std::string deathTexturePath);
    ~PlayerPlus() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(Player& targetPlayer); //
    void doAttack2(Player& targetPlayer);
      bool isAttacking2() const {
        return _isAttacking2;
   
    }
    void setIsAttacking2(bool value) {
        _isAttacking2 = value;
    }

    int getRandomNumberForRandomAttack() const;
    void doJump();
    void doFix() override;
    void randomAttack(Player& targetPlayer);
    bool canAttack() const;


};