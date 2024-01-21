#pragma once

#include "player.hpp"
#include <SFML/Graphics.hpp>

class PlayerPlus : public Player
{
    
protected:
    std::string _texture;  // Ajout de l'attribut texture
    bool _isAttacking2; // Ajout de l'attribut _isAttacking1

public:
    PlayerPlus(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, std::map<std::string, int> textureAssociations);
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
    void doPick();


};