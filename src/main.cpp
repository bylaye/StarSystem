#include <SFML/Graphics.hpp>
#include "SystemMap.hpp"
#include <Stellar.hpp>


void drawInclinedOrbit(sf::RenderWindow& window, const sf::Vector2f& center, float semiMajorAxis, float semiMinorAxis, float angle, sf::Color color = sf::Color::White) {
    sf::CircleShape orbit(semiMajorAxis);     // Rayon principal (demi-grand axe)
    orbit.setFillColor(sf::Color::Transparent); // Pas de remplissage
    orbit.setPointCount(100); 
    orbit.setOutlineThickness(5.f);           // Épaisseur de la ligne
    orbit.setOutlineColor(color);             // Couleur de l'orbite
    orbit.setOrigin(semiMajorAxis, semiMajorAxis); // Centrer l'ellipse
    orbit.setPosition(center);                // Positionner l'ellipse autour du centre
    orbit.setScale(1.f, semiMinorAxis / semiMajorAxis);
    //orbit.setScale(1.f, 0.55f); // Transformer en ellipse
    orbit.setRotation(angle);                 // Appliquer l'inclinaison

    window.draw(orbit); // Dessiner l'orbite inclinée
}


int main() {
    const float mapWidth = 800.0f;
    const float mapHeight = 720.0f;
    const float scale = 10.0f;

    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");

    SystemMap map(window, mapWidth, mapHeight, scale);

    Stellar sun("Sun", sf::Vector2f(mapWidth/2, mapHeight/2), 1.0e30, 50.f, sf::Color::Yellow);
    Stellar earth("Earth", sf::Vector2f(mapWidth/2 + 50, mapHeight/2), 1.0e30, 20.f, sf::Color(0, 100, 255, 90));

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
        sun.update(timestep);

        window.clear(sf::Color::Black);
        
        sun.draw(window);

        drawInclinedOrbit(window, sun.getPosition(), 100.f, 40.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 120.f, 60.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 150.f, 70.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 190.f, 80.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 230.f, 90.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 260.f, 100.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 300.f, 110.f, 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), 350.f, 140.f, 180.f, sf::Color(255, 155, 0, 100));
        //sun.draw(window);
        map.draw();
        earth.draw(window);
        window.display();
    }

    return 0;
}
