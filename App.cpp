#include "game.hpp"

void main() {
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(1920,1080), "AOE", sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);

    start();

    while (window.isOpen()) {
        window.clear(sf::Color(0, 0, 0));

        input(&window, sf::Mouse::getPosition(window));
        update();
        render(&window);

        window.display();
    }

    clean();
}
