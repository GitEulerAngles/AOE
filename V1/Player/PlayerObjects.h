#ifndef PLAYER
#define PLAYER

#include "SFML/Graphics.hpp"
#include "PhysicsObjects.h"
#include "MapObjects.h"

namespace playerObj {
    class player {
    public:
        sf::View cam;
        sf::Vector2i mouse_pos = sf::Vector2i(0, 0);
        float mul = 1;
        float speed = 2.5;
        sf::Vector2f pos = sf::Vector2f(0, 0);

        void updateMap(mapObj::tile (&map)[25][25]);
        sf::Vector2i getMouseTile(sf::Vector2i mapConstant);
        void keyboardEvents();
    private:
    };
}

#endif // !PLAYER