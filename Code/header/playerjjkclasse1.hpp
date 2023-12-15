#include "playerjjk.hpp"

class PlayerJJKClasse1 : public PlayerJJK
{
    protected :
    float _occultenergy;
    float _color;

    public : 
    PlayerJJKClasse1(std::string lastname, std::string firstname, float Xp, float speed, float x, float y, float occultenergy, float color);
    ~PlayerJJKClasse1(){};
    void invocation();
    void extension();

};

