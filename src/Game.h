
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game(sf::RenderWindow& window);
    ~Game();
    bool init();
    void update(float dt);
    void render();
    void mouseClicked(sf::Event event);
    void keyPressed(sf::Event event);
    void mouseButtonReleased(sf::Event event);

    enum Gamestate
    {
        IN_MENU,
        IN_GAME,
        GAME_OVER
    };

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text menu_text;
    sf::Text play_text;
    sf::Text quit_text;
    sf::Text gameOver_text;
    sf::Sprite background;
    sf::Texture background_texture;

    Gamestate gamestate = IN_MENU;

    int lives;
    sf::Text livesText;
};

#endif // PLATFORMER_GAME_H

