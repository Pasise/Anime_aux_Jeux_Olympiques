#pragma once 

#include "playerbleachshinigami.hpp"
#include <SFML/Graphics.hpp>

class PlayerBleachShinigamiCapitaine : public PlayerBleachShinigami
{
protected:
    float _soin;
    bool _isAttacking2;

public:
    PlayerBleachShinigamiCapitaine(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float soin, std::map<std::string, int> textureAssociations);
    ~PlayerBleachShinigamiCapitaine() {};
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