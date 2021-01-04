#ifndef PHYSICS
#define PHYSICS

#include "SFML/Graphics.hpp"

struct linef {
    sf::Vector2f p1;
    sf::Vector2f p2;
    linef(sf::Vector2f point1, sf::Vector2f point2) {
        p1 = point1;
        p2 = point2;
    }
    linef() {

    };
};

class rayf {
public:
    sf::Vector2f Point;
    float Distance = INFINITY;

    rayf(sf::Vector2f pos, sf::Vector2f slp) {
        Position = pos;
        Slope = slp;
    }
    rayf() {};

    void setPos(sf::Vector2f pos) {
        Position = pos;
    }

    void setSlope(sf::Vector2f slp) {
        Slope = slp;
    }

    bool cast(linef wall) {
        float x1 = wall.p1.x;
        float y1 = wall.p1.y;
        float x2 = wall.p2.x;
        float y2 = wall.p2.y;

        float x3 = Position.x;
        float y3 = Position.y;
        float x4 = Position.x + Slope.x;
        float y4 = Position.y + Slope.y;

        float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (den == 0) {
            return false;
        }

        float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

        if (t > 0 && t < 1 && u > 0 && u < Distance) {
            Point = sf::Vector2f((x1 + t * (x2 - x1)), (y1 + t * (y2 - y1)));
            Distance = u;
            return true;
        }
        return false;
    }
private:
    sf::Vector2f Position;
    sf::Vector2f Slope;
};

sf::Vector2f addVectors(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f subVectors(sf::Vector2f v1, sf::Vector2f v2);

sf::Vector2f mulItoVectors(float i, sf::Vector2f v);

#endif // !PHYSICS


