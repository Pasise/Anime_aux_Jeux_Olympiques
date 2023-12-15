#pragma once 
#include <iostream>

class Joueur{
    protected :
    std::string _Nom;
    std::string _Prenom;
    float _Xp;
    float _vitesse;

    public : 
    void virtual courir() = 0; 
    void virtual attaquer() = 0;
    void virtual recevoir_une_attaque() = 0; 



}; 