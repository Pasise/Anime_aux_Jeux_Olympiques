#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "fruit.hpp"
#include "userinput.hpp"
#include <memory>
#include <vector>

class CharacterRenderer {
public:
    CharacterRenderer();
    CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players,const std::vector<std::shared_ptr<Fruit>>* fruits , const std::string& backgroundTexturePath);
    std::string getTexture();
    void render(sf::RenderWindow& window);
    void setPlayers(const std::vector<std::shared_ptr<Player>>* players);
    void setTexture(const std::string& texturePath) { _backgroundTexturePath = texturePath; loadBackgroundTexture(); }
    void setCameraPosition(float x);
    void setFruits(const std::vector<std::shared_ptr<Fruit>>* fruits); // Ajout de la méthode setFruits
    void renderFruits(sf::RenderWindow& window); // Ajout de la méthode renderFruits

    void loadHealthBarTexture();
    void renderHealthBars(sf::RenderWindow& window);


private:
    const std::vector<std::shared_ptr<Player>>* _players;
    const std::vector<std::shared_ptr<Fruit>>* _fruits; // Added _fruits attribute  
    std::vector<sf::Sprite> _sprites;
    std::vector<sf::Sprite> _fruitSprites; // Added _fruitSprites attribute
    std::vector<int> _currentFrames;
    std::vector<sf::Sprite> _attackSprites; // Added _attackSprites attribute
    sf::Clock _clock;
    float _frameChangeSpeed;
    std::map<std::string, int> _frameCounts;

    std::string _backgroundTexturePath;
    sf::Texture _backgroundTexture;   // Added _backgroundTexture attribute
    sf::Sprite _backgroundSprite;     // Added _backgroundSprite attribute

    // Ajout de la texture pour la barre de vie
    sf::Texture _healthBarTexture;

    void loadBackgroundTexture();
    void renderPosition(sf::RenderWindow& window, std::size_t index);
    void renderAttack1(sf::RenderWindow& window, std::size_t index);
    void renderAttack2(sf::RenderWindow& window, std::size_t index);
    void renderHeal(sf::RenderWindow& window, std::size_t index);
    
};

