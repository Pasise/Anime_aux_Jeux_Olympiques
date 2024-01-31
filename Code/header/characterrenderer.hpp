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
    void render2(sf::RenderWindow& window);
    void setTexture(const std::string& texturePath) { _backgroundTexturePath = texturePath; loadBackgroundTexture(); }
    void setFruits(const std::vector<std::shared_ptr<Fruit>>* fruits);
    void renderFruits(sf::RenderWindow& window); 
    std::string getTexturePathFruits(int i){ 
        std::string file_name = _fruits->at(i)->getTexturePath();
        return file_name;
    }
    void renderHealthBarsBots(sf::RenderWindow& window);
    void renderPlayerCurser(sf::RenderWindow& window);



private:
    const std::vector<std::shared_ptr<Player>>* _players;
    const std::vector<std::shared_ptr<Fruit>>* _fruits; 
    std::vector<sf::Sprite> _sprites;
    std::vector<sf::Sprite> _fruitSprites; 
    std::vector<int> _currentFrames;
    std::vector<sf::Sprite> _attackSprites; 
    sf::Clock _clock;
    float _frameChangeSpeed;
    std::map<std::string, int> _frameCounts;

    std::string _backgroundTexturePath;
    sf::Texture _backgroundTexture;  
    sf::Sprite _backgroundSprite;     

    sf::Texture _healthBarTexture;

    void loadBackgroundTexture();
    void loadPlayerTexture(const std::shared_ptr<Player>& player, sf::Sprite& sprite, int textureIndex);
    void loadFruitTexture(const std::shared_ptr<Fruit>& fruit, sf::Sprite& sprite);
    void renderPosition(sf::RenderWindow& window, std::size_t index);
    void renderAttack1(sf::RenderWindow& window, std::size_t index);
    void renderAttack2(sf::RenderWindow& window, std::size_t index);
    void renderHeal(sf::RenderWindow& window, std::size_t index);
    void renderDeath(sf::RenderWindow& window, std::size_t index);
    
};

