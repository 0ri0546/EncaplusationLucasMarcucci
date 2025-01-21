#include "Entity.hpp"

void Entity::makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY) {
	rectangle.setFillColor(color);
	rectangle.setPosition(posX, posY);
	rectangle.setSize(Vector2f(sizeX, sizeY));
}
void Entity::resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}
