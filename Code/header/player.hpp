#pragma once 
#include <iostream>
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
    std::map<std::string, int> _textureAssociations;
    public : 
    void moveLeft();
    void moveRight();
    float getX(){return _x;}
    float getY(){return _y;}
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
    void reduceHealth(float damage){_Xp = _Xp - damage;}
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
    void randomAttack();
    void virtual doAttack1()=0;
    void virtual doAttack2()=0;
    void virtual doAttack3()=0;
    void virtual doAttack4()=0;
    void virtual doJump()=0;
    void virtual doPick()=0;




}; 