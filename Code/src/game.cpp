// Game.cpp
#include "../header/game.hpp"


Game::Game() : _players(), _characterRenderer(&_players,"../Sprite/Background1.2merged.png")  
{
    // Crée le joueur de classe 1 Fushiguro Megumi
    std::shared_ptr<Player> player1 = std::make_shared<PlayerJJKClasse1>("Fushiguro", "Megumi", 0, 2.5, -1, 580, -1, 0, "../Sprite/Byakuya_Kuchiki_Run4.png");

    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    // Crée le joueur de classe S Satoru Gojo
    std::shared_ptr<Player> player2 = std::make_shared<PlayerJJKClasseS>("Satoru", "Gojo", 0, 1.3, 0, 590, 1, 0, "../Sprite/luffy_walkreverse4.png");
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;


    // Crée le joueur de l'équipage du Mugiwara Roronoa Zoro
    std::shared_ptr<Player> player3 = std::make_shared<PlayerOnePieceMugiwara>("Roronoa", "Zoro", 0, 1.3, 0, 740, -1, 0, "../Sprite/zoro_walk.png");
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[2]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,"../Sprite/Background1.2merged.png"); 

    // Crée le joueur de l'équipage du Mugiwara Monkey D. Luffy avec un fruit du démon
    std::shared_ptr<Player> player4 = std::make_shared<PlayerOnePieceMugiwaraFD>("Monkey D.", "Luffy", 0, 0.7, 0, 580, -1, 0, "../Sprite/Attack_2.png");
    _players.push_back(player4);  // Ajoutez le joueur à la liste
    std::cout << "Player 4 in the list" << std::endl;
    std::cout << "Player 4 name : " << _players[3]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,"../Sprite/Background1.2merged.png");


    // Crée le joueur de l'équipage du Mugiwara Trafalgar D. Water Law avec un fruit du démon
    std::shared_ptr<Player> player5 = std::make_shared<PlayerOnePieceMugiwara>("Trafalgar D.", "Water Law", 0, 0.6, 0, 580, -1, 0, "../Sprite/Attack_2.png");
    _players.push_back(player5);  // Ajoutez le joueur à la liste
    std::cout << "Player 5 in the list" << std::endl;
    std::cout << "Player 5 name : " << _players[4]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,"../Sprite/Background1.2merged.png");

    //Cree le joeur de Bleach Byakuya Kuchiki
    std::shared_ptr<Player> player6 = std::make_shared<PlayerBleachShinigami>("Kuchiki", "Byakuya", 0, 1.3, 0, 580, -1, "../Sprite/Byakuya_Kuchiki_Run4.png");
    _players.push_back(player6);  // Ajoutez le joueur à la liste
    std::cout << "Player 6 in the list" << std::endl;
    std::cout << "Player 6 name : " << _players[5]->getFirstname() << std::endl;
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
