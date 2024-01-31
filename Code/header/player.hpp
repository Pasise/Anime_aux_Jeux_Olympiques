#pragma once 
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "userinput.hpp"
#include "object.hpp"
#include "fruit.hpp"
class Player: public Object{
    protected :
    std::string _lastname;
    std::string _firstname;
    float _Hp;
    float _HpMax;
    float _HpMultiplier;
    float _speed;
    float _x;
    float _y;
    float _damage;
    int _direction;
    bool _isAttacking1;

    using Clock = std::chrono::steady_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint _lastAttackTime; // Record the time of the last attack
    TimePoint _lastPickTime;

    bool _isPicking;
    
    std::map<std::string, int> _textureAssociations;
    std::string _deathTexturePath;

    //view
    sf::View _view;

    public : 
    sf::View &getView() 
    {
        return _view;
    }
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    float getX()const {return _x;}
    float getY()const {return _y;}
    float getSpeed(){return _speed;}
    float getHp(){return _Hp;}
    float getHpMax(){return _HpMax;}
    int getDirection(){return _direction;}
    float getDamage(){return _damage;}
    std::string getLastname(){return _lastname;}
    std::string getFirstname(){return _firstname;}
    std::string getDeathTexturePath() const {
        return _deathTexturePath;
    }
    TimePoint getLastAttackTime() const {
        return _lastAttackTime;
    }

    int getNumberOfFrames(const std::string& texturePath) const {
        auto it = _textureAssociations.find(texturePath);
        if (it != _textureAssociations.end()) {
            return it->second;
        } else {
            // Retourne 0 si le texturePath n'est pas trouvé (ou une valeur par défaut appropriée)
            return 0;
        }
    }
        
    const std::map<std::string, int>& getTextureAssociations() const {
        return _textureAssociations;
    }

    std::string getTexturePath(int i) const {
        auto it = _textureAssociations.begin();
        std::advance(it, i);  

        if (it != _textureAssociations.end()) {
            
            return it->first;
        } else {
            
            return "";
        }
    }

    void setX(float x){_x = x;}
    void setY(float y){_y = y;}
    void setHp(float Hp){_Hp = Hp;}
    void setDirection(int direction){_direction = direction;}

    void reduceHealth(Player& targetPlayer, float damage);
    
    void addTexture(const std::string& texturePath, int numberOfFrames) {
        _textureAssociations[texturePath] = numberOfFrames;
    }
    void addAssociations(const std::map<std::string, int>& textureAssociationsToAdd) {
        for (const auto& entry : textureAssociationsToAdd) {
            _textureAssociations[entry.first] = entry.second;
        }
    }

    bool isCloseTo(const Player &otherPlayer, float distanceThreshold) const;
    bool isCloseToFruit(const Fruit &targetFruit, float distanceThreshold) const;
    bool isTimetoAttack() const;
    int getRandomNumberForCanAttack() const;
    
    bool isBehind(const Player &otherPlayer) const;
    bool isAttacking1() const {
        return _isAttacking1;
   
    }

    void setIsAttacking1(bool value) {_isAttacking1 = value;}

    bool isPicking() const {return _isPicking;}
    void setIsPicking(bool value) {_isPicking = value;}

    void setSpeed()
    {
        _speed = (_Hp * _HpMultiplier);

        // On s'assure que le joeur ne fasse pas du surplace
        if (_speed < 0.2f) {
            _speed = 0.2f;
        }
    }

    void setSpeed( float HpMultiplier)
    {
        _speed = (_Hp * HpMultiplier);

        // On s'assure que le joeur ne fasse pas du surplace
        if (_speed < 0.2f) {
            _speed = 0.2f;
        }
    }

    void setLastAttackTime() {
        _lastAttackTime = Clock::now();
    }

    void setLastPickTime() {
        _lastPickTime = Clock::now();
    }

    bool isTimeToFix() const;
    
    void virtual doFix();

    void doPick(Fruit& targetFruit, float distanceThreshold);

    void virtual doAttack1(Player& targetPlayer)=0;
    
    void virtual randomAttack(Player& targetPlayer)=0;
    bool virtual canAttack() const = 0;
    bool isTimetoPick() const;


}; 