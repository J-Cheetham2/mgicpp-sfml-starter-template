
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

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

private:
    void newAnimal();

    enum Gamestate
    {
        IN_MENU,
        IN_GAME,
        GAME_OVER
    };

private:

    Gamestate gamestate = IN_MENU;

    sf::RenderWindow& window;
    sf::Font font;
    sf::Text menu_text;
    sf::Text play_text;
    sf::Text quit_text;
    sf::Text gameOver_text;
    sf::Sprite background;
    sf::Texture background_texture;
    sf::Texture accept_button_texture;
    sf::Texture reject_button_texture;
    sf::Texture accept_stamp_texture;
    sf::Texture reject_stamp_texture;

    std::unique_ptr<sf::Sprite> accept_button;
    std::unique_ptr<sf::Sprite> reject_button;
    std::unique_ptr<sf::Sprite> accept_stamp;
    std::unique_ptr<sf::Sprite> reject_stamp;

    sf::Sprite* character;
    sf::Sprite* passport;

    sf::Sprite* dragged_sprite = nullptr;
    sf::Vector2f drag_offset;

    std::vector<sf::Texture*> animals;
    std::vector<sf::Texture*> passports;

    bool entry_permitted;
    bool passport_stamped = false;
    bool passport_accepted = false;

    int lives;
    sf::Text livesText;
};

#endif // PLATFORMER_GAME_H
