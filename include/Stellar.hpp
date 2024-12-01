#ifndef STELLAR_HPP
#define STELLAR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

class Stellar {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    float radius;
    sf::Color color;
    std::string name;
    sf::CircleShape shape;
    float orbitalAngle;
    float orbitalSpeed;
    float orbitalRadius;
    sf::Vector2f orbitCenter;


public:
    Stellar(const std::string& name, const sf::Vector2f& position, 
            float mass, float radius, const sf::Color& color
        );

    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;
    float getMass() const;
    float getRadius() const;
    const std::string& getName() const;

    void setPosition(const sf::Vector2f& newPosition);
    void setVelocity(const sf::Vector2f& newVelocity);
    void applyForce(const sf::Vector2f& force);

    void update(float timestep);
    void draw(sf::RenderWindow& window);

    void setOrbit(const sf::Vector2f& center, float radius, float speed);
    void updateOrbit(float timestep);
};

#endif
