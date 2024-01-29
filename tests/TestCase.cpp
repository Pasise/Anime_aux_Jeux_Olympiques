#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Code/header/playermedium.hpp" 
#include "../Code/header/playerplus.hpp"
#include "../Code/header/playersoin.hpp"
#include "../Code/header/characterrenderer.hpp"


TEST_CASE("Test des fonctions de la classe PlayerMedium") {
    SUBCASE("Test du constructeur et des fonctions d'initialisation") {
        std::string lastname = "Gojo";
        std::string firstname = "Satoru";
        float Xp = 100.0f;
        float Xp_max = 150.0f;
        float Xp_multiplier = 1.5f;

        float x = 0.0f;
        float y = 0.0f;
        float damage = 20.0f;
        std::map<std::string, int> textureAssociations = {{"Gojo.png", 2}, {"Gojo2.png", 3}};
        std::string deathTexturePath = "death_texture.png";

        PlayerMedium playerMedium(lastname, firstname, Xp, Xp_max, Xp_multiplier, x, y, damage, textureAssociations, deathTexturePath);

        CHECK(playerMedium.getLastname() == lastname);
        CHECK(playerMedium.getFirstname() == firstname);
        CHECK(playerMedium.getXp() == Xp);
        CHECK(playerMedium.getXpMax() == Xp_max);
        CHECK(playerMedium.getX() == x);
        CHECK(playerMedium.getY() == y);
        CHECK(playerMedium.getDamage() == damage);
        CHECK(playerMedium.getTextureAssociations() == textureAssociations);
        CHECK(playerMedium.getDeathTexturePath() == deathTexturePath);
    }

    SUBCASE("Test de la fonction doAttack1") {
        PlayerMedium attacker("Trafalgar", "Law", 100.0f, 150.0f, 1.5f, 0.0f, 0.0f, 20.0f, {{"Trafalgar.png", 2}}, "Trafalgar2.png");
        PlayerMedium target("Don Quijote", "Doflamingo", 80.0f, 120.0f, 1.2f, 0.0f, 0.0f, 15.0f, {{"Doflamingo.png", 3}}, "Doflamingo2.png");

        float initialXp = target.getXp();
        attacker.doAttack1(target);

        CHECK(target.getXp() == doctest::Approx(initialXp - attacker.getDamage()));
        CHECK(target.isAlive() == (target.getXp() > 0));
    }

    SUBCASE("Test pour la surcharge de l'opérateur =") {
       
        PlayerMedium playerMediumOriginal("Original", "Player", 100.0f, 150.0f, 1.5, 0.0f, 0.0f, 20.0f, {{"OriginalPlayer.png", 1}}, "OriginalPlayer2.png");
        PlayerMedium playerMediumCopy("Copy", "Player", 50.0f, 75.0f, 1.0f, 0.0f, 0.0f, 10.0f, {{"CopyPlayer.png", 1}}, "CopyPlayer2.png");
        
        playerMediumCopy = playerMediumOriginal; // Utilisez l'opérateur d'affectation

        CHECK(playerMediumCopy.getLastname() == playerMediumOriginal.getLastname());
        CHECK(playerMediumCopy.getFirstname() == playerMediumOriginal.getFirstname());
        CHECK(playerMediumCopy.getXp() == playerMediumOriginal.getXp());
        CHECK(playerMediumCopy.getXpMax() == playerMediumOriginal.getXpMax());
        CHECK(playerMediumCopy.getX() == playerMediumOriginal.getX());
        CHECK(playerMediumCopy.getY() == playerMediumOriginal.getY());
        CHECK(playerMediumCopy.getDamage() == playerMediumOriginal.getDamage());
        CHECK(playerMediumCopy.getTextureAssociations() == playerMediumOriginal.getTextureAssociations());
        CHECK(playerMediumCopy.getDeathTexturePath() == playerMediumOriginal.getDeathTexturePath());
    }
    /*

    SUBCASE("Test de la surchage en changeant l'état de _isAlive à true") {
        PlayerMedium playerMedium("Trafalgar", "Law", 100.0f, 150.0f, 1.5f, 0.0f, 0.0f, 20.0f, {{"Trafalgar.png", 2}}, "Trafalgar2.png");
        playerMedium = true;

        CHECK(playerMedium.isAlive() == true);
    }

    SUBCASE("Test de la surchage en changeant l'état de _isAlive à false") {
        PlayerMedium playerMedium("Trafalgar", "Law", 100.0f, 150.0f, 1.5f, 0.0f, 0.0f, 20.0f, {{"Trafalgar.png", 2}}, "Trafalgar2.png");
        playerMedium = false;

        CHECK(playerMedium.isAlive() == false);
    }

*/
}


TEST_CASE("Test des fonctions de la classe PlayerPlus") {
    SUBCASE("Test du constructeur et des fonctions d'initialisation") {
        std::string lastname = "Fushiguro";
        std::string firstname = "Megumi";
        float Xp = 200.0f;
        float Xp_max = 250.0f;
        float Xp_multiplier = 2.5f;
        float x = 4.0f;
        float y = 0.0f;
        float damage = 25.0f;
        std::map<std::string, int> textureAssociations = {{"Megumi.png", 2}, {"Megumi2.png", 3}};
        std::string deathTexturePath = "death_texture.png";

        PlayerPlus playerPlus(lastname, firstname, Xp, Xp_max, Xp_multiplier, x, y, damage, textureAssociations, deathTexturePath);
        CHECK(playerPlus.getLastname() == lastname);
        CHECK(playerPlus.getFirstname() == firstname);
        CHECK(playerPlus.getXp() == Xp);
        CHECK(playerPlus.getXpMax() == Xp_max);
        CHECK(playerPlus.getX() == x);
        CHECK(playerPlus.getY() == y);
        CHECK(playerPlus.getDamage() == damage);
        CHECK(playerPlus.getTextureAssociations() == textureAssociations);
        CHECK(playerPlus.getDeathTexturePath() == deathTexturePath);
    }

    SUBCASE("Test de la fonction doAttack1") {
        PlayerPlus attacker("Shelby", "Thomas", 100.0f, 150.0f, 1.5f, 0.0f, 0.0f, 20.0f, {{"Thomas.png", 2}}, "Thomas2.png");
        PlayerPlus target("Annelise", "Keating", 80.0f, 120.0f, 1.2f,0.0f, 0.0f, 15.0f, {{"Annelise.png", 3}}, "death_texture.png");

        float initialXp = target.getXp();
        attacker.doAttack1(target);

        CHECK(target.getXp() == doctest::Approx(initialXp - attacker.getDamage()));
        CHECK(target.isAlive() == (target.getXp() > 0));
        CHECK(attacker.isAttacking1() == true);
        CHECK(attacker.isAttacking2() == false);
    }

    SUBCASE("Test de la fonction doAttack2") {
    PlayerPlus attacker("Thomas", "Sankara", 300.0f, 350.0f, 1.5f, 0.0f, 0.0f, 20.0f, {{"Thomas.png", 2}}, "death_texture.png");
    PlayerPlus target("Petit", "Pompier", 80.0f, 120.0f, 1.2f, 0.0f, 0.0f, 15.0f, {{"Petit.png", 3}}, "death_texture.png");

    attacker.doAttack2(target);

    
    CHECK(target.isAlive() == (target.getXp() > 0));
    CHECK(attacker.isAttacking1() == false);
    CHECK(attacker.isAttacking2() == true);
}

}

TEST_CASE("PlayerSoin - Test de la fonction doHeal") {
    PlayerSoin healer("Jorge", "Blanco", 100.0f, 150.0f, 1.5f, 0.0f, 0.0f, 20.0f, 10.0f, {{"texture1.png", 2}}, "death_texture.png");

    healer.doHeal();

    CHECK(healer.getXp() <= healer.getXpMax());
    CHECK(healer.isHealing() == true);
    CHECK(healer.isAttacking1() == false);
    CHECK(healer.isPicking() == false);
}



TEST_CASE("Creation of Fruit") {
    

    // Vérifiez que le nom, l'énergie, la texture et le statut sont corrects
    SUBCASE("Création de fruit"){
    Fruit fruit("Gomu Gomu fruit", 10.0f, "gomu_texture.png");
    CHECK(fruit.getName() == "Gomu Gomu fruit");
    CHECK(fruit.getEnergy() == 10.0f);
    CHECK(fruit.getTexturePath() == "gomu_texture.png");
    CHECK(fruit.isAlive() == true);
    }

    SUBCASE("Test sur les coordonnées y") {
    Fruit fruit1("Gomu Gomu fruit", 10.0f, "gomu_texture.png");
    Fruit fruit2("Masque du Hollow", 15.0f, "hollow_texture.png");
    Fruit fruit3("Fruit Normal", 8.0f, "normal_texture.png");

    // Vérifiez que les coordonnées y générées sont valides en fonction du nom du fruit
    CHECK((fruit1.getY() == 775.0f || fruit1.getY() == 627.0f));
    CHECK((fruit2.getY() == 725.0f || fruit2.getY() == 580.0f));
    CHECK((fruit3.getY() == 830.0f || fruit3.getY() == 680.0f));


}

}


TEST_CASE("UserInput - Test de la gestion des inputs") {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");
    UserInput userInput;

    SUBCASE("Test de la touche Q") {
        sf::Event event;
        event.type = sf::Event::KeyPressed;
        event.key.code = sf::Keyboard::Q;

        userInput.manageInput(event, window);
        CHECK(userInput.getButton() == Button::left);

        event.type = sf::Event::KeyReleased;
        userInput.manageInput(event, window);
        CHECK(userInput.getButton() == Button::fix);
    }

    SUBCASE("Test de la touche D") {
        sf::Event event;
        event.type = sf::Event::KeyPressed;
        event.key.code = sf::Keyboard::D;

        userInput.manageInput(event, window);
        CHECK(userInput.getButton() == Button::right);

        event.type = sf::Event::KeyReleased;
        userInput.manageInput(event, window);
        CHECK(userInput.getButton() == Button::fix);
    }

    // Ajoutez des tests similaires pour les autres touches (S, Z, A, E, C, R, Escape, Enter, etc.)
}

