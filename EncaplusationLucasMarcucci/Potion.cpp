#include "Potion.hpp"

Potion::Potion(const Vector2f& pos) : position(pos) {
    if (!potionTexture.loadFromFile("potion.png")) {}
    resize(potionTexture, potionSprite, SIZEX, SIZEY);
    potionSprite.setPosition(pos);
}

void Potion::interact(Player& player) {
    player.increaseSpeed(10.f);
}

const void Potion::draw(RenderWindow& window) {
    window.draw(potionSprite);
}

const FloatRect Potion::getBounds() {
    return potionSprite.getGlobalBounds();
}
