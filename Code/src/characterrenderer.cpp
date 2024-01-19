#include "../header/characterrenderer.hpp"

CharacterRenderer::CharacterRenderer()
    : _players(nullptr), _sprites(), _currentFrames(), _frameChangeSpeed(0.1)
{
    std::cout << "CharacterRenderer created" << std::endl;
}

CharacterRenderer::CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players, const std::string& backgroundTexturePath)
    : _players(players),
      _sprites(players->size()),
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
    else
    {
        std::cout << "Invalid pointer to players" << std::endl;
    }
}



// ... (votre code existant)

void CharacterRenderer::renderPosition(sf::RenderWindow& window, std::size_t index)
{
        if ((*_players)[index] && !(*_players)[index]->isAttacking1()) {
            std::string playerTexturePath = (*_players)[index]->getTexturePath(1);

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