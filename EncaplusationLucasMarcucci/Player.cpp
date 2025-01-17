#include "Player.hpp"

Player::Player(double x, double y, double spe) : x(x), y(y), spe(spe) {
	Color couleurJoueur(177, 220, 222);
	makeRectangle(joueur, couleurJoueur, x, y, SIZEX, SIZEY);
};

void Player::makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY) {
	rectangle.setFillColor(color);
	rectangle.setPosition(posX, posY);
	rectangle.setSize(Vector2f(sizeX, sizeY));
}

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
}
