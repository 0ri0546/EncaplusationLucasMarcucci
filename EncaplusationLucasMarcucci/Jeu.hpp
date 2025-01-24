#ifndef JEU_HPP
#define JEU_HPP

#include "Potion.hpp"
#include "Enemy.hpp"

class Jeu {
public:
	Player player;
	vector<Enemy> enemies;
	Map map;
	Clock clock;
	Font font;
	Cursor cursor;
	
	Jeu(double x, double y, double speed);

	Texture gameOverScreen, winTexture, fondTexture, startScreenTexture;
	Sprite gameOverSprite, winSprite, fondSprite, startScreenSprite; 
	Text start, timer;
	RectangleShape timerRect, mort1;

	bool startGame = false;
	bool gameOver = false;
	bool win = false;
	int timerInt = 1800;
	int secondes = 30;
	int AnimationMort = 0;
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