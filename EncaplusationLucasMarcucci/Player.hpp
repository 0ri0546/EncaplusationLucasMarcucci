#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity{
public:
	double x, y;
	double spe;
	RectangleShape joueur;
	
	Player(double x, double y, double spe);

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	int timerBoost = 0;
	void handleInput();
	double getX();
	double getY();
	Vector2f getPos();
};

#endif