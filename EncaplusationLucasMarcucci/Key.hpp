#ifndef KEY_HPP
#define KEY_HPP

#include "Interactable.hpp"

class Key : public Interactable {
private:
    Vector2f position;
    RectangleShape key;
public:
    Key(const Vector2f& pos);

    Texture keyTexture;
    Sprite keySprite;

    void interact(Player& player);
    void const draw(RenderWindow& window) override;
    const FloatRect getBounds() override;
};
#endif