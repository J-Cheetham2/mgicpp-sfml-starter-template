#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf");

	menu_text.setString("Welcome to Critters Crossing! Press the Play button to start, or the Quit button to exit.");
	menu_text.setFillColor(sf::Color(255, 255, 0));
	menu_text.setFont(font);
	menu_text.setCharacterSize(25);
	menu_text.setPosition(
		window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
		window.getSize().y / 4 - menu_text.getGlobalBounds().height / 2);

	play_text.setString("Play");
	play_text.setFillColor(sf::Color(255, 255, 0));
	play_text.setFont(font);
	play_text.setCharacterSize(30);
	play_text.setPosition(
		window.getSize().x / 2 - play_text.getGlobalBounds().width - 50,
		window.getSize().y / 2 - play_text.getGlobalBounds().height / 2);

	quit_text.setString("Quit");
	quit_text.setFillColor(sf::Color(255, 255, 0));
	quit_text.setFont(font);
	quit_text.setCharacterSize(30);
	quit_text.setPosition(
		window.getSize().x / 2 + 50,
		window.getSize().y / 2 - quit_text.getGlobalBounds().height / 2);

	lives = 3;
	livesText.setFont(font);
	livesText.setCharacterSize(30);
	livesText.setFillColor(sf::Color::White);
	livesText.setPosition(10, 10);
	livesText.setString("Lives: " + std::to_string(lives));

	gameOver_text.setFont(font);
	gameOver_text.setString("Game Over");
	gameOver_text.setCharacterSize(60);
	gameOver_text.setFillColor(sf::Color::Red);
	gameOver_text.setPosition(
		window.getSize().x / 2 - gameOver_text.getGlobalBounds().width / 2, 50);

	if (!background_texture.loadFromFile("..\Data\Images\kenney_physicspack\PNG\Backgrounds\colored_shroom.png"))
	{
		std::cout << "background texture did not load \n";
		return false;
	}

	background.setTexture(background_texture);

	return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(background);

	if (gamestate == IN_MENU)
	{
		window.draw(menu_text);
		window.draw(play_text);
		window.draw(quit_text);
	}
	else if (gamestate == IN_GAME)
	{
		window.draw(livesText);
	}
	else if (gamestate == GAME_OVER)
	{
		window.draw(gameOver_text);
		window.draw(play_text);
		window.draw(quit_text);
	}
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}

void Game::mouseButtonReleased(sf::Event event)
{

}


