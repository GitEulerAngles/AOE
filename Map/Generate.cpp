#include "MapObjects.h"
#include "PhysicsObjects.h"
#include "Perlin.hpp"
#include <vector>
#include <iostream>

extern mapObj::tile tiles[][25];
int _mapw;
int _maph;
int _length;

sf::Vector2f assignScreenCoords(int x, int y) {
    return sf::Vector2f(
        (x-y) * (_mapw / 2),
        (x+y) * (_maph / 2)
    );
};

void assignPositions() {
    for (int y = 0; y < _length; y++)
    for (int x = 0; x < _length; x++) {
        tiles[x][y].OriginPos = assignScreenCoords(x, y);
        tiles[x][y].texture = rand()%8;
    }
}

void mapGeneration(int mapw, int maph, int length) {
    //Assign globals
    _mapw = mapw;
    _maph = maph;
    _length = length;

    assignPositions();
}
