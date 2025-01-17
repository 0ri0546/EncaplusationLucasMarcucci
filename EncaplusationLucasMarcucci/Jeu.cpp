#include "Jeu.hpp"

Jeu::Jeu(double x, double y, double speed): player(Player(x,y,speed)) {}

void Jeu::makeRectangle(RectangleShape& rectangle, Color& color, float posX, float posY, float sizeX, float sizeY) {
    rectangle.setFillColor(color);
    rectangle.setPosition(posX, posY);
    rectangle.setSize(Vector2f(sizeX, sizeY));
}
void Jeu::makeCircle(CircleShape& circle, Color& color, float posX, float posY, float rad) {
    circle.setFillColor(color);
    circle.setPosition(posX, posY);
    circle.setRadius(rad);
    circle.setOutlineColor(color);
    circle.setOutlineThickness(1);
}
void Jeu::makeText(Text& text, Font& font, string message, int characterSize, Color& color, float posX, float posY) {
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(posX, posY);
}

void Jeu::boucleDeJeu() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Escape the Dungeon");

    Color couleurJoueur(177, 220, 222);
    
    while (window.isOpen()) {
        Event event;
        Keyboard keyboard;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        player.update(5.f);

        window.setFramerateLimit(60);
        window.clear();
        player.draw(window);
        window.display();
    }
}