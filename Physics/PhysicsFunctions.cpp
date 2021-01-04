#include "PhysicsObjects.h"

sf::Vector2f addVectors(sf::Vector2f v1, sf::Vector2f v2) {
    return sf::Vector2f(v1.x + v2.x, v1.y + v2.y);
}

sf::Vector2f subVectors(sf::Vector2f v1, sf::Vector2f v2) {
    return sf::Vector2f(v1.x - v2.x, v1.y - v2.y);
}

sf::Vector2f mulItoVectors(float i, sf::Vector2f v) {
    return sf::Vector2f(v.x * i, v.y * i);
}
