#include "../header/characterrenderer.hpp"

CharacterRenderer::CharacterRenderer() 
    : _players(nullptr), _sprites(), _currentFrames(), _frameChangeSpeed(0.1) 
{

}

CharacterRenderer::CharacterRenderer(const std::vector<std::shared_ptr<Player>>* players)
    : _players(players), _sprites(), _currentFrames(players->size(), 0), _frameChangeSpeed(0.08)
{
    if (_players)
    {
        for (const auto& player : *_players)
        {
            if (player)
            {
                sf::Sprite sprite;
                sf::Texture playerTexture;
                playerTexture.loadFromFile(player->getTexture());
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
    // Mesure du temps écoulé depuis le dernier changement de frame
    sf::Time elapsedTime = _clock.getElapsedTime();

    // Vérification si le temps écoulé est supérieur à la vitesse de changement de frame
    if (elapsedTime.asSeconds() > _frameChangeSpeed) {
        // Changement de frame pour chaque joueur
        for (std::size_t i = 0; i < _currentFrames.size(); ++i)
        {
            _currentFrames[i] = (_currentFrames[i] + 1) % 4;  // Changez 4 selon le nombre total de frames
        }

        // Réinitialisation de l'horloge
        _clock.restart();
    }

    // Dessinez chaque sprite sur la fenêtre
    for (std::size_t i = 0; i < _sprites.size(); ++i)
    {
        if ((*_players)[i])
        {
            std::string playerTexturePath = (*_players)[i]->getTexture();
            sf::Texture texture;

            if (texture.loadFromFile(playerTexturePath))
            {
                // Calcul de la taille d'une frame
                sf::Vector2u frameSize(texture.getSize().x / 4, texture.getSize().y);

                // Calcul de l'indice de la frame à afficher
                int currentFrame = _currentFrames[i];

                // Calcul du rectangle source pour la frame actuelle
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
    }
}
