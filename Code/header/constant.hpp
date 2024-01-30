#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


//======Constantes OnePiece=======

//======Constantes Zoro RORONOA =======
const std::string LASTNAME_ZORO = "Roronoa";
const  std::string FIRSTNAME_ZORO = "Zoro";
const float XP_ZORO =  200;
const float XP_MAX_ZORO =  200;
const float XP_MULTIPLIER_ZORO = 0.02;
const float X_ZORO = 0;
const float Y_ZORO = 740;
const float DAMAGE_ZORO = 40;
const std::string TEXTUREPATH_ZORO =  "../Sprite/zoro_run.png";
const std::string TEXTUREPATH_ZORO_ATTACK1 = "../Sprite/zoro_attack1.png";
const std::string TEXTUREPATH_ZORO_ATTACK2 = "../Sprite/zoro_attack2.png";
std::map<std::string, int> ZOROASSOCIATION = {{TEXTUREPATH_ZORO, 6}, {TEXTUREPATH_ZORO_ATTACK1, 5}, {TEXTUREPATH_ZORO_ATTACK2, 6}};
const std::string DEATH_TEXTURE_PATH_ZORO = "../Sprite/zoro_dead.PNG";

//======Constantes OnePiece MugiwaraFD=======
 // ===================Constantes OnePiece MugiwaraFD Joueur1=======

const std::string LASTNAME_LUFFY = "Monkey D.";
const  std::string FIRSTNAME_LUFFY = "Luffy";
const float XP_LUFFY =  250;
const float XP_MAX_LUFFY =  250;
const float XP_MULTIPLIER_LUFFY = 0.017;
const float X_LUFFY = 0;
const float Y_LUFFY = 580;
const float DAMAGE_LUFFY = 50;
const std::string TEXTUREPATH_LUFFY = "../Sprite/luffy_run.png";
const std::string TEXTUREPATH_LUFFY_ATTACK1 = "../Sprite/luffy_attack1.png";
std::map<std::string, int> LUFFYASSOCIATION = {{TEXTUREPATH_LUFFY, 6}, {TEXTUREPATH_LUFFY_ATTACK1, 5}};
const std::string DEATH_TEXTURE_PATH_LUFFY = "../Sprite/luffy_dead.PNG";

//======Constantes Bleach=======

//======Constantes Byakuya KUCHIKI =======
const std::string LASTNAME_BYAKUYA = "Kuchiki";
const  std::string FIRSTNAME_BYAKUYA = "Byakuya";
const float XP_BYAKUYA =  300;
const float XP_MAX_BYAKUYA =  300;
const float XP_MULTIPLIER_BYAKUYA = 0.017;
const float X_BYAKUYA = 0;
const float Y_BYAKUYA = 740;
const float DAMAGE_BYAKUYA = 50;
const std::string TEXTUREPATH_BYAKUYA =  "../Sprite/byakuya_run.png";
const std::string TEXTUREPATH_BYAKUYA_ATTACK1 = "../Sprite/byakuya_attack1.png";
std::map<std::string, int> BYAKUYAASSOCIATION = {{TEXTUREPATH_BYAKUYA, 4}, {TEXTUREPATH_BYAKUYA_ATTACK1, 7}};
const std::string DEATH_TEXTURE_PATH_BYAKUYA = "../Sprite/byakuya_dead.PNG";


//======Constantes Ichigo KUROSAKI=======
const std::string LASTNAME_ICHIGO = "Kurosaki";
const  std::string FIRSTNAME_ICHIGO = "Ichigo";
const float XP_ICHIGO =  200;
const float XP_MAX_ICHIGO =  200;
const float XP_MULTIPLIER_ICHIGO = 0.016;
const float X_ICHIGO = 0;
const float Y_ICHIGO = 580;
const float DAMAGE_ICHIGO = 40;
const std::string TEXTUREPATH_ICHIGO =    "../Sprite/ichigo_run.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK1 =  "../Sprite/ichigo_attack1.png";
const std::string TEXTUREPATH_ICHIGO_ATTACK2 = "../Sprite/ichigo_attack2.png";
std::map<std::string, int> ICHIGOASSOCIATION = {{TEXTUREPATH_ICHIGO , 6},{TEXTUREPATH_ICHIGO_ATTACK1, 3}, {TEXTUREPATH_ICHIGO_ATTACK2, 6}};
const std::string DEATH_TEXTURE_PATH_ICHIGO = "../Sprite/ichigo_dead.PNG";

//======Constantes SHUNSUI KYORAKU=======
const std::string LASTNAME_SHUNSUI = "Kyoraku";
const  std::string FIRSTNAME_SHUNSUI = "SHUNSUI";
const float XP_SHUNSUI =  200;
const float XP_MAX_SHUNSUI =  200;
const float XP_MULTIPLIER_SHUNSUI = 0.02;
const float X_SHUNSUI = 0;
const float Y_SHUNSUI = 580;
const float DAMAGE_SHUNSUI = 50;
const float HEAL_SHUNSUI = 40;
const std::string TEXTUREPATH_SHUNSUI =    "../Sprite/kyoraku_run.png"; 
const std::string TEXTUREPATH_SHUNSUI_ATTACK1 =  "../Sprite/kyoraku_attack1.png";
const std::string TEXTUREPATH_SHUNSUI_HEAL = "../Sprite/kyoraku_heal.png";
std::map<std::string, int> SHUNSUIASSOCIATION = {{TEXTUREPATH_SHUNSUI , 4},{TEXTUREPATH_SHUNSUI_ATTACK1, 6}, {TEXTUREPATH_SHUNSUI_HEAL, 4}};
const std::string DEATH_TEXTURE_PATH_SHUNSUI = "../Sprite/kyoraku_dead.PNG";

// ========== Constantes Background ==========

const std::string BACKGROUND = "../Sprite/Background.png";

// ========== Constantes Fruit  ==========

// ========== Constantes Fruit du démon ==========
const std::string TEXTUREPATH_FRUIT = "../Sprite/Fruit_du_demon.png";
const float ENERGY_FRUIT = 100;
const std::string NAME_FRUIT = "Gomu Gomu fruit";

// ========== Constantes Fruit normal ==========
const std::string TEXTUREPATH_FRUITNORMAL = "../Sprite/pasteque.png";
const float ENERGY_FRUITNORMAL = 80;
const std::string NAME_FRUITNORMAL = "Fruit Normal";

// ========== Constantes Masque du Hollow ==========
const std::string TEXTUREPATH_HOLLOW = "../Sprite/Hollow_mask5.png";
const float ENERGY_HOLLOW = 90;
const std::string NAME_HOLLOW = "Masque du Hollow";


// ========== Constantes génerales ==========
//======= Constantes distances d'attaque =========
const float DISTANCETREEHOLD = 250.f; 
const float DISTANCETREEHOLDLUFFY = 450.f; //Luffy peut attaquer de plus loin
const float DISTANCETREEHOLDFRUITS = 180.f;


//======= Constantes musique=========
const std::string MUSIC = "../Music/julia-133094.wav";
const std::string WINMUSIC = "../Music/win.wav";
const std::string LOSEMUSIC = "../Music/lose.wav";
const std::string HEALMUSIC = "../Music/heal.wav";
const std::string ATTACKMUSIC = "../Music/attack.wav";
const std::string PICKMUSIC = "../Music/pick.wav";
const std::string ATTACKEDMUSIC = "../Music/attacked.wav";
