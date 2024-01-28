// Game.cpp
#include "../header/game.hpp"
#include "../header/constant.hpp"


Game::Game() : _players(),_fruits(), _characterRenderer(&_players,&_fruits,BACKGROUND)  
{
    if (!_backgroundMusic.openFromFile(MUSIC)) // Chargez la musique de fond
        std::cerr << "Failed to load background music." << std::endl;


    std::shared_ptr<Player> player1 = std::make_shared<PlayerMedium>(LASTNAME_BYAKUYA, FIRSTNAME_BYAKUYA, XP_BYAKUYA,XP_MAX_BYAKUYA,XP_MULTIPLIER_BYAKUYA, SPEED_BYAKUYA, X_BYAKUYA, Y_BYAKUYA, DAMAGE_BYAKUYA, BYAKUYAASSOCIATION, DEATH_TEXTURE_PATH_BYAKUYA);
    _players.push_back(player1);  // Ajoutez le joueur à la liste
    std::cout << "Player 1 in the list" << std::endl;
    std::cout << "Player 1 name : " << _players[0]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    std::shared_ptr<Player> player2 = std::make_shared<PlayerPlus>(LASTNAME_ICHIGO, FIRSTNAME_ICHIGO, XP_ICHIGO,XP_MAX_ICHIGO,XP_MULTIPLIER_ICHIGO, SPEED_ICHIGO, X_ICHIGO, Y_ICHIGO, DAMAGE_ICHIGO, ICHIGOASSOCIATION, DEATH_TEXTURE_PATH_ICHIGO);
    _players.push_back(player2);  // Ajoutez le joueur à la liste
    std::cout << "Player 2 in the list" << std::endl;
    std::cout << "Player 2 name : " << _players[1]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    std::shared_ptr<Player> player3 = std::make_shared<PlayerSoin>(LASTNAME_SHINSUI, FIRSTNAME_SHINSUI, XP_SHINSUI,XP_MAX_SHINSUI,XP_MULTIPLIER_SHINSUI, SPEED_SHINSUI, X_SHINSUI, Y_SHINSUI, DAMAGE_SHINSUI, SOIN_SHINSUI, SHINSUIASSOCIATION, DEATH_TEXTURE_PATH_SHINSUI);
    _players.push_back(player3);  // Ajoutez le joueur à la liste
    std::cout << "Player 3 in the list" << std::endl;
    std::cout << "Player 3 name : " << _players[2]->getFirstname() << std::endl;

    std::shared_ptr<Player> player4 = std::make_shared<PlayerPlus>(LASTNAME_ZORO, FIRSTNAME_ZORO, XP_ZORO,XP_MAX_ZORO,XP_MULTIPLIER_ZORO, SPEED_ZORO, X_ZORO, Y_ZORO, DAMAGE_ZORO, ZOROASSOCIATION, DEATH_TEXTURE_PATH_ZORO);
    _players.push_back(player4);  // Ajoutez le joueur à la liste
    std::cout << "Player 4 in the list" << std::endl;
    std::cout << "Player 4 name : " << _players[3]->getFirstname() << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 

    std::shared_ptr<Player> player5 = std::make_shared<PlayerMedium>(LASTNAME_LUFFY, FIRSTNAME_LUFFY, XP_LUFFY,XP_MAX_LUFFY,XP_MULTIPLIER_LUFFY, SPEED_LUFFY, X_LUFFY, Y_LUFFY, DAMAGE_LUFFY, LUFFYASSOCIATION, DEATH_TEXTURE_PATH_LUFFY);
    _players.push_back(player5);  // Ajoutez le joueur à la liste
    std::cout << "Player 5 in the list" << std::endl;
    std::cout << "Player 5 name : " << _players[4]->getFirstname() << std::endl;

    std::shared_ptr<Fruit> fruit1 = std::make_shared<Fruit>(NAME_FRUIT,ENERGY_FRUIT,TEXTUREPATH_FRUIT);
    _fruits.push_back(fruit1);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 1 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND); 

    std::shared_ptr<Fruit> fruit2 = std::make_shared<Fruit>(NAME_FRUITNORMAL,ENERGY_FRUITNORMAL,TEXTUREPATH_FRUITNORMAL);
    _fruits.push_back(fruit2);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 2 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    std::shared_ptr<Fruit> fruit3 = std::make_shared<Fruit>(NAME_HOLLOW,ENERGY_HOLLOW,TEXTUREPATH_HOLLOW);
    _fruits.push_back(fruit3);  // Ajoutez le fruit à la liste
    std::cout << "Fruit 3 in the list" << std::endl;
    _characterRenderer = CharacterRenderer(&_players,&_fruits,BACKGROUND);

    chooseScreen.push_back("../Sprite/Choose_Byakuya.PNG");
    chooseScreen.push_back("../Sprite/Choose_Ichigo.PNG");
    chooseScreen.push_back("../Sprite/Choose_Kyoraku.PNG");
    chooseScreen.push_back("../Sprite/Choose_Zoro.PNG");
    chooseScreen.push_back("../Sprite/Choose_Luffy.PNG");

    if (!_healMusic.openFromFile(HEALMUSIC)) {
        std::cerr << "Failed to load heal music." << std::endl;
    }
    if (!_attackMusic.openFromFile(ATTACKMUSIC)) {
        std::cerr << "Failed to load attack music." << std::endl;
    }
    if (!_pickMusic.openFromFile(PICKMUSIC)) {
        std::cerr << "Failed to load pick music." << std::endl;
    }
    if (!_atacckedMusic.openFromFile(ATTACKEDMUSIC)) {
        std::cerr << "Failed to load attacked music." << std::endl;
    }
}

void Game::playBackgroundMusic() {
    _backgroundMusic.setVolume(20);
    _backgroundMusic.play();
    _backgroundMusic.setLoop(true);
}

void Game::stopBackgroundMusic() {
    for (int i = 20; i >= 0; i-=5) {
        _backgroundMusic.setVolume(i);
        sf::sleep(sf::milliseconds(80));
    }
    _backgroundMusic.stop();
}

void Game::playHealSound() {
    _healMusic.setVolume(100);
    _healMusic.stop(); 
    _healMusic.setPlayingOffset(sf::Time::Zero); 
    _healMusic.play();
}


void Game::playAttackSound() {
    _attackMusic.setVolume(100);
    _attackMusic.stop();
    _attackMusic.setPlayingOffset(sf::Time::Zero);
    _attackMusic.play();
}


void Game::playPickSound() {
    _pickMusic.setVolume(100);
    _pickMusic.stop();
    _pickMusic.setPlayingOffset(sf::Time::Zero);
    _pickMusic.play();
}

void Game::playAttackedSound() {
    _atacckedMusic.setVolume(40);
    _atacckedMusic.stop();
    _atacckedMusic.setPlayingOffset(sf::Time::Zero);
    _atacckedMusic.play();
}

void Game::loadAndDrawTexture(sf::RenderWindow& window, const std::string& filePath) {
    sf::Texture texture;
    if (texture.loadFromFile(filePath)) {
        sf::Sprite sprite(texture);
        window.draw(sprite);
        window.display();
    } else {
        std::cerr << "Failed to load image from " << filePath << std::endl;
    }
}


bool Game::waitForMouseClickInRegion(sf::RenderWindow& window, int minX, int maxX, int minY, int maxY) {
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed &&
                       event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (mousePosition.x >= minX && mousePosition.x <= maxX &&
                    mousePosition.y >= minY && mousePosition.y <= maxY) {
                    return true;
                }
            }
        }
    }
    return false;
}


void Game::displayIntroScreen(sf::RenderWindow& window) {
    loadAndDrawTexture(window, "../Sprite/home_screen.PNG");
}


void Game::displayStartScreen(sf::RenderWindow& window) {
    loadAndDrawTexture(window, "../Sprite/home_screen_start.PNG");
}


void Game::displayExitScreen(sf::RenderWindow& window) {
    loadAndDrawTexture(window, "../Sprite/home_screen_exit.PNG");
}


void Game::handleIntroLogic(sf::RenderWindow& window) {
    if (waitForMouseClickInRegion(window, 690, 1195, 770, 900)) {
        displayStartScreen(window);
        sf::sleep(sf::seconds(0.5));
    } else if (waitForMouseClickInRegion(window, 820, 1055, 930, 1040)) {
        displayExitScreen(window);
        sf::sleep(sf::seconds(0.5));
        window.close();
    }
}


void Game::intro(sf::RenderWindow& window) {
    displayIntroScreen(window);
    handleIntroLogic(window);
}


void Game::moveImageIterator(std::vector<std::string>::iterator& currentImage, size_t& i, int direction) {
    if (direction > 0) {
        // Déplacer vers l'image suivante dans le vecteur
        currentImage++;
        i++;
        if (currentImage == chooseScreen.end()) {
            // Revenir au début si nous sommes à la fin
            currentImage = chooseScreen.begin();
            i = 0;
        }
    } else if (direction < 0) {
        // Déplacer vers l'image précédente dans le vecteur
        if (currentImage == chooseScreen.begin()) {
            // Revenir à la fin si nous sommes au début
            currentImage = chooseScreen.end();
            i = chooseScreen.size();
        }
        currentImage--;
        i--;
    }
}


void Game::choose(sf::RenderWindow& window, size_t& i) {
    sf::Event event;
    std::vector<std::string>::iterator currentImage = chooseScreen.begin();
    sf::Texture chooseTexture;
    
    // Charger et afficher l'image initiale
    loadAndDrawTexture(window, *currentImage);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                // Utiliser UserInput pour gérer les événements de touche
                UserInput input(event, window);
                
                if (input.getButton() == Button::right || input.getButton() == left) {
                    moveImageIterator(currentImage, i, (input.getButton() == Button::right) ? 1 : -1);
                } else if (input.getButton() == confirm) {
                    std::string newFileName = *currentImage;
                    newFileName.insert(newFileName.find_last_of('.'), "1");
                    loadAndDrawTexture(window, newFileName);
                    sf::sleep(sf::seconds(0.5));
                    return;
                }

                loadAndDrawTexture(window, *currentImage);
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (waitForMouseClickInRegion(window, 1500, 1855, 940, 1025)) {
                    std::string newFileName = *currentImage;
                    newFileName.insert(newFileName.find_last_of('.'), "1");
                    loadAndDrawTexture(window, newFileName);
                    sf::sleep(sf::seconds(0.5));
                    return;
                }
            }
        }
    }
}


void Game::setPlayerPositionAndStatus(size_t index, float yPos, bool isAlive) {
    _players[index]->setY(yPos);
    _players[index]->setIsAlive(isAlive);
}

void Game::checkExitConditions(bool& exitRun, size_t& winner) {
    for (size_t i = 0; i < _players.size(); i++) {
        if (_players[i]->getX() > 1700) {
            exitRun = true;
            winner = i;
            break;
        } else if (!_players[0]->isAlive()) {
            exitRun = true;
            winner = -1;
            break;
        }
    }
}

void Game::updateStates() {
    updateStatePlayerUser(_input);
    updateStateBots();
}

void Game::render(sf::RenderWindow& window, std::shared_ptr<PlayerPlus> captainPlayer) {
    window.clear();
    _characterRenderer.setTexture(BACKGROUND);
    if (captainPlayer)
        _characterRenderer.render2(window);
    else
        _characterRenderer.render(window);
    _characterRenderer.renderHealthBars(window);
}

void Game::handleWinLose(size_t winner, sf::RenderWindow& window) {
    if (winner == 0)
        win(window);
    else
        lose(window);
}

void Game::run(sf::RenderWindow& window, size_t i) {
    applyPlayerChosen(i);
    bool exitRun = false;
    size_t winner = -1;
    
    std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[0]);
    
    if (captainPlayer) {
        setPlayerPositionAndStatus(i, -1000, false);
        setPlayerPositionAndStatus(i + 1, 740, true);
    } else {
        setPlayerPositionAndStatus(1, -1000, false);
    }

    while (window.isOpen() && !exitRun) {
        checkExitConditions(exitRun, winner);

        sf::Event event;
        while (window.pollEvent(event)) {
            _input.manageInput(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateStates();
        render(window, captainPlayer);

        window.display();
    }

    handleWinLose(winner, window);
}


void Game::win(sf::RenderWindow& window) {
    stopBackgroundMusic();
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
    if (winMusic.openFromFile(WINMUSIC)) {
        winMusic.setVolume(65);
        winMusic.play();
    } else {
        std::cerr << "Failed to load win music." << std::endl;
        return;
    }

    // Attendre 7 secondes
    sf::sleep(sf::seconds(4));

    // Retourner de la fonction
}

void Game::lose(sf::RenderWindow& window) {
    sf::Texture loseTexture;
        stopBackgroundMusic();
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
    if (loseMusic.openFromFile(LOSEMUSIC)) {
        loseMusic.setVolume(65);
        loseMusic.play();
    } else {
        std::cerr << "Failed to load lose music." << std::endl;
        return;
    }

    // Attendre 7 secondes
    sf::sleep(sf::seconds(4));

    // Retourner de la fonction
}

//la méthode action prend en entrer un UserInput et effectue l'action correspondante : pour left on décrémente la position x et poour right on l'incrémente

void Game::updateStatePlayerUser(const UserInput& input) {
    if (_players.empty() || !_players[0])
        return;

    _players[0]->setSpeed();
    _players[0]->getRandomNumberForCanAttack();

    switch (input.getButton()) {
        case Button::left: _players[0]->moveLeft(); break;
        case Button::right: _players[0]->moveRight(); break;
        case Button::up: _players[0]->moveUp(); break;
        case Button::down: _players[0]->moveDown(); break;
        case Button::attack1: handleAttack(1); break;
        case Button::attack2: handleAttack(2); break;
        case Button::pick: handlePick(); break;
        case Button::heal: handleHeal(); break;
        case Button::fix: _players[0]->doFix(); break;
        default: break;
    }
}

void Game::handleAttack(int attackType) {
    size_t attackerIndex = 0;
    if (attackType == 2) {
        std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[0]);
        if (!captainPlayer) {
            std::cerr << "Error: _players[0] is not of type PlayerPlus" << std::endl;
            return;
        }
        attackerIndex = captainPlayerAttack(captainPlayer);
    } else {
        attackerIndex = basicAttack();
    }

    if (attackerIndex != static_cast<size_t>(-1)) {
        playAttackSound();
        _players[attackerIndex]->setLastAttackTime();
    }
}

size_t Game::basicAttack() {
    for (size_t i = 0; i < _players.size(); ++i) {
        if (i != 0 && _players[i] && _players[i]->isAlive() &&
            _players[0]->isTimetoAttack() && (_players[0]->isCloseTo(*_players[i],DISTANCETREEHOLD) && _players[0]->isBehind(*_players[i]))) {
            _players[0]->doAttack1(*_players[i]);
            _players[0]->setLastAttackTime();
            return i;
        }
    }
    std::cout << "You can't attack1 now" << std::endl;
    return static_cast<size_t>(-1);
}

size_t Game::captainPlayerAttack(const std::shared_ptr<PlayerPlus>& captainPlayer) {
    for (size_t i = 0; i < _players.size(); ++i) {
        if (i != 0 && captainPlayer->isTimetoAttack() &&
            (captainPlayer->isCloseTo(*_players[i],DISTANCETREEHOLD) && captainPlayer->isBehind(*_players[i]))) {
            captainPlayer->doAttack2(*_players[i]);
            captainPlayer->setLastAttackTime();
            return i;
        }
    }
    std::cout << "You can't attack2 now" << std::endl;
    return static_cast<size_t>(-1);
}

void Game::handlePick() {
        for (const auto& fruit : _fruits) {
            _players[0]->doPick(*fruit);
            if(_players[0]->isPicking()) {
                playPickSound();
                _players[0]->setLastPickTime();
        }
    }
}

void Game::handleHeal() {
    std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(_players[0]);
    if (soinPlayer && soinPlayer->isTimetoHeal()){
        soinPlayer->doHeal();
        playHealSound();
        soinPlayer->setLastHealTime();
    }
}


void Game::updateStateBots() {
    for (size_t i = 1; i < _players.size(); ++i) {
        if (_players[i] && _players[i]->isAlive()) {
            
            std::shared_ptr<PlayerPlus> captainPlayer = std::dynamic_pointer_cast<PlayerPlus>(_players[i]);
            std::shared_ptr<PlayerSoin> soinPlayer = std::dynamic_pointer_cast<PlayerSoin>(_players[i]);           
            _players[i]->doFix();

            _players[i]->setSpeed();

            for (size_t j = 0; j < _players.size(); ++j) {
                if (i != j &&  _players[i]->isTimetoAttack() && _players[i]->isCloseTo(*_players[j], DISTANCETREEHOLD) && _players[i]->canAttack() && _players[i]->isCloseTo(*_players[j],DISTANCETREEHOLD) && _players[i]->isBehind(*_players[j])) {
                    _players[i]->randomAttack(*_players[j]);
                    if (j == 0) playAttackedSound();
                    std::cout << "Player " << _players[i]->getFirstname() << " is close to Player " << _players[j]->getFirstname() << std::endl;

                    // Arrêter le mouvement après l'attaque
                    _players[i]->setSpeed(0);
                    break;  // Sortir de la boucle interne après avoir attaqué
                }
                if (soinPlayer && soinPlayer->getXp()<=soinPlayer->getXpMax()/2 && soinPlayer->isTimetoHeal()) {
                    soinPlayer->doHeal();
                    soinPlayer->setLastHealTime();
                }
            }

            // Si le joueur n'attaque pas, il peut continuer à se déplacer
            if (!_players[i]->isAttacking1() && (!captainPlayer || !captainPlayer->isAttacking2())) {
                _players[i]->moveRight();
            }
        } else {
            std::cout << "Player " << _players[i]->getFirstname() << "is dead" << std::endl;
        }
    }
}



