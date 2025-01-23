#ifndef MAP_HPP
#define MAP_HPP

#include "Entity.hpp"

class Map {
private:
    Texture wallTexture, floorTexture, doorTexture;
    Sprite wallSprite, floorSprite, doorSprite;

public:
    bool doorLocked = true;
    vector<string> mapData;
    void loadFromFile(const string& filename);
    void draw(RenderWindow& window);
    bool isObstacle(double x, double y);
    void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
};

#endif