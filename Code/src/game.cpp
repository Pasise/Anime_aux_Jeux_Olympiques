// Game.cpp
#include "../header/game.hpp"
#include "../header/constant.hpp"


Game::Game() : _players(),_fruits(), _characterRenderer(&_players,&_fruits,BACKGROUND)  
{
    if (!_backgroundMusic.openFromFile(MUSIC)) // Chargez la musique de fond
        std::cerr << "Failed to load background music." << std::endl;


    std::shared_ptr<Player> player1 = std::make_shared<PlayerMedium>(LASTNAME_BYAKUYA, FIRSTNAME_BYAKUYA, XP_BYAKUYA,XP_MAX_BYAKUYA, SPEED_BYAKUYA, X_BYAKUYA, Y_BYAKUYA, DAMAGE_BYAKUYA, BYAKUYAASSOCIATION, DEATH_TEXTURE_PATH_BYAKUYA);
    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    std::shared_ptr<Player> player2 = std::make_shared<PlayerPlus>(LASTNAME_ICHIGO, FIRSTNAME_ICHIGO, XP_ICHIGO,XP_MAX_ICHIGO, SPEED_ICHIGO, X_ICHIGO, Y_ICHIGO, DAMAGE_ICHIGO, ICHIGOASSOCIATION, DEATH_TEXTURE_PATH_ICHIGO);
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    //Créer le joueur Shinsui KYORAKU de playersoin
    std::shared_ptr<Player> player3 = std::make_shared<PlayerSoin>(LASTNAME_SHINSUI, FIRSTNAME_SHINSUI, XP_SHINSUI,XP_MAX_SHINSUI, SPEED_SHINSUI, X_SHINSUI, Y_SHINSUI, DAMAGE_SHINSUI, SOIN_SHINSUI, SHINSUIASSOCIATION, DEATH_TEXTURE_PATH_SHINSUI);
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[2]->getFirstname() << std::endl;

    // Crée le joueur de l'équipage du Mugiwara Roronoa Zoro
    std::shared_ptr<Player> player4 = std::make_shared<PlayerPlus>(LASTNAME_ZORO, FIRSTNAME_ZORO, XP_ZORO,XP_MAX_ZORO, SPEED_ZORO, X_ZORO, Y_ZORO, DAMAGE_ZORO, ZOROASSOCIATION, DEATH_TEXTURE_PATH_ZORO);
    _players.push_back(player4);  // Ajoutez le joueur à la liste
    std::cout << "Player 4 in the list" << std::endl;
    std::cout << "Player 4 name : " << _players[3]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 

    // Crée le joueur de l'équipage du Mugiwara Monkey D. Luffy player medium
    std::shared_ptr<Player> player5 = std::make_shared<PlayerMedium>(LASTNAME_LUFFY, FIRSTNAME_LUFFY, XP_LUFFY,XP_MAX_LUFFY, SPEED_LUFFY, X_LUFFY, Y_LUFFY, DAMAGE_LUFFY, LUFFYASSOCIATION, DEATH_TEXTURE_PATH_LUFFY);
    _players.push_back(player5);  // Ajoutez le joueur à la liste
    std::cout << "Player 5 in the list" << std::endl;
    std::cout << "Player 5 name : " << _players[4]->getFirstname() << std::endl;

    // Crée le fruit du démon de Luffy
    std::shared_ptr<Fruit> fruit1 = std::make_shared<Fruit>(NAME_FRUITNORMAL,Y_FRUIT,ENERGY_FRUIT,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit1);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 1 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 


    // Crée un fruit normal que tout le monde peut manger
    std::shared_ptr<Fruit> fruit2 = std::make_shared<Fruit>(NAME_FRUITNORMAL,Y_FRUITNORMAL,ENERGY_FRUITNORMAL,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit2);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 2 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);


    //Cree le masque hollow de Ichigo
    std::shared_ptr<Fruit> fruit3 = std::make_shared<Fruit>(NAME_FRUITNORMAL,Y_HOLLOW,ENERGY_HOLLOW,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit3);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 3 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    chooseScreen.push_back("../Sprite/Choose_Byakuya.PNG");
    chooseScreen.push_back("../Sprite/Choose_Ichigo.PNG");
    chooseScreen.push_back("../Sprite/Choose_Kyoraku.PNG");
    chooseScreen.push_back("../Sprite/Choose_Zoro.PNG");
    chooseScreen.push_back("../Sprite/Choose_Luffy.PNG");



}

void Game::playBackgroundMusic() {
    _backgroundMusic.play();
    _backgroundMusic.setLoop(true);
}

void Game::intro(sf::RenderWindow& window) {
    

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

void Game::choose(sf::RenderWindow& window, size_t &i) {
    sf::Event event;
    std::vector<std::string>::iterator currentImage = chooseScreen.begin();
    sf::Texture chooseTexture;
    
    // Load the initial image
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
                // Use UserInput to handle key events
                UserInput input(event,window);
                
                if (input.getButton() == Button::right) {
                    // Move to the next image in the vector
                    currentImage++;
                    i++;
                    if (currentImage == chooseScreen.end()) {
                        // Wrap around to the beginning if we are at the end
                        currentImage = chooseScreen.begin();
                        i = 0;
                    }
                } else if (input.getButton() == left) {
                    // Move to the previous image in the vector
                    if (currentImage == chooseScreen.begin()) {
                        // Wrap around to the end if we are at the beginning
                        currentImage = chooseScreen.end();
                        i = chooseScreen.size();
                    }
                    currentImage--;
                    i--;
                } else if (input.getButton() == confirm){
                    std::string newFileName = *currentImage;
                    newFileName.insert(newFileName.find_last_of('.'), "1");

                    // Load and display the new image
                    sf::Texture newTexture;
                    if (newTexture.loadFromFile(newFileName)) {
                        sf::Sprite newSprite(newTexture);
                        window.draw(newSprite);
                        window.display();
                        
                        // Pause for a short duration (0.5 seconds)
                        sf::sleep(sf::seconds(0.5));
                        
                        return;
                    } else {
                        std::cerr << "Failed to load " << newFileName << std::endl;
                        return;
                    }
                }

                // Load and display the current image
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
                // Check if the mouse is in the specified area
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (mousePosition.x >= 1500 && mousePosition.x <= 1855 &&
                    mousePosition.y >= 940 && mousePosition.y <= 1025) {
                    // Build the new file name with "1.PNG" added
                    std::string newFileName = *currentImage;
                    newFileName.insert(newFileName.find_last_of('.'), "1");

                    // Load and display the new image
                    sf::Texture newTexture;
                    if (newTexture.loadFromFile(newFileName)) {
                        sf::Sprite newSprite(newTexture);
                        window.draw(newSprite);
                        window.display();
                        
                        // Pause for a short duration (0.5 seconds)
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


void Game::run(sf::RenderWindow& window, size_t i) {
    applyPlayerChosen(i);
    bool exitRun = false;
    size_t winner;
    while (window.isOpen() && !exitRun) {
        for (size_t i = 0; i < _players.size(); i++) {
            if (_players[i]->getX() > 1700) {
                exitRun = true;  // Sortir de la boucle run si un joueur a sa coordonnée x > 1850
                winner = i;
                break;
            } else if (_players[0]->getXp() <= 0) {
                exitRun = true;  // Sortir de la boucle run si un joueur a sa vie <= 0
                winner = -1;
                break;
            }
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            _input.manageInput(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateStatePlayerUser(_input);
        updateStateBots();

        window.clear();
        _characterRenderer.setTexture(BACKGROUND);
        _characterRenderer.render(window);
        _characterRenderer.renderFruits(window);
        _characterRenderer.renderHealthBars(window);
        window.display();
    }
    if (winner == 0) return win(window);
    else return lose(window);
}

void Game::win(sf::RenderWindow& window) {
    sf::Texture winTexture;
    if (winTexture.loadFromFile("../Sprite/win.png")) {
        sf::Sprite winSprite(winTexture);
        window.draw(winSprite);
        window.display();
    } else {
        std::cerr << "Failed to load win image." << std::endl;
        return;
    }

    // Charger la musique
    sf::Music winMusic;
    if (winMusic.openFromFile(MUSIC)) {
        winMusic.play();
    } else {
        std::cerr << "Failed to load win music." << std::endl;
        return;
    }

    // Attendre 7 secondes
    sf::sleep(sf::seconds(7));

    // Retourner de la fonction
}

void Game::lose(sf::RenderWindow& window) {
    sf::Texture loseTexture;
    if (loseTexture.loadFromFile("../Sprite/lose.png")) {
        sf::Sprite loseSprite(loseTexture);
        window.draw(loseSprite);
        window.display();
    } else {
        std::cerr << "Failed to load lose image." << std::endl;
        return;
    }

    // Charger la musique
    sf::Music loseMusic;
    if (loseMusic.openFromFile(MUSIC)) {
        loseMusic.play();
    } else {
        std::cerr << "Failed to load lose music." << std::endl;
        return;
    }

    // Attendre 7 secondes
    sf::sleep(sf::seconds(7));

    // Retourner de la fonction
}

//la méthode action prend en entrer un UserInput et effectue l'action correspondante : pour left on décrémente la position x et poour right on l'incrémente

void Game::updateStatePlayerUser(const UserInput& input) {
    if (_players.empty() || !_players[0])
        return;

    _players[0]->setSpeed(XPMULTIPLIER);
    _players[0]->getRandomNumberForCanAttack();

    if (input.getButton() == Button::left)
        _players[0]->moveLeft();
    else if (input.getButton() == Button::right){
        _players[0]->moveRight();
        std::cout << "Player " << _players[0]->getFirstname() << " is moving right" << std::endl;}
    else if (input.getButton() == Button::attack1) {
        if (_players[0]->isTimetoAttack() && (_players[0]->isSameline(*_players[1]) && _players[0]->isBehind(*_players[1]))) {
            _players[0]->doAttack1(*_players[1]);
            _players[0]->setLastAttackTime();
        } else {
            std::cout << "You can't attack1 now" << std::endl;
        }
    } else if (input.getButton() == Button::attack2) {
        std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[0]);

        if (captainPlayer) {
            if (captainPlayer->isTimetoAttack()) {
                captainPlayer->doAttack2(*_players[1]);
                captainPlayer->setLastAttackTime();
            } else {
                std::cout << "You can't attack2 now" << std::endl;
            }
        } else {
            std::cerr << "Error: _players[0] is not of type PlayerPlus" << std::endl;
        }
    } else if (input.getButton() == Button::pick) {
        for (const auto& fruit : _fruits) {
            _players[0]->doPick(*fruit);
        }
    } else if (input.getButton() == Button::heal) {
        std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(_players[0]);
        if (soinPlayer){
        soinPlayer->doHeal();
        std::cout << "Player " << _players[0]->getFirstname() << " is healing" << std::endl;
        } else {
            std::cerr << "Error: _players[0] is not of type PlayerSoin" << std::endl;
        }
    } else if (input.getButton() == Button::fix) {
        std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[0]);
        std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(_players[0]);
        std::shared_ptr<PlayerMedium> mediumPlayer = std::dynamic_pointer_cast<PlayerMedium>(_players[0]);

        if (captainPlayer) {
            captainPlayer->doFix2();
        } else {
            std::cerr << "Error: _players[0] is not of type PlayerPlus" << std::endl;
        }
        if (soinPlayer) {
            soinPlayer->doFix3();
        } else {
            std::cerr << "Error: _players[0] is not of type PlayerSoin" << std::endl;
        }
        if (mediumPlayer) {
            mediumPlayer->doFix();
        } else {
            std::cerr << "Error: _players[0] is not of type PlayerMedium" << std::endl;
        }
        _players[0]->doFix();
    }
}

void Game::updateStateBots() {
    for (size_t i = 1; i < _players.size(); ++i) {
        if (_players[i]) {
            
            std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[i]);
            _players[i]->doFix();
            if (captainPlayer) captainPlayer->doFix2();

            _players[i]->setSpeed(XPMULTIPLIER);

            for (size_t j = 0; j < _players.size(); ++j) {
                if (i != j && _players[j]->isCloseTo(*_players[i], DISTANCETREEHOLD) && _players[i]->canAttack() && _players[i]->isSameline(*_players[j]) && _players[i]->isBehind(*_players[j])) {
                    _players[i]->randomAttack(*_players[j]);
                    std::cout << "Player " << _players[i]->getFirstname() << " is close to Player " << _players[j]->getFirstname() << std::endl;

                    // Arrêter le mouvement après l'attaque
                    _players[i]->setSpeed(0);
                    break;  // Sortir de la boucle interne après avoir attaqué
                }
            }

            // Si le joueur n'attaque pas, il peut continuer à se déplacer
            if (!_players[i]->isAttacking1() && (!captainPlayer || !captainPlayer->isAttacking2())) {
                _players[i]->moveRight();
            }
        }
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

