// Game.cpp
#include "../header/game.hpp"
#include "../header/constant.hpp"

Game::Game() : _players(), _characterRenderer(&_players,BACKGROUND)  
{
    //Crée le joueur de classe 1 Fushiguro Megumi
    std::shared_ptr<Player> player1 = std::make_shared<PlayerJJKClasse1>(LASTNAME_JJKCLASSE1, FIRSTNAME_JJKCLASSE1, XP_JJKCLASSE1, SPEED_JJKCLASSE1, X_JJKCLASSE1, Y_JJKCLASSE1, OCULTENERGY_JJKCLASSE1, COLOR_JJKCLASSE1, MEGUMIASSOCIATION);

    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    // Crée le joueur de classe S Satoru Gojo
    std::shared_ptr<Player> player2 = std::make_shared<PlayerJJKClasseS>(LASTNAME_JJKCLASSES, FIRSTNAME_JJKCLASSES, XP_JJKCLASSES, SPEED_JJKCLASSES, X_JJKCLASSES, Y_JJKCLASSES, OCULTENERGY_JJKCLASSES, COLOR_JJKCLASSES, GOJOASSOCIATION);
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;


    // Crée le joueur de l'équipage du Mugiwara Roronoa Zoro
    std::shared_ptr<Player> player3 = std::make_shared<PlayerOnePieceMugiwara>(LASTNAME_ONEPIECEMUGIWARA, FIRSTNAME_ONEPIECEMUGIWARA, XP_ONEPIECEMUGIWARA, SPEED_ONEPIECEMUGIWARA, X_ONEPIECEMUGIWARA, Y_ONEPIECEMUGIWARA, VOL_ONEPIECEMUGIWARA, ZOROASSOCIATION);
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[2]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND); 

    // Crée le joueur de l'équipage du Mugiwara Monkey D. Luffy avec un fruit du démon
    std::shared_ptr<Player> player4 = std::make_shared<PlayerOnePieceMugiwaraFD>(LASTNAME_ONEPIECEMUGIWARAFDJ1, FIRSTNAME_ONEPIECEMUGIWARAFDJ1, XP_ONEPIECEMUGIWARAFDJ1, SPEED_ONEPIECEMUGIWARAFDJ1, X_ONEPIECEMUGIWARAFDJ1, Y_ONEPIECEMUGIWARAFDJ1, VOL_ONEPIECEMUGIWARAFDJ1, LUFFYASSOCIATION);
    _players.push_back(player4);  // Ajoutez le joueur à la liste
    std::cout << "Player 4 in the list" << std::endl;
    std::cout << "Player 4 name : " << _players[3]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);


    // Crée le joueur de l'équipage du Mugiwara Trafalgar D. Water Law avec un fruit du démon
    std::shared_ptr<Player> player5 = std::make_shared<PlayerOnePieceMugiwara>(LASTNAME_ONEPIECEMUGIWARAFDJ2, FIRSTNAME_ONEPIECEMUGIWARAFDJ2, XP_ONEPIECEMUGIWARAFDJ2, SPEED_ONEPIECEMUGIWARAFDJ2, X_ONEPIECEMUGIWARAFDJ2, Y_ONEPIECEMUGIWARAFDJ2, VOL_ONEPIECEMUGIWARAFDJ2,  TRAFALGARASSOCIATION);
    _players.push_back(player5);  // Ajoutez le joueur à la liste
    std::cout << "Player 5 in the list" << std::endl;
    std::cout << "Player 5 name : " << _players[4]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);

    //Cree le joeur de Bleach Kuchiki Rukia
    std::shared_ptr<Player> player6 = std::make_shared<PlayerBleachShinigami>(LASTNAME_BLEACHSHINIGAMI, FIRSTNAME_BLEACHSHINIGAMI, XP_BLEACHSHINIGAMI, SPEED_BLEACHSHINIGAMI, X_BLEACHSHINIGAMI, Y_BLEACHSHINIGAMI, SOIN_BLEACHSHINIGAMI, RUKIAASSOCIATION);
    _players.push_back(player6);  // Ajoutez le joueur à la liste
    std::cout << "Player 6 in the list" << std::endl;
    std::cout << "Player 6 name : " << _players[5]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);

    //Cree le joeur de Bleach Kuchiki Byakuya
    std::shared_ptr<Player> player7 = std::make_shared<PlayerBleachShinigamiCapitaine>(LASTNAME_BLEACHSHINIGAMICAPITAINE, FIRSTNAME_BLEACHSHINIGAMICAPITAINE, XP_BLEACHSHINIGAMICAPITAINE, SPEED_BLEACHSHINIGAMICAPITAINE, X_BLEACHSHINIGAMICAPITAINE, Y_BLEACHSHINIGAMICAPITAINE, SOIN_BLEACHSHINIGAMICAPITAINE, BYAKUYAASSOCIATION);
    _players.push_back(player7); 
    std::cout << "Player 7 in the list" << std::endl;
    std::cout << "Player 7 name : " << _players[6]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);

    


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
        _characterRenderer.setTexture(BACKGROUND);
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
                    _players[i]->moveLeft();// Ajoutez le joueur à la liste
                else if (input.getButton() == Button::right)
                    _players[i]->moveRight();
                else if (input.getButton() == Button::attack1)
                    _players[i]->doAttack1(*_players[1]);
                else if (input.getButton() == Button::attack2)
                    _players[i]->doAttack2(*_players[2]);
                else if (input.getButton() == Button::attack3)
                    _players[i]->doAttack3(*_players[3]);
                else if (input.getButton() == Button::attack4)
                    _players[i]->doAttack4(*_players[4]);
                else if (input.getButton() == Button::pick)
                    _players[i]->doJump();
                else
                    _players[i]->doPick();
            }
            else
            {
                // Pour les autres joueurs, déplacez-les constamment vers la droite
                _players[i]->moveRight();
                for(size_t j = 0; j < _players.size(); ++j) // Pour chaque joueur
                {
                    if (i != j && _players[j]->isCloseTo(*_players[i], DISTANCETREEHOLD)) // Si le joueur est proche d'un autre joueur
                    {
                        _players[i]->randomAttack(*_players[j]); // Attaque aléatoire
                        std::cout << "Player " << _players[i]->getFirstname()  << " is close to Player " << _players[j]->getFirstname()  << std::endl;
                    }
                }

            }
        }
    }
}
