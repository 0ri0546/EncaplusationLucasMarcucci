#include "Enemy.hpp"

Enemy::Enemy(double _x, double _y, string _type, Player* _p) : p(_p),  x(_x), y(_y), type(_type) {
	Color couleurEnemy(235, 5, 24);
	makeRectangle(enemy, couleurEnemy, x, y, SIZEX, SIZEY);
}

void Enemy::update(float deltaTime) {
	if (type == "chase") { ChaserEnemy(); }
	else if (type == "patrol") { PatrollingEnemy(); }
};

void Enemy::draw(RenderWindow& window) {
	window.draw(enemy);
};

void Enemy::PatrollingEnemy() {
	if (goToRight && enemy.getPosition().x + SIZEX < WIDTH - 50) { enemy.move(5, 0); }
	else { goToRight = false; }
	if (!goToRight && enemy.getPosition().x > 50) { enemy.move(-5, 0); }
	else { goToRight = true; }
}

void Enemy::ChaserEnemy() {
    static Vector2f targetPosition = enemy.getPosition();
    static Clock clock;
    float velocity = 100.f;
    const float stopThreshold = 5.f;
    const float maxX = WIDTH;
    const float maxY = HEIGHT;
    Vector2f posPlayer = p->getPos();
    if (posPlayer.x > 0 && posPlayer.x < WIDTH && posPlayer.y > 0 && posPlayer.y < HEIGHT) {
        targetPosition = Vector2f(posPlayer) - Vector2f(SIZEX / 2, SIZEY / 2);
        if (targetPosition.y < 0) targetPosition.y = 0;
        if (targetPosition.y > maxY) targetPosition.y = maxY;
    }
    
    float deltaTime = clock.restart().asSeconds();
    Vector2f currentPosition = enemy.getPosition();
    Vector2f direction = targetPosition - currentPosition;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance > stopThreshold) { direction /= distance; enemy.move(direction * velocity * deltaTime); }
    else { enemy.setPosition(targetPosition); }
}

double Enemy::getX() { return enemy.getPosition().x; }
double Enemy::getY() { return enemy.getPosition().y; }