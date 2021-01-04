#ifndef MAPOBJ
#define MAPOBJ

#include "SFML/Graphics.hpp"

namespace mapObj {

    enum struct colorDirection {
        YELLOW = 4226955007,
        RED = 2888971007,
        BLUE = 1533993471,
        GREEN = 1790849279
    };

    enum struct typeTile {
        DIRT  = 0,
        GRASS = 1,
        TREE  = 2,
        STONE = 3,
    };

    struct tile {
        sf::Vector2f Pos;
        sf::Vector2f OriginPos;
        sf::Color    color;
        typeTile     type;
        int          texture;
        
    };
}

void mapGeneration(int mapw, int maph, int length);
mapObj::tile* nonChunkCoords(int x, int y);

#endif // !MAPOBJ