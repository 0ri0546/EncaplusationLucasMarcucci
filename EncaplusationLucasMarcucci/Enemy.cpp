#include "Enemy.hpp"

Enemy::Enemy(double _x, double _y, string _type, Player* _p) : p(_p),  x(_x), y(_y), type(_type) {
    if (!enemyTexture.loadFromFile("enemy.png")) {}
    if (!enemyChaseTexture.loadFromFile("enemyChaser.png")) {}
    frameWidth = enemyTexture.getSize().x / totalFrames;
    frameHeight = enemyTexture.getSize().y;

    enemySprite.setTextureRect(IntRect(0, 0, frameWidth, frameHeight)); 
    enemySprite.setPosition(x, y);
}

void Enemy::update(float deltaTime) {
    if (type == "chase") { ChaserEnemy(); }
    else if (type == "patrol") { PatrollingEnemy(); }

    animate(deltaTime);
}

void Enemy::draw(RenderWindow& window) {
	window.draw(enemySprite);
}

void Enemy::PatrollingEnemy() {
    resize(enemyChaseTexture, enemySprite, SIZEX * 4, SIZEY);
    int speedEnemis = 4;
    if (map->isObstacle(enemySprite.getPosition().x + speedEnemis + SIZEX, enemySprite.getPosition().y)) {
        goToRight = !goToRight;
    }
    else if (map->isObstacle(enemySprite.getPosition().x - speedEnemis, enemySprite.getPosition().y)) {
        goToRight = !goToRight;
    }
	if (goToRight ) { enemySprite.move(speedEnemis, 0); }
	else { goToRight = false; }
	if (!goToRight ) { enemySprite.move(-speedEnemis, 0); }
	else { goToRight = true; }

    animate(0.016f);
}

void Enemy::ChaserEnemy() {
    resize(enemyTexture, enemySprite, SIZEX * 4, SIZEY);
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

    animate(0.016f);
}

double Enemy::getX() { return enemySprite.getPosition().x; }
double Enemy::getY() { return enemySprite.getPosition().y; }

void Enemy::setX(double newX) {
    x = newX;
}

void Enemy::setY(double newY) {
    y = newY;
}

void Enemy::setMap(Map& map) {
    this->map = &map;
}

void Enemy::animate(float deltaTime) {
    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= animationSpeed) {
        currentFrame = (currentFrame + 1) % totalFrames;
        enemySprite.setTextureRect(IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        timeSinceLastFrame = 0;
    }
}