#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

using namespace sfSnake;

GameOverScreen::GameOverScreen(std::size_t score) : score_(score)
{
	font_.loadFromFile("Fonts/Futura-medium-6.ttf");
	text_.setFont(font_);
	text_.setString("Your score:   " + std::to_string(score) + "!" + "\n\n\n\n\n\n\n\n\n" +
		"\n\nPress [SPACE] to retry"
		"\n\nPress [ESC] to quit");
	text_.setFillColor(sf::Color::Red);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2+15);
	text_.setCharacterSize(34);
	text_.setOutlineThickness(1.0f);
	text_.setOutlineColor(sf::Color::Black);
}

void GameOverScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void GameOverScreen::update(sf::Time delta)
{

}

void GameOverScreen::render(sf::RenderWindow& window)
{
	sp = sf::RectangleShape(sf::Vector2f(Game::Width,Game::Height));
	texture.loadFromFile("gameover.jpg");
	sp.setTexture(&texture);
	window.draw(sp);
	window.draw(text_);
}