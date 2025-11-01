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

	 if (!background_texture.loadFromFile("../Data/Images/kenney_physicspack/PNG/Backgrounds/colored_shroom.png"))
	{
		std::cout << "background texture did not load \n";
		return false;
	}

	background.setTexture(background_texture);

	character = new sf::Sprite();
	passport = new sf::Sprite();

	sf::Texture* animal_texture_1 = new sf::Texture();

	if (!animal_texture_1->loadFromFile("../Data/Images/kenney_physicspack/PNG/Other/penguin.png"))
	{
		std::cout << "Failed to load penguin.png" << std::endl;
		return false;
	}
	sf::Texture* passport_texture_1 = new sf::Texture();
	if (!passport_texture_1->loadFromFile("../Data/Images/penguin passport.png"))
	{
		std::cout << "Failed to load penguin passport.png" << std::endl;
		return false;
	}

	sf::Texture* animal_texture_2 = new sf::Texture();
	if (!animal_texture_2->loadFromFile("../Data/Images/elephant.png"))
	{
		std::cout << "Failed to load elephant.png" << std::endl;
		return false;
	}
	sf::Texture* passport_texture_2 = new sf::Texture();
	if (!passport_texture_2->loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "Failed to load elephant passport.png" << std::endl;
		return false;
	}

	sf::Texture* animal_texture_3 = new sf::Texture();
	if (!animal_texture_3->loadFromFile("../Data/Images/Critter Crossing Customs/giraffe.png"))
	{
		std::cout << "Failed to load giraffe.png" << std::endl;
		return false;
	}
	sf::Texture* passport_texture_3 = new sf::Texture();
	if (!passport_texture_3->loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "Failed to load moose passport.png" << std::endl;
		return false;
	}
	animals.push_back(animal_texture_1);
	animals.push_back(animal_texture_2);
	animals.push_back(animal_texture_3);

	passports.push_back(passport_texture_1); 
	passports.push_back(passport_texture_2); 
	passports.push_back(passport_texture_3);

	newAnimal();

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
		window.draw(*character);
		window.draw(*passport);
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
	sf::Vector2i click_position = sf::Mouse::getPosition(window);
	sf::Vector2f click_position_f(
		static_cast<float>(click_position.x),
		static_cast<float>(click_position.y));

	if (gamestate == IN_MENU || gamestate == GAME_OVER)
	{
		if (play_text.getGlobalBounds().contains(click_position_f))
		{
			gamestate = IN_GAME;
			lives = 3;
			livesText.setString("Lives: " + std::to_string(lives));

			newAnimal();
		}

		else if (quit_text.getGlobalBounds().contains(click_position_f))
		{
			window.close();
		}
	}
	else if (gamestate == IN_GAME)
	{

	}
}

void Game::keyPressed(sf::Event event)
{

}

void Game::mouseButtonReleased(sf::Event event)
{

}

void Game::newAnimal()
{
	int animal_index = rand() % animals.size();
	int passport_index = rand() % passports.size();

	entry_permitted = (animal_index == passport_index);

	character->setTexture(*animals[animal_index], true);
	passport->setTexture(*passports[passport_index], true);

	character->setPosition(100, 300);
	passport->setPosition(500, 300);
}


