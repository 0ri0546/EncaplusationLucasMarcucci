#include "key.hpp"

Key::Key(const Vector2f& pos) : position(pos) {
    if (!keyTexture.loadFromFile("key.png")) {}
    resize(keyTexture, keySprite, SIZEX, SIZEY);
    keySprite.setPosition(pos);
}

void Key::interact(Player& player) {
    player.collectKey();
}

void const Key::draw(RenderWindow& window) {
    window.draw(keySprite);
}

const FloatRect Key::getBounds() {
    return keySprite.getGlobalBounds();
}
