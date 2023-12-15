#include "../header/game.hpp"

Game::Game() : _input(Button::none)
{
    _players.push_back(Player("Player1"));
    _players.push_back(Player("Player2"));
    _players.push_back(Player("Player3"));
    _players.push_back(Player("Player4"));
}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            _input.manageInput(event, window);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        action(_input);
        window.clear();
        window.draw(shape);
        window.display();
    }
}

//la méthode action prend en entrer un UserInput et effectue l'action correspondante : pour left on décrémente la position x et poour right on l'incrémente

void Game::action(UserInput input)
{
    if (input.getButton() == Button::left)
    {
        for (auto &player : _players)
        {
            player.moveLeft();
        }
    }
    else if (input.getButton() == Button::right)
    {
        for (auto &player : _players)
        {
            player.moveRight();
        }
    }
    else if (input.getButton() == Button::attack1)
    {
        for (auto &player : _players)
        {
            player.attack1();
        }
    }
    else if (input.getButton() == Button::attack2)
    {
        for (auto &player : _players)
        {
            player.attack2();
        }
    }
    else if (input.getButton() == Button::attack3)
    {
        for (auto &player : _players)
        {
            player.attack3();
        }
    }
    else if (input.getButton() == Button::attack4)
    {
        for (auto &player : _players)
        {
            player.attack4();
        }
    }
    else if (input.getButton() == Button::pick)
    {
        for (auto &player : _players)
        {
            player.pick();
        }
    }
    else
    {
        for (auto &player : _players)
        {
            player.idle();
        }
    }
}