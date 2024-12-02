#ifndef STELLAR_HPP
#define STELLAR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

class Stellar {
private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;
    float radius;
    sf::Color color;
    std::string name;
    float orbitalAngle;
    float orbitalSpeed;
    float orbitalRadius;
    float orbitalSemiMinorAxis;
    float orbitalSemiMajorAxis;
    sf::Vector2f orbitCenter;
    int countEvolution;


public:
    Stellar(const std::string& name, const sf::Vector2f& position, 
            float mass, float radius, const sf::Color& color
        );

    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;
    float getMass() const;
    float getRadius() const;
    float getOrbitalSemiMinorAxis() const;
    float getOrbitalSemiMajorAxis() const ;
    const std::string getName() const;
    int getCountEvolution() const;

    void setPosition(const sf::Vector2f& newPosition);
    void setVelocity(const sf::Vector2f& newVelocity);
    void applyForce(const sf::Vector2f& force);
    void setCountEvolution(int iter);

    void update(float timestep);
    void draw(sf::RenderWindow& window);

    void setOrbit(const sf::Vector2f& center, 
                float orbitalSemiMinorAxis, float orbitalSemiMajorAxis, 
                float speed
            );
    void updateOrbit(float timestep, float orbitalSemiMinorAxis, float orbitalSemiMajorAxis);
};

#endif
