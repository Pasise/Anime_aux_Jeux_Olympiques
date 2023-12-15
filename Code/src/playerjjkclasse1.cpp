#include "../header/playerjjkclasse1.hpp"

PlayerJJKClasse1::PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color) : PlayerJJK(lastname, firstname, Xp, speed, x, y, occultenergy, color)
{
    std::cout << "PlayerJJKClasse1 created" << std::endl;
}