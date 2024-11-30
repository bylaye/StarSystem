#include <SFML/Graphics.hpp>
#include "SystemMap.hpp"
#include <Stellar.hpp>

int main() {
    const float mapWidth = 800.0f;
    const float mapHeight = 700.0f;
    const float scale = 10.0f;

    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");

    SystemMap map(window, mapWidth, mapHeight, scale);

    Stellar star("Sun", sf::Vector2f(mapWidth/2, mapHeight/2), 1.0e30, 50.f, sf::Color::Yellow);

    sf::Clock clock;
    float timestep = clock.restart().asSeconds();

    map.setCenter(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        star.update(timestep);

        window.clear(sf::Color::Black);
        map.draw();
        star.draw(window);
        window.display();
    }

    return 0;
}
