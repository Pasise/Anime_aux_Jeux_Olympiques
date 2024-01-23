#include "header/main.hpp"

int main() {
    sf::RenderWindow  window(sf::VideoMode(1920, 1080), "One Piece vs Bleach", sf::Style::Fullscreen);

    Game game;
    //Play the background music
    game.playBackgroundMusic();

    // Call the intro method
    game.intro(window);

    game.choose(window);
    // Call the run method
    game.run(window);

    return 0;
}