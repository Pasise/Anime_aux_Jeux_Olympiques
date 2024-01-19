#pragma once 
#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "userinput.hpp"
class Player{
    protected :
    std::string _lastname;
    std::string _firstname;
    float _Xp;
    float _speed;
    float _x;
    float _y;
    int _direction;
    bool _isAttacking1;
    bool _isAttacking2;
    bool _isAttacking3;
    bool _isAttacking4;
    bool _isJumping;
    bool _isPicking;
    
    std::map<std::string, int> _textureAssociations;
    bool _canAttack; // Variable de classe pour stocker l'état d'attaque
    public : 
    void moveLeft();
    void moveRight();
    float getX()const {return _x;}
    float getY()const {return _y;}
    float getSpeed(){return _speed;}
    float getXp(){return _Xp;}
    int getDirection(){return _direction;}
    std::string getLastname(){return _lastname;}
    std::string getFirstname(){return _firstname;}
    void setX(float x){_x = x;}
    void setY(float y){_y = y;}
    void setSpeed(float speed){_speed = speed;}
    void setXp(float Xp){_Xp = Xp;}
    void setDirection(int direction){_direction = direction;}
    void reduceHealth(float damage,Player& targetPlayer);
        // Ajout de la méthode pour associer un texturePath à un nombre de frames
    void addTexture(const std::string& texturePath, int numberOfFrames) {
        _textureAssociations[texturePath] = numberOfFrames;
    }
    void addAssociations(const std::map<std::string, int>& textureAssociationsToAdd) {
        for (const auto& entry : textureAssociationsToAdd) {
            _textureAssociations[entry.first] = entry.second;
        }
    }

    // Méthode pour récupérer le nombre de frames associé à un texturePath
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
        std::advance(it, i);  // Avance jusqu'à l'élément à la position i

        if (it != _textureAssociations.end()) {
            // Renvoie le chemin de texture de l'élément à la position i
            return it->first;
        } else {
            // Renvoie une chaîne vide si la position i est hors limites
            return "";
        }
    }
    void randomAttack(Player& targetPlayer);
    bool isCloseTo(const Player &otherPlayer, float distanceThreshold) const;
    bool canAttack() const;
    Player() : _canAttack(true) {
        std::srand(std::time(0)); // Initialisation de la graine une seule fois
    }
    bool canAttackNow() const;
    void setCanAttack(bool value) {
        _canAttack = value;
    }
    bool isAttacking1() const {
        return _isAttacking1;
    }
    bool isAttacking2() const {
        return _isAttacking2;
    }
    bool isAttacking3() const {
        return _isAttacking3;
    }
    bool isAttacking4() const {
        return _isAttacking4;
    }
    void setIsAttacking1(bool value) {
        _isAttacking1 = value;
    }
    void setIsAttacking2(bool value) {
        _isAttacking2 = value;
    }
    void setIsAttacking3(bool value) {
        _isAttacking3 = value;
    }
    void setIsAttacking4(bool value) {
        _isAttacking4 = value;
    }
    
    bool isJumping() const {
        return _isJumping;
    }
    void setIsJumping(bool value) {
        _isJumping = value;
    }
    bool isPicking() const {
        return _isPicking;
    }
    void setIsPicking(bool value) {
        _isPicking = value;
    }
    
    void doFix();

    void virtual doAttack1(Player& targetPlayer)=0;
    void virtual doAttack2(Player& targetPlayer)=0;
    void virtual doAttack3(Player& targetPlayer)=0;
    void virtual doAttack4(Player& targetPlayer)=0;
    void virtual doJump()=0;
    void virtual doPick()=0;




}; 