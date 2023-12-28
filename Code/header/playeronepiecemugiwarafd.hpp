#pragma once

#include "playeronepiecemugiwara.hpp"
#include <SFML/Graphics.hpp>

class PlayerOnePieceMugiwaraFD : public PlayerOnePieceMugiwara
{
    
protected:
    float _vol;
    std::string _texture;  // Ajout de l'attribut texture

public:
    PlayerOnePieceMugiwaraFD(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float vol, std::map<std::string, int> textureAssociations);
    ~PlayerOnePieceMugiwaraFD() {};
    std::string getTexture(){return _texture;}
    void setTexture(std::string texturepath){_texture = texturepath;}
    void doAttack1(); //
    void doAttack2();
    void doAttack3(); //
    void doAttack4();
    void doJump();
    void doPick();


};