#include "Enemy.hpp"

Enemy::Enemy(double _x, double _y, string _type, Player* _p) : p(_p),  x(_x), y(_y), type(_type) {
    if (!enemyTexture.loadFromFile("enemy.png")) {}
    resize(enemyTexture, enemySprite, SIZEX, SIZEY);
    enemySprite.setPosition(x, y);
}

void Enemy::update(float deltaTime) {
    if (type == "chase") { ChaserEnemy(); }
    else if (type == "patrol") { PatrollingEnemy(); }
}


void Enemy::draw(RenderWindow& window) {
	window.draw(enemySprite);
}

void Enemy::PatrollingEnemy() {
    int speedEnemis = 4;
    //cout << map.isObstacle(enemySprite.getPosition().x + (float)speedEnemis, enemySprite.getPosition().y) << endl;
    //if (map.isObstacle(enemySprite.getPosition().x + speedEnemis, enemySprite.getPosition().y)) {
    //    goToRight != goToRight;
    //}
    //if (map.isObstacle(enemySprite.getPosition().x - speedEnemis, enemySprite.getPosition().y))
    //{
    //    goToRight != goToRight;
    //}
	if (goToRight && enemySprite.getPosition().x + SIZEX < WIDTH - 50) { enemySprite.move(speedEnemis, 0); }
	else { goToRight = false; }
	if (!goToRight && enemySprite.getPosition().x > 50) { enemySprite.move(-speedEnemis, 0); }
	else { goToRight = true; }
}

void Enemy::ChaserEnemy() {
    static Vector2f targetPosition = enemySprite.getPosition();
    float velocity = 2.f;
    const float stopThreshold = 5.f;
    const float maxX = WIDTH;
    const float maxY = HEIGHT;
    Vector2f posPlayer = p->getPos();
    if (posPlayer.x > 0 && posPlayer.x < WIDTH && posPlayer.y > 0 && posPlayer.y < HEIGHT) {
        targetPosition = Vector2f(posPlayer) - Vector2f(SIZEX / 2, SIZEY / 2);
        if (targetPosition.y < 0) targetPosition.y = 0;
        if (targetPosition.y > maxY) targetPosition.y = maxY;
    }
    
    Vector2f currentPosition = enemySprite.getPosition();
    Vector2f direction = targetPosition - currentPosition;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance > stopThreshold) { direction /= distance; enemySprite.move(direction * velocity); }
    else { enemySprite.setPosition(targetPosition); }
}

double Enemy::getX() { return enemySprite.getPosition().x; }
double Enemy::getY() { return enemySprite.getPosition().y; }

void Enemy::setX(double newX) {
    x = newX;
}

void Enemy::setY(double newY) {
    y = newY;
}