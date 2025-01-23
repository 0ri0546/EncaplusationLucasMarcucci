#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

class Enemy : Entity{
public:
	Player* p;

	double x, y;
	string type;

	RectangleShape enemy;
	Texture enemyTexture;
	Sprite enemySprite;
	Map map;

	Enemy(double x, double y, string type, Player* p);

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void ChaserEnemy();
	void PatrollingEnemy();
	bool goToRight = true;
	double getX();
	double getY();
	void setX(double newX);
	void setY(double newY);
};

#endif