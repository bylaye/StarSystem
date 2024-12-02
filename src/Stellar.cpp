#include <Stellar.hpp>
#include <iostream>

Stellar::Stellar(const std::string& name, const sf::Vector2f& position, 
                float mass, float radius, const sf::Color& color)
    : name(name), position(position), velocity(0.f, 0.f), 
    acceleration(0.f, 0.f), mass(mass), radius(radius), color(color) {
    
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
    shape.setPosition(position.x, position.y);
    
}

// Getters
const sf::Vector2f& Stellar::getPosition() const {
    return position;
}

const sf::Vector2f& Stellar::getVelocity() const {
    return velocity;
}

float Stellar::getMass() const {
    return mass;
}

float Stellar::getRadius() const {
    return radius;
}

const std::string Stellar::getName() const {
    return name;
}

float Stellar::getOrbitalSemiMinorAxis() const {
    return orbitalSemiMinorAxis;
}

float Stellar::getOrbitalSemiMajorAxis() const {
    return orbitalSemiMajorAxis;
}

int Stellar::getCountEvolution() const {
    return countEvolution;
}

void Stellar::setCountEvolution( int additer){
    countEvolution += additer;
}

// Setters
void Stellar::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
    shape.setPosition(position.x, position.y); // Mettre à jour la position graphique
}

void Stellar::setVelocity(const sf::Vector2f& newVelocity) {
    velocity = newVelocity;
}

// Appliquer une force
void Stellar::applyForce(const sf::Vector2f& force) {
    sf::Vector2f accelerationChange = force / mass; // F = m * a => a = F / m
    acceleration += accelerationChange;
}

// Mettre à jour la position en fonction du temps
void Stellar::update(float timestep) {
    // Mettre à jour la vitesse
    velocity += acceleration * timestep;

    // Mettre à jour la position
    position += velocity * timestep;

    // Réinitialiser l'accélération pour le prochain pas
    acceleration = sf::Vector2f(0.f, 0.f);

    // Mettre à jour la position graphique
    shape.setPosition(position.x, position.y);
}

// Dessiner l'objet sur la fenêtre
void Stellar::draw(sf::RenderWindow& window) {
    window.draw(shape);
}


void Stellar::setOrbit(const sf::Vector2f& center, float semiMinorAxis, float semiMajorAxis, float speed) {
    orbitCenter = center;       // Centre de l'orbite (Soleil)
    orbitalSemiMajorAxis = semiMajorAxis;
    orbitalSemiMinorAxis = semiMinorAxis;
    orbitalSpeed = speed;       // Vitesse angulaire
    orbitalAngle = 0.f;         // Angle initial
}


void Stellar::updateOrbit(float timestep, float orbitalSemiMinorAxis, float orbitalSemiMajorAxis) {
    // Mettre à jour l'angle orbital
    orbitalAngle += orbitalSpeed * timestep;
    //std::cout << "orbit angle" << orbitalAngle << std::endl;
    // Garder l'angle entre 0 et 2*PI pour éviter un débordement
    if (orbitalAngle >= 2 * M_PI) {
        orbitalAngle -= 2 * M_PI;
        countEvolution += 1;
    }

    // Calculer la nouvelle position sur l'orbite circulaire
    float x = orbitalSemiMajorAxis * std::cos(orbitalAngle);
    float y = orbitalSemiMinorAxis * std::sin(orbitalAngle);        

    // Ajuster la position par rapport au centre de l'orbite
    setPosition(orbitCenter + sf::Vector2f(x, y));
}