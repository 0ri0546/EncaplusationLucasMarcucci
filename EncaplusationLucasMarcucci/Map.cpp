#include "Map.hpp"

void Map::resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

void Map::loadFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        mapData.push_back(line);
    }

    wallTexture.loadFromFile("wall.png");
    doorTexture.loadFromFile("door.png");
    resize(wallTexture, wallSprite, SIZEX, SIZEY);
    resize(doorTexture, doorSprite, SIZEX * 2, SIZEY);
}

void Map::draw(RenderWindow& window) {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                wallSprite.setPosition(x * SIZEX, y * SIZEY); //38.4, 21.6
                window.draw(wallSprite);
            }
            else if (mapData[y][x] == 'D') {
                doorSprite.setPosition(x * SIZEX, y * SIZEY);
                window.draw(doorSprite);
            }
        }
    }
}

bool Map::isObstacle(double x, double y) {
    int tileX = x / (double)SIZEX;
    int tileY = y / (double)SIZEY;

    if (mapData[tileY][tileX] == '#' || mapData[tileY][tileX] == 'D' || mapData[tileY][tileX] == 'd') {;
        return true;
    }
    return false;
}

bool Map::isWin(double x, double y) {
    int tileX = x / (double)SIZEX;
    int tileY = y / (double)SIZEY;

    if (mapData[tileY][tileX] == 'D' && Keyboard::isKeyPressed(Keyboard::E)) {
        return true;
        cout << "test";
    }
    return false;
}
