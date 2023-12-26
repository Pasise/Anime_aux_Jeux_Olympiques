// Game.cpp
#include "../header/game.hpp"


Game::Game() : _players(), _characterRenderer(&_players)  
{
    // Crée le joueur de classe 1 Fushiguro Megumi
    std::shared_ptr<Player> player1 = std::make_shared<PlayerJJKClasse1>("Fushiguro", "Megumi", 0, 1.3, 0, 0, -1, 0, "../Sprite/Byakuya_Kuchiki_Run3.png");
    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players);

    // Crée le joueur de classe S Satoru Gojo
    std::shared_ptr<Player> player2 = std::make_shared<PlayerJJKClasseS>("Satoru", "Gojo", 0, 1.3, 0, 0, -1, 0, "../Sprite/Attack_3.png");
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players);

}
void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!"); 
    //créer un fond d'écran bleu
    window.clear(sf::Color::Blue); // Clear the window to blue

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //std::cout << "The game is running" << std::endl;
            _input.manageInput(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateState(_input);

        window.clear();
        window.clear(sf::Color::Green); // Clear the window to blue
        _characterRenderer.render(window
        );
        //je veux que le fond d'écran soit bleu
        window.display();
    }
}
//la méthode action prend en entrer un UserInput et effectue l'action correspondante : pour left on décrémente la position x et poour right on l'incrémente

void Game::updateState(const UserInput &input)
{
    // Vérifiez si les pointeurs dans _players sont valides avant d'appeler les méthodes sur eux
    for (auto &player : _players)
    {
        if (player)
        {
            if (input.getButton() == Button::left)
                player->moveLeft();
            else if (input.getButton() == Button::right)
                player->moveRight();
            else if (input.getButton() == Button::attack1)
                player->doAttack1();
            else if (input.getButton() == Button::attack2)
                player->doAttack2();
            else if (input.getButton() == Button::attack3)
                player->doAttack3();
            else if (input.getButton() == Button::attack4)
                player->doAttack4();
            else if (input.getButton() == Button::pick)
                player->doJump();
            else
                player->doPick();
        }
    }
}
