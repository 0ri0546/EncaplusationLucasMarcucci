#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "Player.hpp"

class Interactable {
public:
	virtual ~Interactable() = default;
	virtual void interact(Player& player) = 0;
	virtual const FloatRect getBounds() = 0;
	virtual const void draw(RenderWindow& window) = 0;
	void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
};

#endif