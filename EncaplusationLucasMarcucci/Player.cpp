#include "Player.hpp"

Player::Player(double x, double y, double spe) : x(x), y(y), spe(spe) {
	Color couleurJoueur(177, 220, 222);
	makeRectangle(joueur, couleurJoueur, x, y, SIZEX, SIZEY);
	
};

void Player::update(float deltaTime) {
	handleInput();
};

void Player::draw(RenderWindow& window) {
	window.draw(joueur);
};

void Player::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::Right) && joueur.getPosition().x + SIZEX < WIDTH) { joueur.move(spe, 0); }
	if (Keyboard::isKeyPressed(Keyboard::Left) && joueur.getPosition().x > 0) { joueur.move(-spe, 0); }
	if (Keyboard::isKeyPressed(Keyboard::Up) && joueur.getPosition().y > 0) { joueur.move(0,-spe); }
	if (Keyboard::isKeyPressed(Keyboard::Down) && joueur.getPosition().y + SIZEY < HEIGHT) { joueur.move(0, spe); }
	if (timerBoost == 0) {
		spe = 8.;
		if (Keyboard::isKeyPressed(Keyboard::B)) { spe = 12.; timerBoost = 120; }
	}
	timerBoost--;
	if (timerBoost < 0) { timerBoost = 0; }
	
}

double Player::getX() { return joueur.getPosition().x; }
double Player::getY() { return joueur.getPosition().y; }
Vector2f Player::getPos() { return joueur.getPosition(); }