#pragma once

#include <iostream>
#include "player.hpp"
#include "userinput.hpp"
#include "playerjjk.hpp"
#include "playerjjkclasse1.hpp"
#include "playerjjkclasseS.hpp"
#include "playeronepiece.hpp"
#include "playeronepiecemugiwara.hpp"
#include "playeronepiecemugiwarafd.hpp"
#include "playerbleach.hpp"
#include "playerbleachshinigami.hpp"
#include "playerbleachshinigamicapitaine.hpp"
#include "characterrenderer.hpp"
#include <list>
#include <memory>

class Game {
    std::vector<std::shared_ptr<Player>> _players;
    UserInput _input;
    CharacterRenderer _characterRenderer;
public:
    Game();
    void run();
    void updateState(const UserInput& input);

};