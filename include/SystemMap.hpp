#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class SystemMap {
private:
    sf::RenderWindow& window;
    float width;
    float height;
    float scale;
    sf::Vector2f center;

public:
    SystemMap(sf::RenderWindow& win, float width, float height, float scale);

    void setScale(float newScale);
    void setCenter(float x, float y); 

    float getScale() const;
    sf::Vector2f getCenter() const;
    void draw(); 
};

#endif

