#include <iostream>
#include "player.hpp"
#include "userinput.hpp"
#include <list>

class Game{
    std::list <Player> _players;
    UserInput _input;
    public :
    Game();
    void run();
    void updateState(UserInput input);
};