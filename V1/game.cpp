#ifndef GAME
#define GAME

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "MapObjects.h"
#include "PhysicsObjects.h"
#include "PlayerObjects.h"
#include <random>

using namespace mapObj;
using namespace playerObj;
const int length = 25;

tile tiles[length][length];
sf::Image i1;
sf::Texture t1[8];
sf::Sprite s;
player* warrior = new player;

const sf::Vector2i mapC(121, 61);
sf::Vector2i selected;

void render(sf::RenderWindow * window) {
    int dis = 0;
    //RenderTiles
    for (int y = 0; y < length; y++)
    for (int x = 0; x < length; x++) {
        s.setTexture(t1[tiles[x][y].texture]);
        s.setPosition(tiles[x][y].Pos);
        if (x == selected.x && y == selected.y) {
            s.setColor(sf::Color(100, 100, 100));
        }
        else {
            s.setColor(sf::Color(255, 255, 255));
        }
        window->draw(s);
    }
}
void update() {
    warrior->updateMap(tiles);
    selected = warrior->getMouseTile(mapC);
}
void input(sf::RenderWindow* window, sf::Vector2i mouse_pos) {
    warrior->keyboardEvents();
    sf::Event e;
    warrior->mouse_pos = mouse_pos;
    while (window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            std::cout << "Closed Window";
            window->close();
        }
        if (e.type == sf::Event::MouseWheelMoved) {
            if (e.mouseWheel.delta > 0) {
                warrior->mul += .01;
            }
            else if (e.mouseWheel.delta < 0) {
                warrior->mul -= .01;
            }
            if (warrior->mul < .85) {
                warrior->mul = .85;
            }
            else if (warrior->mul > 1) {
                warrior->mul = 1;
            }
        }
    }
}
void clean() {

}
void start() {
    srand(time(NULL));

    mapGeneration(mapC.x, mapC.y, length);

    i1.loadFromFile("C:/Users/kurtk/source/repos/AOE/Images/tiles.png");
    for (int t = 0; t < 8; t++) {
        t1[t].loadFromImage(i1, sf::Rect(mapC.x * t, 0, mapC.x, mapC.y));
    }
}

#endif // !GAME
