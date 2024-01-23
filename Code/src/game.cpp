// Game.cpp
#include "../header/game.hpp"
#include "../header/constant.hpp"


Game::Game() : _players(),_fruits(), _characterRenderer(&_players,&_fruits,BACKGROUND)  
{
    std::cout << "Game created" << std::endl;

    // Crée le joueur de shinigami capiaine de Bleach Kuchiki Byakuya
    std::shared_ptr<Player> player1 = std::make_shared<PlayerPlus>(LASTNAME_ICHIGO, FIRSTNAME_ICHIGO, XP_BLEACHSHINIGAMICAPITAINE, SPEED_BLEACHSHINIGAMICAPITAINE, X_BLEACHSHINIGAMICAPITAINE, Y_BLEACHSHINIGAMICAPITAINE, ICHIGOASSOCIATION);
    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);



    // Crée le joueur de l'équipage du Mugiwara Roronoa Zoro
    std::shared_ptr<Player> player3 = std::make_shared<PlayerPlus>(LASTNAME_ONEPIECEMUGIWARA, FIRSTNAME_ONEPIECEMUGIWARA, XP_ONEPIECEMUGIWARA, SPEED_ONEPIECEMUGIWARA, X_ONEPIECEMUGIWARA, Y_ONEPIECEMUGIWARA, ZOROASSOCIATION);
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[1]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 

    // Crée le joueur de l'équipage du Mugiwara Monkey D. Luffy avec un fruit du démon
    /*std::shared_ptr<Player> player4 = std::make_shared<PlayerOnePieceMugiwaraFD>(LASTNAME_ONEPIECEMUGIWARAFDJ1, FIRSTNAME_ONEPIECEMUGIWARAFDJ1, XP_ONEPIECEMUGIWARAFDJ1, SPEED_ONEPIECEMUGIWARAFDJ1, X_ONEPIECEMUGIWARAFDJ1, Y_ONEPIECEMUGIWARAFDJ1, VOL_ONEPIECEMUGIWARAFDJ1, LUFFYASSOCIATION);
    _players.push_back(player4);  // Ajoutez le joueur à la liste
    std::cout << "Player 4 in the list" << std::endl;
    std::cout << "Player 4 name : " << _players[2]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);


    // Crée le joueur de l'équipage du Mugiwara Trafalgar D. Water Law avec un fruit du démon
    std::shared_ptr<Player> player5 = std::make_shared<PlayerOnePieceMugiwara>(LASTNAME_ONEPIECEMUGIWARAFDJ2, FIRSTNAME_ONEPIECEMUGIWARAFDJ2, XP_ONEPIECEMUGIWARAFDJ2, SPEED_ONEPIECEMUGIWARAFDJ2, X_ONEPIECEMUGIWARAFDJ2, Y_ONEPIECEMUGIWARAFDJ2, VOL_ONEPIECEMUGIWARAFDJ2,  TRAFALGARASSOCIATION);
    _players.push_back(player5);  // Ajoutez le joueur à la liste
    std::cout << "Player 5 in the list" << std::endl;
    std::cout << "Player 5 name : " << _players[3]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);

    //Cree le joeur de Bleach Kuchiki Rukia
    std::shared_ptr<Player> player6 = std::make_shared<PlayerBleachShinigami>(LASTNAME_BLEACHSHINIGAMI, FIRSTNAME_BLEACHSHINIGAMI, XP_BLEACHSHINIGAMI, SPEED_BLEACHSHINIGAMI, X_BLEACHSHINIGAMI, Y_BLEACHSHINIGAMI, SOIN_BLEACHSHINIGAMI, RUKIAASSOCIATION);
    _players.push_back(player6);  // Ajoutez le joueur à la liste
    std::cout << "Player 6 in the list" << std::endl;
    std::cout << "Player 6 name : " << _players[4]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);

    //Cree le joeur de Bleach Kuchiki Byakuya
    std::shared_ptr<Player> player7 = std::make_shared<PlayerBleachShinigamiCapitaine>(LASTNAME_BLEACHSHINIGAMICAPITAINE, FIRSTNAME_BLEACHSHINIGAMICAPITAINE, XP_BLEACHSHINIGAMICAPITAINE, SPEED_BLEACHSHINIGAMICAPITAINE, X_BLEACHSHINIGAMICAPITAINE, Y_BLEACHSHINIGAMICAPITAINE, SOIN_BLEACHSHINIGAMICAPITAINE, BYAKUYAASSOCIATION);
    _players.push_back(player7); 
    std::cout << "Player 7 in the list" << std::endl;
    std::cout << "Player 7 name : " << _players[5]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,BACKGROUND);*/

    // Crée le fruit du démon de Luffy
    std::shared_ptr<Fruit> fruit1 = std::make_shared<Fruit>(NAME_FRUIT,Y_FRUIT,ENERGY_FRUIT,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit1);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 1 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 


    // Crée un fruit normal que tout le monde peut manger
    std::shared_ptr<Fruit> fruit2 = std::make_shared<Fruit>(NAME_FRUIT,Y_FRUITNORMAL,ENERGY_FRUITNORMAL,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit2);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 2 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);


    //Cree le masque hollow de Ichigo
    std::shared_ptr<Fruit> fruit3 = std::make_shared<Fruit>(NAME_FRUIT,Y_HOLLOW,ENERGY_HOLLOW,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit3);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 3 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    chooseScreen.push_back("../Sprite/Choose_Byakuya.PNG");
    chooseScreen.push_back("../Sprite/Choose_Ichigo.PNG");
    chooseScreen.push_back("../Sprite/Choose_Kyoraku.PNG");
    chooseScreen.push_back("../Sprite/Choose_Zoro.PNG");
    chooseScreen.push_back("../Sprite/Choose_Luffy.PNG");



}
void Game::intro(sf::RenderWindow& window) {
    // Open the intro window
    window.create(sf::VideoMode(1920, 1080), "One Piece vs Bleach", sf::Style::Fullscreen);

    // Load and display the intro image
    sf::Texture introTexture;
    if (introTexture.loadFromFile("../Sprite/home_screen.PNG")) {
        sf::Sprite introSprite(introTexture);
        window.draw(introSprite);
        window.display();
    } else {
        std::cerr << "Failed to load intro image." << std::endl;
        return;
    }

    // Wait for user input
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed &&
                       event.mouseButton.button == sf::Mouse::Left) {
                // Check if the mouse is within the specified rectangle
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (mousePosition.x >= 690 && mousePosition.x <= 1195 &&
                    mousePosition.y >= 770 && mousePosition.y <= 900) {
                    // Load and display the new image
                    sf::Texture startTexture;
                    if (startTexture.loadFromFile("../Sprite/home_screen_start.PNG")) {
                        sf::Sprite startSprite(startTexture);
                        window.draw(startSprite);
                        window.display();
                        sf::sleep(sf::seconds(0.5));
                        return;
                    } else {
                        std::cerr << "Failed to load start image." << std::endl;
                    }
                } else  if (mousePosition.x >= 820 && mousePosition.x <= 1055 &&
                    mousePosition.y >= 930 && mousePosition.y <= 1040) {
                    // Load and display the new image
                    sf::Texture startTexture;
                    if (startTexture.loadFromFile("../Sprite/home_screen_exit.PNG")) {
                        sf::Sprite startSprite(startTexture);
                        window.draw(startSprite);
                        window.display();
                        sf::sleep(sf::seconds(0.5));
                        window.close();
                    } else {
                        std::cerr << "Failed to load start image." << std::endl;
                    }
                }
                       }
        }
    }
}

void Game::choose(sf::RenderWindow& window) {
    sf::Event event;
    std::vector<std::string>::iterator currentImage = chooseScreen.begin();
    sf::Texture chooseTexture;
    if (chooseTexture.loadFromFile(*currentImage)) {
        sf::Sprite chooseSprite(chooseTexture);
        window.draw(chooseSprite);
        window.display();
    } else {
        std::cerr << "Failed to load choose image." << std::endl;
        return;
    }
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::D) {
                    // Afficher l'image suivante dans le vecteur
                    currentImage++;
                    if (currentImage == chooseScreen.end()) {
                        // Revenir au début du vecteur si nous sommes à la fin
                        currentImage = chooseScreen.begin();
                    }
                } else if (event.key.code == sf::Keyboard::Q) {
                    // Afficher l'image précédente dans le vecteur
                    if (currentImage == chooseScreen.begin()) {
                        // Aller à la fin du vecteur si nous sommes au début
                        currentImage = chooseScreen.end();
                    }
                    currentImage--;
                }
                // Charger et afficher l'image actuelle
                if (chooseTexture.loadFromFile(*currentImage)) {
                    sf::Sprite chooseSprite(chooseTexture);
                    window.draw(chooseSprite);
                    window.display();
                } else {
                    std::cerr << "Failed to load choose image." << std::endl;
                    return;
                }
            } else if (event.type == sf::Event::MouseButtonPressed &&
                       event.mouseButton.button == sf::Mouse::Left) {
                // Vérifier si la souris est dans la zone spécifiée
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (mousePosition.x >= 1500 && mousePosition.x <= 1855 &&
                    mousePosition.y >= 940 && mousePosition.y <= 1025) {
                    // Construire le nouveau nom de fichier avec "1.PNG" ajouté
                    std::string newFileName = *currentImage;
                    newFileName.insert(newFileName.find_last_of('.'), "1");

                    // Charger et afficher la nouvelle image
                    sf::Texture newTexture;
                    if (newTexture.loadFromFile(newFileName)) {
                        sf::Sprite newSprite(newTexture);
                        window.draw(newSprite);
                        window.display();
                        sf::sleep(sf::seconds(0.5));
                        return;
                    } else {
                        std::cerr << "Failed to load " << newFileName << std::endl;
                        return;
                    }
                }
            }
        }
    }
}

void Game::run(sf::RenderWindow& window)
{
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                _input.manageInput(event, window);
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            updateState(_input);

            window.clear();
            _characterRenderer.setTexture(BACKGROUND);
            _characterRenderer.render(window);
            _characterRenderer.renderFruits(window);
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
                _players[i]->setSpeed(XPMULTIPLIER);
                //Appeler la fonction getRandomNumber pour avoir un nombre aléatoire entre 0 et 1
                _players[i]->getRandomNumberForCanAttack();
                // Seulement pour le premier joueur, utilisez les entrées de l'utilisateur
                if (input.getButton() == Button::left)
                    _players[i]->moveLeft();// Ajoutez le joueur à la liste
                else if (input.getButton() == Button::right)
                    _players[i]->moveRight();
                else if (input.getButton() == Button::attack1){
                    if(_players[i]->isTimetoAttack())
                    {
                    _players[i]->doAttack1(*_players[1]);
                    _players[i]->setLastAttackTime();
                    }
                    else
                    {
                        std::cout << "You can't attack1 now" << std::endl;
                    }
                    }
                else if (input.getButton() == Button::attack2)
                {
                    // Get the shared pointer to PlayerBleachShinigamiCapitaine
                    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[i]);

                    if (captainPlayer)
                    {
                        if(captainPlayer->isTimetoAttack())
                    {
                        captainPlayer->doAttack2(*_players[1]);
                        captainPlayer->setLastAttackTime();
                    }
                    else
                    {
                        std::cout << "You can't attack2 now" << std::endl;
                    }
                        
                    }
                    else
                    {
                        std::cerr << "Error: _players[" << i << "] is not of type PlayerBleachShinigamiCapitaine" << std::endl;
                    }
                }
                else if (input.getButton() == Button::attack3)
                    _players[i]->doAttack1(*_players[3]);
                else if (input.getButton() == Button::attack4)
                    _players[i]->doAttack1(*_players[4]);
                else if (input.getButton() == Button::pick)
                {
                    for (const auto& fruit : _fruits)
                    {

                            _players[i]->doPick(*fruit);
                    }
                }
                else if (input.getButton() == Button::fix){
                    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[i]);

                    if (captainPlayer)
                    {
                        captainPlayer->doFix2();
                    }
                    else
                    {
                        std::cerr << "Error: _players[" << i << "] is not of type PlayerBleachShinigamiCapitaine" << std::endl;
                    }
                 
                    _players[i]->doFix();
                }
            }
            else
            {
                
                // Pour les autres joueurs, déplacez-les constamment vers la droite
                _players[i]->moveRight();
                
            for(size_t j = 1; j < _players.size(); ++j) // Pour chaque joueur
            {
                _players[i]->setSpeed(XPMULTIPLIER);
                if (i != j && _players[j]->isCloseTo(*_players[i], DISTANCETREEHOLD) && _players[i]->canAttack()) // Si le joueur est proche d'un autre joueur et les deux peuvent attaquer
                {
                    
                    _players[i]->randomAttack(*_players[j]); // Attaque aléatoire
                    std::cout << "Player " << _players[i]->getFirstname() << " is close to Player " << _players[j]->getFirstname() << std::endl;
                }
            }


            }
        }
        //remets tous les attributs attack à false
        //_players[i]->setIsAttacking1(false);
    }
}


/*for (int i = 0; i < 10; ++i) {
        std::cout << "Iteration " << i + 1 << ": ";
        if (player.canAttackNow()) {
            std::cout << "Player can attack." << std::endl;
        } else {
            std::cout << "Player cannot attack." << std::endl;
        }

        // Modifier dynamiquement l'état d'attaque (par exemple, toutes les 3 itérations)
        if ((i + 1) % 3 == 0) {
            player.setCanAttack(!player.canAttackNow());
            std::cout << "Player attack state changed." << std::endl;
        }
    }
*/

