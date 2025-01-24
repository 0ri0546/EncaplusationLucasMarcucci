#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

class Enemy : Entity{
public:
	double x, y;
	string type;

	int currentFrame = 0;
	int totalFrames = 4;
	float frameWidth;
	float frameHeight;
	float animationSpeed = 0.3f;
	float timeSinceLastFrame = 0;

	RectangleShape enemy;
	Texture enemyTexture, enemyChaseTexture;
	Sprite enemySprite, enemyChaseSprite;
	Player* p;
	Map *map;

	Enemy(double x, double y, string type, Player* p);

	void setMap(Map& map);
	void animate(float deltaTime);
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