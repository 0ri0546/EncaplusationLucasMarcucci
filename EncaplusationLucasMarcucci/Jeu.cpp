#include "Jeu.hpp"

Jeu::Jeu(double x, double y, double speed) : player(Player(x, y, speed)) {
    if (!gameOverScreen.loadFromFile("gameOver.jpg")) {}
    if (!winTexture.loadFromFile("win.png")) {}
    if (!fondTexture.loadFromFile("fond.jpg")) {}
    if (!startScreenTexture.loadFromFile("start.jpg")) {}
    if (!font.loadFromFile("font.ttf")) {}
    if (cursor.loadFromSystem(sf::Cursor::Hand))
    map.loadFromFile("map.txt");
    player.map = map;
}

void Jeu::makeEnemies(double x, double y, string type) {
    Enemy* e = new Enemy(x, y, type, &player);
    e->setMap(map);
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
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Escape the Dungeon", Style::Fullscreen);
    window.setMouseCursor(cursor);

    resize(gameOverScreen, gameOverSprite, WIDTH, HEIGHT);
    gameOverSprite.setPosition(0, 0);

    resize(winTexture, winSprite, WIDTH, HEIGHT);
    winSprite.setPosition(0, 0);

    resize(fondTexture, fondSprite, WIDTH, HEIGHT);
    fondSprite.setPosition(0, 0);

    resize(startScreenTexture, startScreenSprite, WIDTH, HEIGHT);
    startScreenSprite.setPosition(0, 0);
    Color couleurStart(241, 223, 247);
    string textStart = "Appuyez sur une touche pour commencer";
    makeText(start, font, textStart, 60, couleurStart, WIDTH / 2, 300);
    FloatRect textBounds = start.getLocalBounds();
    start.setOrigin(textBounds.width / 2, textBounds.height / 2);
    start.setPosition(WIDTH / 2, 300);

    Color couleurRectangle(230, 150, 80);
    makeRectangle(timerRect, couleurRectangle, 5, 0, 150, 75);

    Color couleurMort1(0, 0, 0, 0);
    makeRectangle(mort1, couleurMort1, 0, 0, WIDTH, HEIGHT);
    
    while (!startGame && window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                startGame = true; 
            }
        }
        window.clear();
        window.draw(startScreenSprite); 
        window.draw(start);
        window.display();
    }

    //----------------------------------------------------ENNEMIS---------------------------------------
    Vector2f posEnemi1 = Vector2f(0,0);
    Vector2f posEnemi2 = Vector2f(50, 200);
    Vector2f posEnemi3 = Vector2f(800, 50);
    Vector2f posEnemi4 = Vector2f(800, 800);
    Vector2f posEnemi5 = Vector2f(1500, 900);
    Vector2f posEnemi6 = Vector2f(1000, 600);
    Vector2f posEnemi7 = Vector2f(1600, 700);
    while (map.isObstacle(posEnemi1.x, posEnemi1.y)) {
        posEnemi1.x += SIZEX;
        posEnemi1.y += SIZEY;
    }
    makeEnemies(posEnemi1.x, posEnemi1.y, "patrol");
    while (map.isObstacle(posEnemi2.x, posEnemi2.y)) {
        posEnemi2.x += SIZEX;
        posEnemi2.y += SIZEY;
    }
    makeEnemies(posEnemi2.x, posEnemi2.y, "chase");
    while (map.isObstacle(posEnemi3.x, posEnemi3.y)) {
        posEnemi3.x += SIZEX;
        posEnemi3.y += SIZEY;
    }
    makeEnemies(posEnemi3.x, posEnemi3.y, "chase");
    while (map.isObstacle(posEnemi4.x, posEnemi4.y)) {
        posEnemi4.x += SIZEX;
        posEnemi4.y += SIZEY;
    }
    makeEnemies(posEnemi4.x, posEnemi4.y, "patrol");
    while (map.isObstacle(posEnemi5.x, posEnemi5.y)) {
        posEnemi5.x += SIZEX;
        posEnemi5.y += SIZEY;
    }
    makeEnemies(posEnemi5.x, posEnemi5.y, "patrol");
    while (map.isObstacle(posEnemi6.x, posEnemi6.y)) {
        posEnemi6.x += SIZEX;
        posEnemi6.y += SIZEY;
    }
    makeEnemies(posEnemi6.x, posEnemi6.y, "patrol");
    while (map.isObstacle(posEnemi7.x, posEnemi7.y)) {
        posEnemi7.x += SIZEX;
        posEnemi7.y += SIZEY;
    }
    makeEnemies(posEnemi7.x, posEnemi7.y, "chase");
    //----------------------------------------------------/ENNEMIS---------------------------------------

    vector<unique_ptr<Interactable>> interactables;
    srand(static_cast<unsigned>(time(nullptr)));
    Vector2f posPotion = Vector2f(randomFloat(0.f, WIDTH * 3/4), randomFloat(0.f, HEIGHT * 3 / 4));
    Vector2f posKey = Vector2f(randomFloat(0.f, WIDTH * 3 / 4), randomFloat(0.f, HEIGHT * 3 / 4));
    while (map.isObstacle(posPotion.x + SIZEX / 2, posPotion.y + SIZEY / 2)) {
        posPotion.x += SIZEX;
        posPotion.y += SIZEY;
    }
    interactables.push_back(make_unique<Potion>(Vector2f(posPotion)));
    while (map.isObstacle(posKey.x + SIZEX / 2, posKey.y + SIZEY / 2)) {
        posKey.x += SIZEX;
        posKey.y += SIZEY;
    }
    interactables.push_back(make_unique<Key>(Vector2f(posKey)));

    while (window.isOpen()) {
        Event event;
        Keyboard keyboard;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (map.isWin(player.getX() + SIZEX / 2, player.getY() + SIZEY +  10) && player.keys > 0) {
                win = true;
            }
        }
        window.clear();
        window.setFramerateLimit(60);
        window.draw(fondSprite);
        map.draw(window);

        for (int i = 0; i < enemies.size(); i++) {
            float deltaTime = clock.restart().asSeconds();
            if (!gameOver && !win) { enemies[i].update(deltaTime); }
            if (!win) { enemies[i].draw(window); }
            if (checkCollision(player.getX(), player.getY(), SIZEX, SIZEY, enemies[i].getX(), enemies[i].getY(), SIZEX, SIZEY)) {
                gameOver = true;
            }
        }

        if (timerInt >= 60) { timerInt = 0; secondes--; }
        string temps = "0:" + to_string(secondes);
        makeText(timer, font, temps, 60, couleurStart, 20, 0);

        if (secondes < 0) { gameOver = true; }

        for (auto it = interactables.begin(); it != interactables.end();) {
            if (player.getBounds().intersects((*it)->getBounds())) {
                (*it)->interact(player);
                if (*it == interactables[1]) {  player.collectKey(); }
                it = interactables.erase(it);
            }
            else { ++it; }
        }
        if (!win) { player.draw(window); }

        if (gameOver) {
            AnimationMort++;
            Color couleurMort(0, 0, 0, AnimationMort);
            mort1.setFillColor(couleurMort);
            window.draw(mort1);
            
            if (AnimationMort >= 255) {
                window.draw(gameOverSprite);
                FloatRect textBounds2 = timer.getLocalBounds();
                timer.setOrigin(textBounds2.width / 2, textBounds2.height / 2);
                timer.setPosition(WIDTH / 2, 50);
                window.draw(timer);
                if (event.type == Event::KeyPressed) {
                    window.close();
                }
            }
        }

        else if (!win) {
            timerInt++;
            window.draw(timerRect);
            window.draw(timer);
            float deltaTime2 = clock.restart().asSeconds();
            player.update(deltaTime2); 
            for (const auto& interactable : interactables) {
                interactable->draw(window);
            }
        }

        if (win) {
            window.draw(winSprite);
            timerRect.setPosition(WIDTH / 2 - timerRect.getSize().x / 2, 80);
            window.draw(timerRect);
            FloatRect textBounds2 = timer.getLocalBounds();
            timer.setOrigin(textBounds2.width / 2, textBounds2.height / 2);
            timer.setPosition(WIDTH / 2, 100);
            window.draw(timer);
        }

        window.display();
    }
}