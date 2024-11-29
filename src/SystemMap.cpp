#include "SystemMap.hpp"


SystemMap::SystemMap(sf::RenderWindow& win, float width, float height, float scale)
    : window(win), width(width), height(height), scale(scale), center(0, 0) {}


void SystemMap::setScale(float newScale) {
    if (newScale > 0) {
        scale = newScale;
    }
}


void SystemMap::setCenter(float x, float y) {
    center = sf::Vector2f(x, y);
}


float SystemMap::getScale() const {
    return scale;
}


sf::Vector2f SystemMap::getCenter() const {
    return center;
}


void SystemMap::draw() {
    
}

