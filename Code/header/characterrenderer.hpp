#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "userinput.hpp"
#include <memory>
#include <vector>

class CharacterRenderer {
public:
    CharacterRenderer();
    CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players);
    
    void render(sf::RenderWindow& window);

private:
    const std::vector<std::shared_ptr<Player>>* _players;
    std::vector<sf::Sprite> _sprites; 
    std::vector<int> _currentFrames;  // Nouvel attribut pour stocker l'indice de la frame actuelle
    sf::Clock _clock;
    float _frameChangeSpeed;
};