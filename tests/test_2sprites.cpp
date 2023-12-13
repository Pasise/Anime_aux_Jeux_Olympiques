#include <SFML/Graphics.hpp>

int main() {
    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Deux Sprites");

    // Chargement des sprites depuis un fichier (sprite sheet)
    sf::Texture texture1, texture2;
    if (!texture1.loadFromFile("Attack_2.png") || !texture2.loadFromFile("Attack_3.png")) {
        // Gestion de l'erreur si le chargement échoue
        return -1;
    }

    // Création des sprites et association des textures
    sf::Sprite sprite1(texture1), sprite2(texture2);

    // Taille d'une frame (un cadre) des sprite sheets
    sf::Vector2u frameSize1(texture1.getSize().x / 4, texture1.getSize().y);
    sf::Vector2u frameSize2(texture2.getSize().x / 4, texture2.getSize().y);

    // Positions initiales des sprites
    sf::Vector2f position1(100.0f, 100.0f), position2(300.0f, 100.0f);
    sprite1.setPosition(position1);
    sprite2.setPosition(position2);

    // Vitesse de changement de frame
    float frameChangeSpeed = 0.1f;

    // Indices des frames actuelles
    unsigned int currentFrame1 = 0, currentFrame2 = 0;

    // Vitesse de déplacement
    float speed = 2.0f;

    // Horloge pour mesurer le temps écoulé
    sf::Clock clock;

    // Boucle principale
    while (window.isOpen()) {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mesure du temps écoulé depuis le dernier changement de frame
        sf::Time elapsedTime = clock.getElapsedTime();

        // Vérification si le temps écoulé est supérieur à la vitesse de changement de frame
        if (elapsedTime.asSeconds() > frameChangeSpeed) {
            // Changement de frame pour le sprite 1
            currentFrame1 = (currentFrame1 + 1) % 4;  // Changez 4 selon le nombre total de frames

            // Changement de frame pour le sprite 2
            currentFrame2 = (currentFrame2 + 1) % 4;  // Changez 4 selon le nombre total de frames

            // Réinitialisation de l'horloge
            clock.restart();
        }

        // Gestion du mouvement vers la droite pour le sprite 1 lorsque la touche "E" est enfoncée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            position1.x += speed * elapsedTime.asSeconds();
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            position2.x += speed * elapsedTime.asSeconds();
        }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            position1.x -= speed * elapsedTime.asSeconds();
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            position2.x -= speed * elapsedTime.asSeconds();
        }

        // Calcul des parties des sprite sheets à afficher (source rectangles)
        sf::IntRect sourceRect1(currentFrame1 * frameSize1.x, 0, frameSize1.x, frameSize1.y);
        sf::IntRect sourceRect2(currentFrame2 * frameSize2.x, 0, frameSize2.x, frameSize2.y);

        // Mise à jour des positions des sprites
        sprite1.setPosition(position1);
        sprite2.setPosition(position2);

        // Affichage des sprites avec les frames actuelles
        sprite1.setTextureRect(sourceRect1);
        sprite2.setTextureRect(sourceRect2);

        // Effacement de l'écran
        window.clear();

        // Affichage des sprites
        window.draw(sprite1);
        window.draw(sprite2);

        // Affichage à l'écran
        window.display();
    }

    return 0;
}
