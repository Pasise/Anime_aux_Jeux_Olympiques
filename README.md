
# Anime Aux Jeux Olympiques

Il s'agit d'un jeu de course de vitesse entre des personnages d'Anime tels que Bleach et One Piece afin de se qualifier pour les Jeux Olympiques 2024


## Authors

- [@Rizlaine Zaroual](https://github.com/RizlaineZaroual)
- [@Amalia Seydou](https://github.com/Pasise)

## Installation

Afin de pouvoir télécharger notre jeu il vous faut la librairie SFML:

```bash
sudo apt update
sudo apt upgrade
sudo apt install libsfml-dev

```
Une fois cette étape passée vous pouvez créer un nouveau dossier: 

```bash
mkdir Dossier_Jeu
```
Puis vous placer dans ce dossier et télécharger le jeu:

```bash
cd Dossier_Jeu
git clone https://github.com/Pasise/Anime_aux_Jeux_Olympiques

```
Il faut maintenant vous placer dans le bon répertoire: 
```bash
cd Anime_aux_Jeux_Olympiques/Code
```

Vous pouvez à présent lancer le jeu avec la commande:

```bash
make execute
```



Pour nettoyer les executables: 

```bash
make clean
```

## Fichiers
Le dossier contient les différents types de fichiers suivants

#### - Les fichiers .hpp dans le dossier header pour la déclaration des Classes: 
- button.hpp
- characterrenderer.hpp (gestion des affichages des joeurs, des fruits et les barres de vie)
- constant.hpp (les constantes)
- fruit.hpp (la classe des fruits)
- game.hpp (le déroulement du jeu)
- main.hpp
- object.hpp (un objet peut être un fuit ou un joueur)
- player.hpp (définition général d'un joueur)
- playermedium.hpp(un joueur avec 1 attaque)
- playerplus.hpp(un joueur avec 2 attaques)
- playerheal.hpp(un joueur avec une attaque et la possibilité de se soigner)
- userinput.hpp (gestion du clavier)

#### - Les fichiers .cpp dans la définition des fonctions dans le dossier src:

- characterrenderer.cpp
- fruit.cpp
- game.cpp
- object.cpp
- player.cpp
- playermedium.cpp
- playerplus.cpp
- playerheal.cpp
- userinput.cpp

#### - Le dossier Sprite contient les sprites utilisés pour ce jeu et les images pour l'affichage en .png

#### - Le dossier musique comprend la musique en fond et les bruitages en .wav

#### - Le dossier tests comprend le doctest, le TestCase et le Makefile associé aux tests

#### Dans le dossier code il y a également : 
- Le makefile pour la compilation et l'éxécution
- le main.cpp pour lancer le jeu


## Tests unitaires 

Pour réaliser les tests unitaires il faut se déplacer dans le dossier tests

```bash
cd ../tests
```
Et lancer la commande 

```bash
make test
```

Amusez vous bien !