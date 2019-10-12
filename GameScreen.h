#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"

namespace sfSnake
{
class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void generateFruit();

private:
	Snake snake_;
	std::vector<Fruit> fruit_;
	sf::RectangleShape backpict;
	sf::Texture texture;
	sf::Image image;
	static int count_;
	static int wangge;
};

//  class backgroundpicture
// {
// public:
// 	backgroundpicture(sf::Vector2f position = sf::Vector2f(0, 0));

// 	void setPosition(sf::Vector2f position);
// 	void setPosition(float x, float y);

// 	void move(float xOffset, float yOffset);

// 	void render(sf::RenderWindow& window);

// 	sf::Vector2f getPosition() const;
// 	sf::FloatRect getBounds() const;


// private:
// 	sf::RectangleShape rectshape;
// 	sf::Vector2f position_;
// 	sf::RectangleShape backpict;
// };

}


#endif