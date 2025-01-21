#ifndef POTION_HPP
#define POTION_HPP

#include "Key.hpp"
#include "Entity.hpp"

class Potion : public Interactable {
private:
    Vector2f position;
    RectangleShape potion;
    Texture potionTexture;
    Sprite potionSprite;
public:
    Potion(const Vector2f& pos);

    void interact(Player& player) override;
    void const draw(RenderWindow& window) override;
    const FloatRect getBounds() override;
};

#endif