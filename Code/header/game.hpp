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
#include <SFML/Audio.hpp>

class Game {
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::shared_ptr<Fruit>> _fruits; // Added _fruits attribute
    UserInput _input;
    CharacterRenderer _characterRenderer;
    std::vector<std::string> chooseScreen;
    sf::Music _backgroundMusic; 
    sf::Music _healMusic;
    sf::Music _attackMusic;
    sf::Music _pickMusic;
    sf::Music _atacckedMusic;
public:
    Game();
    std::string getchooseScreen(int i){
        std::string file_name = chooseScreen[i];
        file_name.erase(file_name.end()-4, file_name.end());
        return file_name;
    
    }
    void run(sf::RenderWindow& window, size_t i);
    bool waitForMouseClickInRegion(sf::RenderWindow& window, int minX, int maxX, int minY, int maxY);
    void handleIntroLogic(sf::RenderWindow& window);
    void intro(sf::RenderWindow& window);
    void choose(sf::RenderWindow& window, size_t& i);
    void applyPlayerChosen(int i){ 
        std::shared_ptr<Player> temp = _players[0];
        _players[0] = _players[i];
        _players[i] = temp;}
    void updateStatePlayerUser(const UserInput& input);
    void updateStateBots();
    void win(sf::RenderWindow& window);
    void lose(sf::RenderWindow& window);
    void playBackgroundMusic();
    void stopBackgroundMusic();
    void playHealSound();
    void playAttackSound();
    void playPickSound();
    void playAttackedSound();
    void setPlayerPositionAndStatus(size_t index, float yPos, bool isAlive);
    void checkExitConditions(bool& exitRun, size_t& winner);
    void updateStates();
    void render(sf::RenderWindow& window, std::shared_ptr<PlayerPlus> captainPlayer);
    void handleWinLose(size_t winner, sf::RenderWindow& window);
    void handleAttack(int attackType);
    size_t basicAttack();
    size_t captainPlayerAttack(const std::shared_ptr<PlayerPlus>& captainPlayer);
    void handlePick();
    void handleHeal();

    private :

    void displayIntroScreen(sf::RenderWindow& window);
    void displayStartScreen(sf::RenderWindow& window);
    void displayExitScreen(sf::RenderWindow& window);
    void loadAndDrawTexture(sf::RenderWindow& window, const std::string& filePath);
    void moveImageIterator(std::vector<std::string>::iterator& it, size_t& i, int direction);

};