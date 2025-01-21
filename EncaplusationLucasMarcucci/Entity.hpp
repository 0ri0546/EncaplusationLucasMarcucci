#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "datas.hpp"

class Entity {
public:
    virtual void update(float deltaTime) = 0;
    virtual void draw(RenderWindow & window) = 0;
    void makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY);
    void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
};

#endif