#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "userinput.hpp"
#include <memory>
#include <vector>

class CharacterRenderer {
public:
    CharacterRenderer();
    CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players, const std::string& backgroundTexturePath);
    std::string getTexture();
    void render(sf::RenderWindow& window);
    void setPlayers(const std::vector<std::shared_ptr<Player>>* players);
    void setTexture(const std::string& texturePath) { _backgroundTexturePath = texturePath; loadBackgroundTexture(); }
    void setCameraPosition(float x);

private:
    const std::vector<std::shared_ptr<Player>>* _players;
    std::vector<sf::Sprite> _sprites;
    std::vector<int> _currentFrames;
    sf::Clock _clock;
    float _frameChangeSpeed;

    std::string _backgroundTexturePath;
    sf::Texture _backgroundTexture;   // Added _backgroundTexture attribute
    sf::Sprite _backgroundSprite;     // Added _backgroundSprite attribute

    void loadBackgroundTexture();
};
