#include "Jeu.hpp"

Jeu::Jeu(double x, double y, double speed) : player(Player(x, y, speed)) {
    if (!gameOverScreen.loadFromFile("gameOver.jpg")) {}
    if (!mapTexture.loadFromFile("map.png")) {}
}

void Jeu::makeEnemies(double x, double y, string type) {
    Enemy* e = new Enemy(x, y, type, &player);
    enemies.push_back(*e);
}

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

bool Jeu::checkCollision(double x1, double y1, double sizeX1, double sizeY1, double x2, double y2, double sizeX2, double sizeY2) {
    bool overlapX = (x1 < x2 + sizeX2) && (x1 + sizeX1 > x2);
    bool overlapY = (y1 < y2 + sizeY2) && (y1 + sizeY1 > y2);
    return overlapX && overlapY;
}

void Jeu::resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

float Jeu::randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

void Jeu::boucleDeJeu() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Escape the Dungeon");
    resize(gameOverScreen, gameOverSprite, WIDTH, HEIGHT);
    gameOverSprite.setPosition(0, 0);

    resize(mapTexture, mapSprite, WIDTH, HEIGHT);
    mapSprite.setPosition(0, 0);

    makeEnemies(100, 100, "chase");
    makeEnemies(50, 50, "patrol");

    vector<unique_ptr<Interactable>> interactables;
    srand(static_cast<unsigned>(time(nullptr)));
    interactables.push_back(make_unique<Potion>(Vector2f(randomFloat(0.f, WIDTH - SIZEX), randomFloat(0.f, HEIGHT - SIZEY))));
    interactables.push_back(make_unique<Key>(Vector2f(randomFloat(0.f, WIDTH - SIZEX), randomFloat(0.f, HEIGHT - SIZEY))));

    while (window.isOpen()) {
        Event event;
        Keyboard keyboard;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.setFramerateLimit(60);
        window.draw(mapSprite);
        for (int i = 0; i < enemies.size(); i++) {
            if (!gameOver) { enemies[i].update(5.f); enemies[i].draw(window); }
            if (checkCollision(player.getX(), player.getY(), SIZEX, SIZEY, enemies[i].getX(), enemies[i].getY(), SIZEX, SIZEY)) {
                gameOver = true;
            }
        }

        for (auto it = interactables.begin(); it != interactables.end();) {
            if (player.getBounds().intersects((*it)->getBounds())) {
                (*it)->interact(player);
                it = interactables.erase(it);
            }
            else { ++it; }
        }

        if (gameOver) { window.draw(gameOverSprite); }
        else { 
            player.update(5.f); player.draw(window);
            for (const auto& interactable : interactables) {
                interactable->draw(window);
            }
        }
        
        window.display();
    }
}