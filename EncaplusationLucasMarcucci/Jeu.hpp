#ifndef JEU_HPP
#define JEU_HPP

#include "Enemy.hpp"
#include"Potion.hpp"

class Jeu {
public:
	Player player;
	vector<Enemy> enemies;
	
	Jeu(double x, double y, double speed);

	Texture gameOverScreen, mapTexture;
	Sprite gameOverSprite, mapSprite;

	bool gameOver = false;
	void boucleDeJeu();
	void makeEnemies(double x, double y, string type);
	void makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY);
	void makeCircle(CircleShape& circle, Color& color, float posX, float posY, float rad);
	void makeText(Text& text, Font& font, string message, int characterSize, Color& color, float posX, float posY);
	bool checkCollision(double x1, double y1, double sizeX1, double sizeY1, double x2, double y2, double sizeX2, double sizeY2);
	void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
	float randomFloat(float min, float max);
};

#endif