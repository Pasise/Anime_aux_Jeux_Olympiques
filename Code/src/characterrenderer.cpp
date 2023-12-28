#include "../header/characterrenderer.hpp"

CharacterRenderer::CharacterRenderer()
    : _players(nullptr), _sprites(), _currentFrames(), _frameChangeSpeed(0.1)
{
    std::cout << "CharacterRenderer created" << std::endl;
}

CharacterRenderer::CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players, const std::string& backgroundTexturePath)
    : _players(players), _sprites(), _currentFrames(players->size(), 0), _frameChangeSpeed(0.08), _backgroundTexturePath(backgroundTexturePath)
{
    std::cout << "CharacterRenderer created" << std::endl;
    loadBackgroundTexture();

    if (_players)
    {
        for (const auto& player : *_players)
        {
            if (player)
            {
                sf::Sprite sprite;
                sf::Texture playerTexture;
                playerTexture.loadFromFile(player->getTexturePath(0));
                sprite.setTexture(playerTexture);
                _sprites.push_back(sprite);
                std::cout << "Player texture loaded" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Invalid pointer to players" << std::endl;
    }
}

void CharacterRenderer::render(sf::RenderWindow& window)
{
    sf::Time elapsedTime = _clock.getElapsedTime();

    if (elapsedTime.asSeconds() > _frameChangeSpeed) {
        for (std::size_t i = 0; i < _currentFrames.size(); ++i)
        {
            _currentFrames[i] = (_currentFrames[i] + 1) % 4;
        }

        _clock.restart();
    }

    // Dessinez le fond
    window.draw(_backgroundSprite);

    for (std::size_t i = 0; i < _sprites.size(); ++i)
    {
        if ((*_players)[i])
        {
            std::string playerTexturePath = (*_players)[i]->getTexturePath(0);
            sf::Texture texture;

            if (texture.loadFromFile(playerTexturePath))
            {
                sf::Vector2u frameSize = texture.getSize();
                frameSize.x /= (*_players)[i]->getNumberOfFrames(playerTexturePath);
                frameSize.y /= 1;
                int currentFrame = _currentFrames[i];
                sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

                _sprites[i].setTexture(texture);
                _sprites[i].setTextureRect(sourceRect);
                _sprites[i].setPosition((*_players)[i]->getX(), (*_players)[i]->getY());
                window.draw(_sprites[i]);
            }
            else
            {
                std::cerr << "Failed to load player texture: " << playerTexturePath << std::endl;
            }
        }

        if ((*_players)[i]->getDirection() == 1)
        {
            _sprites[i].setScale(1, 1);
        }
        else
        {
            _sprites[i].setScale(-1, 1);
        }
        if (((*_players)[i]->getFirstname() == "Luffy")||((*_players)[i]->getFirstname() == "Zoro"))
        {
            _sprites[i].setScale(-1, 1);
        }
    }
}

void CharacterRenderer::loadBackgroundTexture()
{
    if (!_backgroundTexture.loadFromFile(_backgroundTexturePath))
    {
        std::cerr << "Failed to load background texture: " << _backgroundTexturePath << std::endl;
    }
    _backgroundSprite.setTexture(_backgroundTexture);
    std::cout << "Background texture loaded" << std::endl;
}

void CharacterRenderer::setCameraPosition(float x)
{
    // Définissez la position de la caméra par rapport au personnage
    _backgroundSprite.setPosition(x, 0);
}