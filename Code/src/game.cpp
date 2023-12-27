// Game.cpp
#include "../header/game.hpp"


Game::Game() : _players(), _characterRenderer(&_players,"../Sprite/Background1.2merged.png")  
{
    // Crée le joueur de classe 1 Fushiguro Megumi
    std::shared_ptr<Player> player1 = std::make_shared<PlayerJJKClasse1>("Fushiguro", "Megumi", 0, 1.9, 0, 580, -1, 0, "../Sprite/Byakuya_Kuchiki_Run3.png");

    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    // Crée le joueur de classe S Satoru Gojo
    std::shared_ptr<Player> player2 = std::make_shared<PlayerJJKClasseS>("Satoru", "Gojo", 0, 1.3, 0, 580, -1, 0, "../Sprite/Attack_3.png");
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;


    // Crée le joueur de l'équipage du Mugiwara Roronoa Zoro
    std::shared_ptr<Player> player3 = std::make_shared<PlayerOnePieceMugiwara>("Roronoa", "Zoro", 0, 0.8, 0, 580, -1, 0, "../Sprite/Attack_2.png");
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[2]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,"../Sprite/Background1.2merged.png");

}
void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            _input.manageInput(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateState(_input);

        // Mise à jour de la position de la caméra en fonction de la position du personnage
        if (!_players.empty() && _players[0])
        {
            float playerX = _players[0]->getX();
            _characterRenderer.setCameraPosition(-playerX);
        }

        window.clear();
        _characterRenderer.setTexture("../Sprite/Background1.2merged.png");
        _characterRenderer.render(window);
        window.display();
    }
}


//la méthode action prend en entrer un UserInput et effectue l'action correspondante : pour left on décrémente la position x et poour right on l'incrémente

void Game::updateState(const UserInput &input)
{
    // Vérifiez si les pointeurs dans _players sont valides avant d'appeler les méthodes sur eux
    for (size_t i = 0; i < _players.size(); ++i)
    {
        if (_players[i])
        {
            if (i == 0)
            {
                // Seulement pour le premier joueur, utilisez les entrées de l'utilisateur
                if (input.getButton() == Button::left)
                    _players[i]->moveLeft();
                else if (input.getButton() == Button::right)
                    _players[i]->moveRight();
                else if (input.getButton() == Button::attack1)
                    _players[i]->doAttack1();
                else if (input.getButton() == Button::attack2)
                    _players[i]->doAttack2();
                else if (input.getButton() == Button::attack3)
                    _players[i]->doAttack3();
                else if (input.getButton() == Button::attack4)
                    _players[i]->doAttack4();
                else if (input.getButton() == Button::pick)
                    _players[i]->doJump();
                else
                    _players[i]->doPick();
            }
            else
            {
                // Pour les autres joueurs, déplacez-les constamment vers la droite
                _players[i]->moveRight();
            }
        }
    }
}
