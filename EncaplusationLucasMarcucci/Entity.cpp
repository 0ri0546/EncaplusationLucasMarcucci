#include "Entity.hpp"

void Entity::makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY) {
	rectangle.setFillColor(color);
	rectangle.setPosition(posX, posY);
	rectangle.setSize(Vector2f(sizeX, sizeY));
}