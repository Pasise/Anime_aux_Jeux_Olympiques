#include <SFML/Graphics.hpp>
#include "main.hpp"




int main() {
    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animation et Déplacement du Sprite");

    //Pour la gestion des inputs
    Input input;

    // Chargement du sprite depuis un fichier (sprite sheet)
    sf::Texture texture;
    if (!texture.loadFromFile("../Sprite/Byakuya_Kuchiki_Run3.png")) {
        // Gestion de l'erreur si le chargement échoue
        return -1;
    }

    // Création du sprite et association de la texture
    sf::Sprite sprite(texture);

    // Taille d'une frame (un cadre) du sprite sheet
    sf::Vector2u frameSize(texture.getSize().x / 4, texture.getSize().y);

    // Position initiale du sprite
    sf::Vector2f position(100.0f, 100.0f);
    sprite.setPosition(position);

    // Vitesse de changement de frame
    float frameChangeSpeed = 0.1f;

    // Index de la frame actuelle
    unsigned int currentFrame = 0;

    // Vitesse de déplacement
    float speed = 2.0f;

    // Horloge pour mesurer le temps écoulé
    sf::Clock clock;
     //Direction du personnage
    int direction = 1;

    // Boucle principale
    while (window.isOpen()) {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        input.GestionDesInputs(event,window);
      

        // Mesure du temps écoulé depuis le dernier changement de frame
        sf::Time elapsedTime = clock.getElapsedTime();

        // Vérification si le temps écoulé est supérieur à la vitesse de changement de frame
        if (elapsedTime.asSeconds() > frameChangeSpeed) {
            // Changement de frame
            currentFrame = (currentFrame + 1) % 4;  // Changez 4 selon le nombre total de frames

            // Réinitialisation de l'horloge
            clock.restart();
        }

        // Gestion du mouvement vers la droite lorsque la touche "E" est enfoncée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            position.x += speed * elapsedTime.asSeconds();
            direction = 1;
        }

        // Gestion du mouvement vers la gauche lorsque la touche "Q" est enfoncée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            position.x -= speed * elapsedTime.asSeconds();
            direction = -1;
        }

        // Calcul de la partie du sprite sheet à afficher (source rectangle)
        sf::IntRect sourceRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y);

        // Mise à jour de la position du sprite
        sprite.setPosition(position);

        // Affichage du sprite avec la frame actuelle
        sprite.setTextureRect(sourceRect);

        // Effacement de l'écran
        window.clear();

        // Affichage du sprite
        window.draw(sprite);

        // Affichage à l'écran
        window.display();

        // Ajuster la direction du sprite horizontalement si le personnage se déplace vers la gauche
        sprite.setScale(direction, 1);
        
    }



    return 0;
}


 