#include "Player.hpp"

Player::Player(double x, double y, double spe) : x(x), y(y), spe(spe) {
	if (!personnageTexture.loadFromFile("personnage.png")) {}
	resize(personnageTexture, personnageSprite, SIZEX, SIZEY);

	frameWidth = personnageTexture.getSize().x / totalFrames;
	frameHeight = personnageTexture.getSize().y;

	resize(personnageTexture, personnageSprite, SIZEX * 4, SIZEY);
	personnageSprite.setTextureRect(IntRect(0, 0, frameWidth, frameHeight));
	personnageSprite.setPosition(x, y);
}

void Player::update(float deltaTime) {
	handleInput();
	animate(0.016f);
}

void Player::draw(RenderWindow& window) {
	window.draw(personnageSprite);
}

void Player::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::Right) && personnageSprite.getPosition().x + SIZEX < WIDTH && !map.isObstacle(personnageSprite.getPosition().x + spe + SIZEX, personnageSprite.getPosition().y)) {
		personnageSprite.move(spe, 0); 
		/*personnageSprite.setScale(-2.1875, 2.1875);*/ 
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && personnageSprite.getPosition().x > 0 && !map.isObstacle(personnageSprite.getPosition().x - spe, personnageSprite.getPosition().y)) {
		personnageSprite.move(-spe, 0);
		/*personnageSprite.setScale(2.1875, 2.1875);*/ // taille souhaitée / taille de la texture = 2.1875
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && personnageSprite.getPosition().y > 0 && !map.isObstacle(personnageSprite.getPosition().x, personnageSprite.getPosition().y - spe)) { personnageSprite.move(0,-spe); }
	if (Keyboard::isKeyPressed(Keyboard::Down) && personnageSprite.getPosition().y + SIZEY < HEIGHT && !map.isObstacle(personnageSprite.getPosition().x, personnageSprite.getPosition().y + spe + SIZEY)) { personnageSprite.move(0, spe); }
	animate(0.016f);
}

void Player::increaseSpeed(float speed) {
	spe = speed;
}

void Player::collectKey() {
	keys++;
}

const FloatRect Player::getBounds() {
	return personnageSprite.getGlobalBounds();
}

double Player::getX() { return personnageSprite.getPosition().x; }
double Player::getY() { return personnageSprite.getPosition().y; }
Vector2f Player::getPos() { return personnageSprite.getPosition(); }

void Player::animate(float deltaTime) {
	timeSinceLastFrame += deltaTime;

	if (timeSinceLastFrame >= animationSpeed) {
		currentFrame = (currentFrame + 1) % totalFrames;
		personnageSprite.setTextureRect(IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
		timeSinceLastFrame = 0;
	}
}