#include "../header/characterrenderer.hpp"
#include "../header/playersoin.hpp"
#include "../header/fruit.hpp"

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
        std::cout << "Invalid pointer to players" << std::endl;
    }
}



// ... (votre code existant)

void CharacterRenderer::renderPosition(sf::RenderWindow& window, std::size_t index)
{
    std::shared_ptr<PlayerSoin> captainPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[index]);
        if ((*_players)[index] && !(*_players)[index]->isAttacking1() &&( !captainPlayer || !captainPlayer->isAttacking1())){
            std::string playerTexturePath = (*_players)[index]->getTexturePath(2);

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

    // ... rest of the code for scaling and additional conditions
}

void CharacterRenderer::renderAttack2(sf::RenderWindow& window, std::size_t index)
{
    std::shared_ptr<PlayerSoin> captainPlayer = std::dynamic_pointer_cast<PlayerSoin>((*_players)[index]);

    if ((*_players)[index] && captainPlayer && captainPlayer->isAttacking1()) {
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

    // ... rest of the code for scaling and additional conditions
}



void CharacterRenderer::render(sf::RenderWindow& window)
{
    sf::Time elapsedTime = _clock.getElapsedTime();

    if (elapsedTime.asSeconds() > _frameChangeSpeed) {
        for (std::size_t i = 0; i < _currentFrames.size(); ++i) {
            std::string texturePath = (*_players)[i]->getTexturePath(0);
            _currentFrames[i] = (_currentFrames[i] + 1) % _frameCounts[texturePath];
        }

        _clock.restart();
    }

    window.draw(_backgroundSprite);

    for (std::size_t i = 0; i < _sprites.size(); ++i) {
        renderPosition(window, i);
        renderAttack1(window, i);
        renderAttack2(window, i);
    }
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
    std::cout << "Rendering fruits" << std::endl;

    
 //Placer les fruits à des endroits aléatoire 
    for (std::size_t i = 0; i < _fruits->size(); ++i) {
        _fruitSprites[i].setPosition((*_fruits)[i]->getX(), (*_fruits)[i]->getY());
        window.draw(_fruitSprites[i]);
    }
    
}

