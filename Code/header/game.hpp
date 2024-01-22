#pragma once

#include <iostream>
#include "player.hpp"
#include "userinput.hpp"
#include "playerplus.hpp"
#include "playersoin.hpp"
#include "characterrenderer.hpp"
#include <list>
#include <vector>
#include <map>
#include <memory>

class Game {
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::shared_ptr<Fruit>> _fruits; // Added _fruits attribute
    UserInput _input;
    CharacterRenderer _characterRenderer;
    std::vector<std::string> chooseScreen;
public:
    Game();
    std::string getchooseScreen(int i){
        std::string file_name = chooseScreen[i];
        file_name.erase(file_name.end()-4, file_name.end());
        return file_name;
    
    }
    void run(sf::RenderWindow& window);
    void intro(sf::RenderWindow& window);
    void choose(sf::RenderWindow& window);
    void updateState(const UserInput& input);

};