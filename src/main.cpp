#include <SFML/Graphics.hpp>
#include "SystemMap.hpp"

int main() {
    const float mapWidth = 800.0f;
    const float mapHeight = 700.0f;
    const float scale = 10.0f;

    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");

    SystemMap map(window, mapWidth, mapHeight, scale);

    map.setCenter(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        map.draw();
        window.display();
    }

    return 0;
}
