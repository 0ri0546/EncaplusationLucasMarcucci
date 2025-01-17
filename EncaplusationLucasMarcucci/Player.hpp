#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

using namespace std;
using namespace sf;


class Player : public Entity{
public:
	double x, y;
	double spe;
	RectangleShape joueur;
	Player(double x, double y, double spe);

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY);

	void handleInput();
	
};

#endif