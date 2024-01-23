#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


//======Constantes JJK=======


//======Constantes JJK classe1=======
/*const std::string LASTNAME_JJKCLASSE1 = "Fushiguro";
const  std::string FIRSTNAME_JJKCLASSE1 = "Megumi";
const float XP_JJKCLASSE1 =  0;
const float SPEED_JJKCLASSE1 = 2.5;
const float X_JJKCLASSE1 = -1; 
const float Y_JJKCLASSE1 = 730;
const float OCULTENERGY_JJKCLASSE1 =  1;
const float COLOR_JJKCLASSE1 = 0;
const std::string TEXTUREPATH_JJKCLASSE1 =    "../Sprite/ichigo_run.png";
const std::string TEXTUREPATH_JJKCLASSE1_ATTACK1 =  "../Sprite/ichigo_attack1.png";
std::map<std::string, int> MEGUMIASSOCIATION = {{TEXTUREPATH_JJKCLASSE1, 6},{TEXTUREPATH_JJKCLASSE1_ATTACK1, 5}};*/

//======Constantes JJK classeS=======

/*const std::string LASTNAME_JJKCLASSES = "Satoru";
const  std::string FIRSTNAME_JJKCLASSES = "Gojo";
const float XP_JJKCLASSES =  0;
const float SPEED_JJKCLASSES = 1.3;
const float X_JJKCLASSES = 0;
const float Y_JJKCLASSES = 590;
const float OCULTENERGY_JJKCLASSES = 2;
const float COLOR_JJKCLASSES = 0;
const std::string TEXTUREPATH_JJKCLASSES =  "../Sprite/luffy_walkreverse4.png";
std::map<std::string, int> GOJOASSOCIATION = {{TEXTUREPATH_JJKCLASSES, 8}};*/



//======Constantes OnePiece=======

//======Constantes Zoro RORONOA =======
const std::string LASTNAME_ZORO = "Roronoa";
const  std::string FIRSTNAME_ZORO = "Zoro";
const float XP_ZORO =  700;
const float SPEED_ZORO = 3;
const float X_ZORO = 0;
const float Y_ZORO = 740;
const float VOL_ZORO = 1;
const std::string TEXTUREPATH_ZORO =  "../Sprite/zoro_run.png";
const std::string TEXTUREPATH_ZORO_ATTACK1 = "../Sprite/zoro_attack1.png";
const std::string TEXTUREPATH_ZORO_ATTACK2 = "../Sprite/zoro_attack2.png";
std::map<std::string, int> ZOROASSOCIATION = {{TEXTUREPATH_ZORO, 6}, {TEXTUREPATH_ZORO_ATTACK1, 5}, {TEXTUREPATH_ZORO_ATTACK2, 6}};

//======Constantes OnePiece MugiwaraFD=======
 // ===================Constantes OnePiece MugiwaraFD Joueur1=======

const std::string LASTNAME_ZOROFDJ1 = "Monkey D.";
const  std::string FIRSTNAME_ZOROFDJ1 = "Luffy";
const float XP_ZOROFDJ1 =  50;
const float SPEED_ZOROFDJ1 = 0.7;
const float X_ZOROFDJ1 = 0;
const float Y_ZOROFDJ1 = 580;
const float VOL_ZOROFDJ1 = 1;
const std::string TEXTUREPATH_ZOROFDJ1 = "../Sprite/luffy_walkreverse4.png";
std::map<std::string, int> LUFFYASSOCIATION = {{TEXTUREPATH_ZOROFDJ1, 8}};

// ===================Constantes OnePiece MugiwaraFD Joueur2=======
const std::string LASTNAME_ZOROFDJ2 = "Trafalgar D.";
const  std::string FIRSTNAME_ZOROFDJ2 = "Water Law";
const float XP_ZOROFDJ2 =  50;
const float SPEED_ZOROFDJ2 = 3.6;
const float X_ZOROFDJ2 = 0;
const float Y_ZOROFDJ2 = 580;
const float VOL_ZOROFDJ2 = 2;
const std::string TEXTUREPATH_ZOROFDJ2 =  "../Sprite/trafalgar_run2.png";
std::map<std::string, int> TRAFALGARASSOCIATION = {{TEXTUREPATH_ZOROFDJ2, 6}};
//======Constantes Bleach=======

//======Constantes Byakuya KUCHIKI =======
const std::string LASTNAME_BYAKUYA = "Kuchiki";
const  std::string FIRSTNAME_BYAKUYA = "Byakuya";
const float XP_BYAKUYA =  600;
const float SPEED_BYAKUYA = 1.6;
const float X_BYAKUYA = 0;
const float Y_BYAKUYA = 580;
const float SOIN_BYAKUYA = 2;
const std::string TEXTUREPATH_BYAKUYA =  "../Sprite/Byakuya_Kuchiki_Run4.png";
const std::string TEXTUREPATH_BYAKUYA_ATTACK1 = "../Sprite/byakuya_attack1.png";
std::map<std::string, int> BYAKUYAASSOCIATION = {{TEXTUREPATH_BYAKUYA, 4}, {TEXTUREPATH_BYAKUYA_ATTACK1, 7}};


//======Constantes Ichigo KUROSAKI=======
const std::string LASTNAME_ICHIGO = "Kurosaki";
const  std::string FIRSTNAME_ICHIGO = "Ichigo";
const float XP_ICHIGO =  1000;
const float SPEED_ICHIGO = 5;
const float X_ICHIGO = 0;
const float Y_ICHIGO = 580;
const float SOIN_ICHIGO = 2;
const std::string TEXTUREPATH_ICHIGO =    "../Sprite/ichigo_run.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK1 =  "../Sprite/ichigo_attack1.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK2 = "../Sprite/ichigo_attack2.png";
std::map<std::string, int> ICHIGOASSOCIATION = {{TEXTUREPATH_ICHIGO , 6},{TEXTUREPATH_ICHIGO_ATTACK1, 3}, {TEXTUREPATH_ICHIGO_ATTACK2, 8}};

// ========== Constantes Background ==========

const std::string BACKGROUND = "../Sprite/Background1.2merged.png";

// ========== Constantes Fruit  ==========

// ========== Constantes Fruit du démon ==========
const std::string TEXTUREPATH_FRUIT = "../Sprite/pasteque.png";
const float Y_FRUIT = 620;
const float ENERGY_FRUIT = 10;
const std::string NAME_FRUIT = "Gomu Gomu fruit";

// ========== Constantes Fruit normal ==========
const std::string TEXTUREPATH_FRUITNORMAL = "../Sprite/pasteque.png";
const float Y_FRUITNORMAL = 620;
const float ENERGY_FRUITNORMAL = 10;
const std::string NAME_FRUITNORMAL = "Fruit Normal";

// ========== Constantes Masque du Hollow ==========
const std::string TEXTUREPATH_HOLLOW = "../Sprite/pasteque.png";
const float Y_HOLLOW = 620;
const float ENERGY_HOLLOW = 10;
const std::string NAME_HOLLOW = "Masque du Hollow";


// ========== Constantes génerales ==========
//======= Constantes distances d'attaque =========
const float DISTANCETREEHOLD = 200.f;

//======= Constantes vitesse=========
const float XPMULTIPLIER = 0.015f;

//======= Constantes musique=========
const std::string MUSIC = "../Music/julia-133094.wav";

//======= Constante barre de vie =========
const std::string TEXTUREPATH_LIFE = "../Sprite/life.png";

