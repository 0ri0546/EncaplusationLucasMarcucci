#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity{
public:
	double x, y;
	double spe;
	RectangleShape joueur;
	int keys = 0;
	
	Player(double x, double y, double spe);

	Texture personnageTexture;
	Sprite personnageSprite;

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void handleInput();
	double getX();
	double getY();
	void increaseSpeed(float speed);
	Vector2f getPos();
	void collectKey();
	const FloatRect getBounds();
};

#endif