#include <SFML/Graphics.hpp>
#include "SystemMap.hpp"
#include <Stellar.hpp>
#include <unistd.h>

void drawInclinedOrbit(sf::RenderWindow& window, const sf::Vector2f& center, float semiMinorAxis, float semiMajorAxis, float angle, sf::Color color = sf::Color::White) {
    sf::CircleShape orbit(semiMajorAxis);     // Rayon principal (demi-grand axe)
    orbit.setFillColor(sf::Color::Transparent); // Pas de remplissage
    orbit.setPointCount(100); 
    orbit.setOutlineThickness(2.f);           // Épaisseur de la ligne
    orbit.setOutlineColor(color);             // Couleur de l'orbite
    orbit.setOrigin(semiMajorAxis, semiMajorAxis); // Centrer l'ellipse
    orbit.setPosition(center);                // Positionner l'ellipse autour du centre
    orbit.setScale(1.f, semiMinorAxis / semiMajorAxis);
    //orbit.setScale(1.f, 0.55f); // Transformer en ellipse
    orbit.setRotation(angle);                 // Appliquer l'inclinaison

    window.draw(orbit); // Dessiner l'orbite inclinée
}


int main() {
    const float mapWidth = 1000.0f;
    const float mapHeight = 600.0f;
    const float scale = 10.0f;

    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");

    SystemMap map(window, mapWidth, mapHeight, scale);

    Stellar sun("Sun", sf::Vector2f(mapWidth/2, mapHeight/2), 1.0e30, 40.f, sf::Color::Yellow);
    
    Stellar mercure("Mercure", sf::Vector2f(mapWidth/2 + 50, mapHeight/2), 1.0e30, 3.f, sf::Color::White);
    mercure.setOrbit(sun.getPosition(), 45, 65, 2.f);

    Stellar venus("Venus", sf::Vector2f(mapWidth/2 + 50, mapHeight/2), 1.0e30, 7.f, sf::Color::Magenta);
    venus.setOrbit(sun.getPosition(), 50, 80, 2.f);

    Stellar earth("Earth", sf::Vector2f(mapWidth/2 + 50, mapHeight/2), 1.0e30, 10.f, sf::Color(0, 100, 255, 90));
    earth.setOrbit(sun.getPosition(), 90, 120, 2.f);

    Stellar mars("Mars", sf::Vector2f(mapWidth/2 + 100, mapHeight/2), 1.0e30, 12.f, sf::Color(200, 10, 155, 90));
    mars.setOrbit(sun.getPosition(), 100, 130, 1.f);

    Stellar jupiter("Jupiter", sf::Vector2f(mapWidth/2 + 100, mapHeight/2), 1.0e30, 14.f, sf::Color(100, 150, 155, 90));
    jupiter.setOrbit(sun.getPosition(), 140, 180, 1.f);

    Stellar saturn("Saturn", sf::Vector2f(mapWidth/2 + 100, mapHeight/2), 1.0e30, 14.f, sf::Color(100, 50, 15, 90));
    saturn.setOrbit(sun.getPosition(), 160, 210, 1.f);

    Stellar uranus("Uranus", sf::Vector2f(mapWidth/2 + 100, mapHeight/2), 1.0e30, 18.f, sf::Color(100, 150, 0, 90));
    uranus.setOrbit(sun.getPosition(), 190, 240, 1.f);

    Stellar neptune("Neptune", sf::Vector2f(mapWidth/2 + 100, mapHeight/2), 1.0e30, 20.f, sf::Color(100, 0, 155, 90));
    neptune.setOrbit(sun.getPosition(), 210, 290, 1.f);

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

        float timestep = clock.restart().asSeconds();
        sun.update(timestep);
        mercure.updateOrbit(timestep, mercure.getOrbitalSemiMinorAxis(), mercure.getOrbitalSemiMajorAxis());
        venus.updateOrbit(timestep, venus.getOrbitalSemiMinorAxis(), venus.getOrbitalSemiMajorAxis());
        earth.updateOrbit(timestep, earth.getOrbitalSemiMinorAxis(), earth.getOrbitalSemiMajorAxis());
        mars.updateOrbit(timestep, mars.getOrbitalSemiMinorAxis(), mars.getOrbitalSemiMajorAxis());
        jupiter.updateOrbit(timestep, jupiter.getOrbitalSemiMinorAxis(), jupiter.getOrbitalSemiMajorAxis());
        saturn.updateOrbit(timestep, saturn.getOrbitalSemiMinorAxis(), saturn.getOrbitalSemiMajorAxis());
        uranus.updateOrbit(timestep, uranus.getOrbitalSemiMinorAxis(), uranus.getOrbitalSemiMajorAxis());
        neptune.updateOrbit(timestep, neptune.getOrbitalSemiMinorAxis(), neptune.getOrbitalSemiMajorAxis());
        usleep(500);
        window.clear(sf::Color::Black);
        
        sun.draw(window);

        drawInclinedOrbit(window, sun.getPosition(), mercure.getOrbitalSemiMinorAxis(), mercure.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), venus.getOrbitalSemiMinorAxis(), venus.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), earth.getOrbitalSemiMinorAxis(), earth.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), mars.getOrbitalSemiMinorAxis(), mars.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), jupiter.getOrbitalSemiMinorAxis(), jupiter.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), saturn.getOrbitalSemiMinorAxis(), saturn.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), uranus.getOrbitalSemiMinorAxis(), uranus.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        drawInclinedOrbit(window, sun.getPosition(), neptune.getOrbitalSemiMinorAxis(), neptune.getOrbitalSemiMajorAxis(), 180.f, sf::Color(255, 155, 0, 100));
        

        map.draw();
        mercure.draw(window);
        venus.draw(window);
        earth.draw(window);
        mars.draw(window);
        jupiter.draw(window);
        saturn.draw(window);
        uranus.draw(window);
        neptune.draw(window);
        window.display();
        //usleep(200000);
    }

    return 0;
}
