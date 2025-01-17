#ifndef JEU_HPP
#define JEU_HPP

#include "Player.hpp"

class Jeu {
public:
	Player player;
	
	Jeu(double x, double y, double speed);
	void boucleDeJeu();
	void makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY);
	void makeCircle(CircleShape& circle, Color& color, float posX, float posY, float rad);
	void makeText(Text& text, Font& font, string message, int characterSize, Color& color, float posX, float posY);
};

#endif