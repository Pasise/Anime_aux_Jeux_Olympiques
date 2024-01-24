#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


//======Constantes OnePiece=======

//======Constantes Zoro RORONOA =======
const std::string LASTNAME_ZORO = "Roronoa";
const  std::string FIRSTNAME_ZORO = "Zoro";
const float XP_ZORO =  100;
const float XP_MAX_ZORO =  100;
const float SPEED_ZORO = 3;
const float X_ZORO = 0;
const float Y_ZORO = 740;
const float DAMAGE_ZORO = 1;
const float VOL_ZORO = 1;
const std::string TEXTUREPATH_ZORO =  "../Sprite/zoro_run.png";
const std::string TEXTUREPATH_ZORO_ATTACK1 = "../Sprite/zoro_attack1.png";
const std::string TEXTUREPATH_ZORO_ATTACK2 = "../Sprite/zoro_attack2.png";
std::map<std::string, int> ZOROASSOCIATION = {{TEXTUREPATH_ZORO, 6}, {TEXTUREPATH_ZORO_ATTACK1, 5}, {TEXTUREPATH_ZORO_ATTACK2, 6}};
const std::string DEATH_TEXTURE_PATH_ZORO = "../Sprite/zoro_dead.PNG";

//======Constantes OnePiece MugiwaraFD=======
 // ===================Constantes OnePiece MugiwaraFD Joueur1=======

const std::string LASTNAME_LUFFY = "Monkey D.";
const  std::string FIRSTNAME_LUFFY = "Luffy";
const float XP_LUFFY =  100;
const float XP_MAX_LUFFY =  100;
const float SPEED_LUFFY = 0.7;
const float X_LUFFY = 0;
const float Y_LUFFY = 580;
const float DAMAGE_LUFFY = 1;
const float VOL_LUFFY = 1;
const std::string TEXTUREPATH_LUFFY = "../Sprite/luffy_run.png";
const std::string TEXTUREPATH_LUFFY_ATTACK1 = "../Sprite/luffy_attack1.png";
std::map<std::string, int> LUFFYASSOCIATION = {{TEXTUREPATH_LUFFY, 6}, {TEXTUREPATH_LUFFY_ATTACK1, 5}};
const std::string DEATH_TEXTURE_PATH_LUFFY = "../Sprite/luffy_dead.PNG";

//======Constantes Bleach=======

//======Constantes Byakuya KUCHIKI =======
const std::string LASTNAME_BYAKUYA = "Kuchiki";
const  std::string FIRSTNAME_BYAKUYA = "Byakuya";
const float XP_BYAKUYA =  100;
const float XP_MAX_BYAKUYA =  100;
const float SPEED_BYAKUYA = 1.6;
const float X_BYAKUYA = 0;
const float Y_BYAKUYA = 740;
const float DAMAGE_BYAKUYA = 1;
const float SOIN_BYAKUYA = 2;
const std::string TEXTUREPATH_BYAKUYA =  "../Sprite/byakuya_run.png";
const std::string TEXTUREPATH_BYAKUYA_ATTACK1 = "../Sprite/byakuya_attack1.png";
std::map<std::string, int> BYAKUYAASSOCIATION = {{TEXTUREPATH_BYAKUYA, 4}, {TEXTUREPATH_BYAKUYA_ATTACK1, 7}};
const std::string DEATH_TEXTURE_PATH_BYAKUYA = "../Sprite/byakuya_dead.PNG";


//======Constantes Ichigo KUROSAKI=======
const std::string LASTNAME_ICHIGO = "Kurosaki";
const  std::string FIRSTNAME_ICHIGO = "Ichigo";
const float XP_ICHIGO =  300;
const float XP_MAX_ICHIGO =  300;
const float SPEED_ICHIGO = 5;
const float X_ICHIGO = 0;
const float Y_ICHIGO = 580;
const float DAMAGE_ICHIGO = 10;
const float SOIN_ICHIGO = 2;
const std::string TEXTUREPATH_ICHIGO =    "../Sprite/ichigo_run.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK1 =  "../Sprite/ichigo_attack1.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK2 = "../Sprite/ichigo_attack2.png";
std::map<std::string, int> ICHIGOASSOCIATION = {{TEXTUREPATH_ICHIGO , 6},{TEXTUREPATH_ICHIGO_ATTACK1, 3}, {TEXTUREPATH_ICHIGO_ATTACK2, 6}};
const std::string DEATH_TEXTURE_PATH_ICHIGO = "../Sprite/ichigo_dead.PNG";

//======Constantes Shinsui KYORAKU=======
const std::string LASTNAME_SHINSUI = "Kyoraku";
const  std::string FIRSTNAME_SHINSUI = "Shinsui";
const float XP_SHINSUI =  100;
const float XP_MAX_SHINSUI =  100;
const float SPEED_SHINSUI = 5;
const float X_SHINSUI = 0;
const float Y_SHINSUI = 580;
const float DAMAGE_SHINSUI = 1;
const float SOIN_SHINSUI = 200;
const std::string TEXTUREPATH_SHINSUI =    "../Sprite/kyoraku_run.png"; 
const std::string TEXTUREPATH_SHINSUI_ATTACK1 =  "../Sprite/kyoraku_attack1.png";
const std::string TEXTUREPATH_SHINSUI_HEAL = "../Sprite/kyoraku_heal.png";
std::map<std::string, int> SHINSUIASSOCIATION = {{TEXTUREPATH_SHINSUI , 4},{TEXTUREPATH_SHINSUI_ATTACK1, 6}, {TEXTUREPATH_SHINSUI_HEAL, 4}};
const std::string DEATH_TEXTURE_PATH_SHINSUI = "../Sprite/kyoraku_dead.PNG";

// ========== Constantes Background ==========

const std::string BACKGROUND = "../Sprite/Background1.23.png";

// ========== Constantes Fruit  ==========

// ========== Constantes Fruit du démon ==========
const std::string TEXTUREPATH_FRUIT = "../Sprite/Fruit_du_demon2.png";
const float ENERGY_FRUIT = 100;
const std::string NAME_FRUIT = "Gomu Gomu fruit";

// ========== Constantes Fruit normal ==========
const std::string TEXTUREPATH_FRUITNORMAL = "../Sprite/pasteque.png";
const float ENERGY_FRUITNORMAL = 100;
const std::string NAME_FRUITNORMAL = "Fruit Normal";

// ========== Constantes Masque du Hollow ==========
const std::string TEXTUREPATH_HOLLOW = "../Sprite/Hollow_mask5.png";
const float ENERGY_HOLLOW = 100;
const std::string NAME_HOLLOW = "Masque du Hollow";


// ========== Constantes génerales ==========
//======= Constantes distances d'attaque =========
const float DISTANCETREEHOLD = 100.f; 

//======= Constantes vitesse=========
const float XPMULTIPLIER = 0.015f;

//======= Constantes musique=========
const std::string MUSIC = "../Music/julia-133094.wav";



