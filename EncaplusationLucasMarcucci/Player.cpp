#include "Player.hpp"

Player::Player(double x, double y, double spe) : x(x), y(y), spe(spe) {
	if (!personnageTexture.loadFromFile("personnage.png")) {}
	resize(personnageTexture, personnageSprite, SIZEX, SIZEY);
	personnageSprite.setPosition(x, y);
};

void Player::update(float deltaTime) {
	handleInput();
};

void Player::draw(RenderWindow& window) {
	window.draw(personnageSprite);
};

void Player::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::Right) && personnageSprite.getPosition().x + SIZEX < WIDTH) { 
		personnageSprite.move(spe, 0); 
		/*personnageSprite.setScale(-2.1875, 2.1875);*/
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && personnageSprite.getPosition().x > 0) { 
		personnageSprite.move(-spe, 0);
		/*personnageSprite.setScale(2.1875, 2.1875);*/ // taille souhaitée / taille de la texture = 2.1875
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && personnageSprite.getPosition().y > 0) { personnageSprite.move(0,-spe); }
	if (Keyboard::isKeyPressed(Keyboard::Down) && personnageSprite.getPosition().y + SIZEY < HEIGHT) { personnageSprite.move(0, spe); }
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