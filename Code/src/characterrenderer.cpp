#include "../header/characterrenderer.hpp"
#include "../header/playersoin.hpp"
#include "../header/fruit.hpp"
#include "../header/playerplus.hpp"
#include "../header/playermedium.hpp"

CharacterRenderer::CharacterRenderer()
    : _players(nullptr), _sprites(), _currentFrames(), _frameChangeSpeed(0.1)
{
    std::cout << "CharacterRenderer created" << std::endl;
}

CharacterRenderer::CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players, const std::vector<std::shared_ptr<Fruit>>* fruits, const std::string& backgroundTexturePath)
    : _players(players),
      _fruits(fruits),
      _sprites(players->size()),
      _fruitSprites(fruits->size()),
      _currentFrames(players->size(), 0),
      _attackSprites(players->size()),
      _frameChangeSpeed(0.08),
      _backgroundTexturePath(backgroundTexturePath)
{
    std::cout << "CharacterRenderer created" << std::endl;
    loadBackgroundTexture();

    if (_players) {
        for (size_t i = 0; i < _players->size(); ++i) {
            const auto& player = (*_players)[i];
            if (!player) continue;

            loadPlayerTexture(player, _sprites[i], 0);
            loadPlayerTexture(player, _attackSprites[i], 1);

            std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(player);
            std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(player);
            if (captainPlayer || soinPlayer) {
                loadPlayerTexture(player, _sprites[i], 2);
            }
        }
    }

    if (_fruits) {
        for (size_t i = 0; i < _fruits->size(); ++i) {
            const auto& fruit = (*_fruits)[i];
            if (!fruit) continue;

            loadFruitTexture(fruit, _fruitSprites[i]);
        }
    } else {
        std::cout << "Invalid pointer to players or fruits" << std::endl;
    }
}

void CharacterRenderer::loadPlayerTexture(const std::shared_ptr<Player>& player, sf::Sprite& sprite, int textureIndex) {
    sf::Texture playerTexture;
    playerTexture.loadFromFile(player->getTexturePath(textureIndex));
    sprite.setTexture(playerTexture);
    std::cout << "Player texture loaded" << std::endl;

    _frameCounts[player->getTexturePath(textureIndex)] = player->getNumberOfFrames(player->getTexturePath(textureIndex));
}

void CharacterRenderer::loadFruitTexture(const std::shared_ptr<Fruit>& fruit, sf::Sprite& sprite) {
    sf::Texture fruitTexture;
    fruitTexture.loadFromFile(fruit->getTexturePath());
    sprite.setTexture(fruitTexture);
    std::cout << "Fruit texture loaded" << std::endl;
}



void CharacterRenderer::renderPosition(sf::RenderWindow& window, std::size_t index)
{
    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>((*_players)[index]);
    std::shared_ptr<PlayerMedium> mediumPlayer = std::dynamic_pointer_cast<PlayerMedium>((*_players)[index]);
    std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[index]);
        if ((*_players)[index] && !(*_players)[index]->isAttacking1() &&( !captainPlayer || !captainPlayer->isAttacking2()) && (!soinPlayer || !soinPlayer->isHealing())){
            std::string playerTexturePath;
            if (captainPlayer || soinPlayer)
            playerTexturePath = (*_players)[index]->getTexturePath(2);
            else playerTexturePath = (*_players)[index]->getTexturePath(1);
            sf::Texture texture;
            if (texture.loadFromFile(playerTexturePath)) {
                sf::Vector2u frameSize = texture.getSize();
                frameSize.x /= (*_players)[index]->getNumberOfFrames(playerTexturePath);
                frameSize.y /= 1;
                int currentFrame = _currentFrames[index];
                sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

                _sprites[index].setTexture(texture);
                _sprites[index].setTextureRect(sourceRect);
                _sprites[index].setPosition((*_players)[index]->getX(), (*_players)[index]->getY());

                window.draw(_sprites[index]);
            }
            else {
                std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
            }
        }

}

void CharacterRenderer::renderAttack1(sf::RenderWindow& window, std::size_t index)
{
        if ((*_players)[index] && (*_players)[index]->isAttacking1()) {
            std::string playerTexturePath = (*_players)[index]->getTexturePath(0);

            sf::Texture texture;
            if (texture.loadFromFile(playerTexturePath)) {
                sf::Vector2u frameSize = texture.getSize();
                frameSize.x /= (*_players)[index]->getNumberOfFrames(playerTexturePath);
                frameSize.y /= 1;
                int currentFrame = _currentFrames[index];
                sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

                _attackSprites[index].setTexture(texture);
                _attackSprites[index].setTextureRect(sourceRect);
                _attackSprites[index].setPosition((*_players)[index]->getX(), (*_players)[index]->getY());

                window.draw(_attackSprites[index]);
            }
            else {
                std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
            }
        }

}

void CharacterRenderer::renderAttack2(sf::RenderWindow& window, std::size_t index)
{
    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>((*_players)[index]);

    if ((*_players)[index] && captainPlayer && captainPlayer->isAttacking2() && !captainPlayer->isAttacking1()) {
        std::string playerTexturePath = captainPlayer->getTexturePath(1);

        sf::Texture texture;
        if (texture.loadFromFile(playerTexturePath)) {
            sf::Vector2u frameSize = texture.getSize();
            frameSize.x /= captainPlayer->getNumberOfFrames(playerTexturePath);
            frameSize.y /= 1;
            int currentFrame = _currentFrames[index];
            sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

            _attackSprites[index].setTexture(texture);
            _attackSprites[index].setTextureRect(sourceRect);
            _attackSprites[index].setPosition(captainPlayer->getX(), captainPlayer->getY());

            window.draw(_attackSprites[index]);
        }
        else {
            std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
        }
    }

}

void CharacterRenderer::renderHeal(sf::RenderWindow& window, std::size_t index)
{
    std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[index]);

    if ((*_players)[index] && soinPlayer && soinPlayer->isHealing() && !soinPlayer->isAttacking1()) {
        std::string playerTexturePath = soinPlayer->getTexturePath(1);

        sf::Texture texture;
        if (texture.loadFromFile(playerTexturePath)) {
            sf::Vector2u frameSize = texture.getSize();
            frameSize.x /= soinPlayer->getNumberOfFrames(playerTexturePath);
            frameSize.y /= 1;
            int currentFrame = _currentFrames[index];
            sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

            _attackSprites[index].setTexture(texture);
            _attackSprites[index].setTextureRect(sourceRect);
            _attackSprites[index].setPosition(soinPlayer->getX(), soinPlayer->getY());

            window.draw(_attackSprites[index]);
        }
        else {
            std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
        }
    }


}

void CharacterRenderer::renderDeath(sf::RenderWindow& window, std::size_t index)
{
    if ((*_players)[index] && !(*_players)[index]->isAlive()) {
        std::string playerTexturePath = (*_players)[index]->getDeathTexturePath();

        sf::Texture texture;
        if (texture.loadFromFile(playerTexturePath)) { 
            sf::Vector2u frameSize = texture.getSize(); 
            frameSize.x /= 1; 
            frameSize.y /= 1;

            _sprites[index].setTexture(texture);
            _sprites[index].setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
            _sprites[index].setPosition((*_players)[index]->getX()-900, (*_players)[index]->getY());



            window.draw(_sprites[index]);
        }
        else {
            std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
        }
    }

}

void CharacterRenderer::render(sf::RenderWindow& window)
{
    sf::Time elapsedTime = _clock.getElapsedTime();
    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>((*_players)[0]);
    std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[0]);

    if (elapsedTime.asSeconds() > _frameChangeSpeed) {
        for (std::size_t i = 0; i < _currentFrames.size(); ++i) {
            std::string texturePath;
            if (soinPlayer)
            texturePath = (*_players)[i]->getTexturePath(2);
            if (captainPlayer)
            texturePath = (*_players)[i]->getTexturePath(0);
            else texturePath = (*_players)[i]->getTexturePath(1);
            _currentFrames[i] = (_currentFrames[i] + 1) % (_frameCounts[texturePath]);
        }

        _clock.restart();
    }

    window.draw(_backgroundSprite);

    for (std::size_t i = 0; i < _sprites.size(); ++i) {
        if ((*_players)[i] && (*_players)[i]->isAlive()) {
            renderPosition(window, i);
            renderAttack1(window, i);
            renderAttack2(window, i);
            renderHeal(window, i);
        } else 
        renderDeath(window, i);
    }
        renderFruits(window);
}

void CharacterRenderer::render2(sf::RenderWindow& window)
{
    sf::Time elapsedTime = _clock.getElapsedTime();
    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>((*_players)[0]);
    std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[0]);

    if (elapsedTime.asSeconds() > _frameChangeSpeed) {
        for (std::size_t i = 0; i < _currentFrames.size(); ++i) {
            std::string texturePath;
            if (soinPlayer) texturePath = (*_players)[i]->getTexturePath(2);

            if (captainPlayer) texturePath = (*_players)[i]->getTexturePath(0);

            else texturePath = (*_players)[i]->getTexturePath(1);

            std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>((*_players)[i]);
            std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[i]);

            if (!captainPlayer)  _currentFrames[i] = (_currentFrames[i] + 1) % (_frameCounts[texturePath]-2);

            else if (!soinPlayer) _currentFrames[i] = (_currentFrames[i] + 1) % (_frameCounts[texturePath]+1);

            else _currentFrames[i] = (_currentFrames[i] + 1) % (_frameCounts[texturePath]-1);
        }

        _clock.restart();
    }

    window.draw(_backgroundSprite);

    for (std::size_t i = 0; i < _sprites.size(); ++i) {
        if ((*_players)[i] && (*_players)[i]->isAlive()) {
            renderPosition(window, i);
            renderAttack1(window, i);
            renderAttack2(window, i);
            renderHeal(window, i);
        } else 
        renderDeath(window, i);
    }
        renderFruits(window);
}

void CharacterRenderer::loadBackgroundTexture()
{
    if (!_backgroundTexture.loadFromFile(_backgroundTexturePath))
    {
        std::cerr << "Failed to load background texture: " << _backgroundTexturePath << std::endl;
    }
    _backgroundSprite.setTexture(_backgroundTexture);
}

void CharacterRenderer::setCameraPosition(float x)
{
    _backgroundSprite.setPosition(x, 0);
}

void CharacterRenderer::setFruits(const std::vector<std::shared_ptr<Fruit>>* fruits) {
    _fruits = fruits;

    _fruitSprites.resize(_fruits->size());
    for (std::size_t i = 0; i < _fruits->size(); ++i) {
        _fruitSprites[i].setTexture((*_fruits)[i]->getTexture());
    }
}

void CharacterRenderer::renderFruits(sf::RenderWindow& window) {
  
 //Placer les fruits à des endroits définis
    for (std::size_t i = 0; i < _fruits->size(); ++i) {
        if ((*_fruits)[i]->isAlive()) {
        std::string fruitTexturePath = (*_fruits)[i]->getTexturePath();
        sf::Texture texture;
        if (texture.loadFromFile(fruitTexturePath)) {
            sf::Vector2u frameSize = texture.getSize();
            frameSize.x /= 1;
            frameSize.y /= 1; 

            _fruitSprites[i].setTexture(texture);
            _fruitSprites[i].setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
            _fruitSprites[i].setPosition((*_fruits)[i]->getX(), (*_fruits)[i]->getY());

            window.draw(_fruitSprites[i]);
        }


        }
    }
    
}

void CharacterRenderer::loadHealthBarTexture() {
    if (!_healthBarTexture.loadFromFile("../Sprite/life.png")) {
        std::cerr << "Failed to load health bar texture." << std::endl;
    }
}

void CharacterRenderer::renderHealthBars(sf::RenderWindow& window) {
    // Utilise seulement le joueur 0
    const auto& player = (*_players)[0];

    // Vérifier si les points d'expérience sont égaux à zéro
    if (player->getXp() == 0) {
        return;
    }

    sf::Vector2f healthBarPosition(10.0f, 10.0f);
    float borderThickness = 5.0f;
    sf::RectangleShape backgroundBar(sf::Vector2f(player->getXpMax(), 20.0f));
    backgroundBar.setPosition(healthBarPosition);
    backgroundBar.setFillColor(sf::Color::Black);
    backgroundBar.setOutlineThickness(borderThickness);
    backgroundBar.setOutlineColor(sf::Color::White);

    float healthPercentage = static_cast<float>(player->getXp()) / static_cast<float>(player->getXpMax());
    float healthBarWidth = healthPercentage * player->getXpMax();

    float healthBarHeight = 20.0f;

    sf::Color healthBarColor = sf::Color::Green;

    if (healthPercentage <= 0.6f && healthPercentage > 0.3f) {
        healthBarColor = sf::Color::Yellow; 
    } else if (healthPercentage <= 0.3f) {
        healthBarColor = sf::Color::Red; 
    }

    sf::RectangleShape healthBar(sf::Vector2f(healthBarWidth, healthBarHeight));
    healthBar.setPosition(healthBarPosition);
    healthBar.setFillColor(healthBarColor);

    healthBar.setOutlineThickness(borderThickness);
    healthBar.setOutlineColor(sf::Color::White);

    window.draw(backgroundBar);
    window.draw(healthBar);
}

void CharacterRenderer::renderHealthBarsBots(sf::RenderWindow& window) {
    for (std::size_t i = 1; i < _players->size(); ++i) {
        const auto& player = (*_players)[i];

        // Vérifier si les points d'expérience sont égaux à zéro
        if (player->getXp() == 0) {
            continue;
        }
        float xBar = player->getX();
        float yBar = player->getY();
        if (player->getFirstname() == "Luffy") xBar+=100;
        else if (player->getFirstname() == "Zoro") xBar+=150;
        sf::Vector2f healthBarPosition(xBar, yBar - 20.0f);
        float borderThickness = 5.0f;
        sf::RectangleShape backgroundBar(sf::Vector2f(player->getXpMax(), 10.0f));
        backgroundBar.setPosition(healthBarPosition);
        backgroundBar.setFillColor(sf::Color::Black);
        backgroundBar.setOutlineThickness(borderThickness);
        backgroundBar.setOutlineColor(sf::Color::White);

        float healthPercentage = static_cast<float>(player->getXp()) / static_cast<float>(player->getXpMax());
        float healthBarWidth = healthPercentage * player->getXpMax();

        float healthBarHeight = 10.0f;

        sf::Color healthBarColor = sf::Color::Green;

        if (healthPercentage <= 0.6f && healthPercentage > 0.3f) {
            healthBarColor = sf::Color::Yellow; 
        } else if (healthPercentage <= 0.3f) {
            healthBarColor = sf::Color::Red; 
        }

        sf::RectangleShape healthBar(sf::Vector2f(healthBarWidth, healthBarHeight));
        healthBar.setPosition(healthBarPosition);
        healthBar.setFillColor(healthBarColor);

        healthBar.setOutlineThickness(borderThickness);
        healthBar.setOutlineColor(sf::Color::White);

        window.draw(backgroundBar);
        window.draw(healthBar);
    }
}
