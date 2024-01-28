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

CharacterRenderer::CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players,const std::vector<std::shared_ptr<Fruit>>* fruits, const std::string& backgroundTexturePath)
    : _players(players),
      _fruits(fruits), // Initialiser _fruits ici
      _sprites(players->size()),
      _fruitSprites(fruits->size()), // Initialiser _fruitSprites ici
      _currentFrames(players->size(), 0),
      _attackSprites(players->size()), // Initialiser _attackSprites ici
      _frameChangeSpeed(0.08),
      _backgroundTexturePath(backgroundTexturePath)
{
    std::cout << "CharacterRenderer created" << std::endl;
    loadBackgroundTexture();

    if (_players)
    {
        for (std::size_t i = 0; i < _players->size(); ++i)
        {
            const auto& player = (*_players)[i];
            if (player)
            {
                sf::Sprite sprite;
                sf::Texture playerTexture;
                playerTexture.loadFromFile(player->getTexturePath(0));
                sprite.setTexture(playerTexture);
                _sprites[i] = sprite;

                sf::Sprite attackSprite;  // Ajout de la création d'une sprite d'attaque
                sf::Texture attackTexture;
                attackTexture.loadFromFile(player->getTexturePath(1));
                attackSprite.setTexture(attackTexture);
                _attackSprites[i] = attackSprite;
                std::cout << "Player texture loaded" << std::endl;
                    for (const auto& player : *_players) {
        if (player) {
            _frameCounts[player->getTexturePath(0)] = player->getNumberOfFrames(player->getTexturePath(0));
            _frameCounts[player->getTexturePath(1)] = player->getNumberOfFrames(player->getTexturePath(1));

            std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(player);
            std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(player);
            if (captainPlayer || soinPlayer)
            _frameCounts[player->getTexturePath(2)] = player->getNumberOfFrames(player->getTexturePath(2));

        }
                    }
            }
        }
    }

    // Initialiser _fruitSprites ici
    if (_fruits)
    {
        for (std::size_t i = 0; i < _fruits->size(); ++i)
        {
            const auto& fruit = (*_fruits)[i];
            if (fruit)
            {
                sf::Sprite sprite;
                sf::Texture fruitTexture;
                fruitTexture.loadFromFile(fruit->getTexturePath());
                sprite.setTexture(fruitTexture);
                _fruitSprites[i] = sprite;
                std::cout << "Fruit texture loaded" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Invalid pointer to players or fruits" << std::endl;
    }
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

    // ... rest of the code for scaling and additional conditions
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
    // Définissez la position de la caméra par rapport au personnage
    _backgroundSprite.setPosition(x, 0);
}

void CharacterRenderer::setFruits(const std::vector<std::shared_ptr<Fruit>>* fruits) {
    _fruits = fruits;

    // Assurez-vous que _fruitSprites a la même taille que _fruits
    _fruitSprites.resize(_fruits->size());

    // Initialisez chaque sprite avec la texture appropriée
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
            frameSize.y /= 1; //je veux que le sprite soit affiché en continue

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

    // Vérifiez si les points d'expérience sont égaux à zéro
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



