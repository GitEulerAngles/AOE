#include "SFML\Graphics.hpp"
#include "PlayerObjects.h"
#include "MapObjects.h"

void playerObj::player::updateMap (mapObj::tile (&map)[25][25]) {
    for (int y = 0; y < 25; y++)
    for (int x = 0; x < 25; x++) {
        map[x][y].Pos.x = map[x][y].OriginPos.x + pos.x;
        map[x][y].Pos.y = map[x][y].OriginPos.y + pos.y;
    }
}

sf::Vector2i playerObj::player::getMouseTile(sf::Vector2i mapConstant) {
    sf::Vector2f game_pos = subVectors((sf::Vector2f)mouse_pos, pos);
    sf::Vector2i vLength = sf::Vector2i(mapConstant.x - 1, mapConstant.y - 1);
    sf::Vector2i vCell = sf::Vector2i(floor(game_pos.x / vLength.x), floor(game_pos.y / vLength.y));
    sf::Vector2i vOffset = sf::Vector2i(fmod(game_pos.x, vLength.x)+1, fmod(game_pos.y, vLength.y)+1);
    sf::Vector2i selected;

    sf::Image t2;
    t2.loadFromFile("C:/Users/kurtk/source/repos/AOE/Images/tileCoordinates.png");

    if (vOffset.x <= 0) {
        vOffset.x = mapConstant.x-fabs(vOffset.x)-2;
    }

    if (vOffset.x < mapConstant.x && vOffset.y < mapConstant.y && vOffset.y > 0) {
        sf::Color c = t2.getPixel(vOffset.x, vOffset.y);
        switch (c.toInteger())
        {
        case (sf::Uint32)mapObj::colorDirection::YELLOW:
            selected = sf::Vector2i(vCell.y + vCell.x, vCell.y - vCell.x+1);
            break;
        case (sf::Uint32)mapObj::colorDirection::RED:
            selected = sf::Vector2i(vCell.y + vCell.x, vCell.y - vCell.x-1);
            break;
        case (sf::Uint32)mapObj::colorDirection::BLUE:
            selected = sf::Vector2i(vCell.y + vCell.x-1, vCell.y - vCell.x);
            break;
        case (sf::Uint32)mapObj::colorDirection::GREEN:
            selected = sf::Vector2i(vCell.y + vCell.x+1, vCell.y - vCell.x);
            break;
        default:
            selected = sf::Vector2i(vCell.y + vCell.x, vCell.y - vCell.x);
            break;
        }
    }
    else {
        return sf::Vector2i(-1, -1);
    }

    return selected;
}

void playerObj::player::keyboardEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos.x -= speed;
    }
}