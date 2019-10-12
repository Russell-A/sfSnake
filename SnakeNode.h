#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
class SnakeNode
{
public:
	SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0));

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void move(float xOffset, float yOffset);

	void render(sf::RenderWindow& window);

	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;

	static const float Width;
	static const float Height;

private:
	sf::RectangleShape shape_;
	sf::Vector2f position_;
	sf::CircleShape shape_circle;
	sf::Sprite sp;
	sf::Texture texture;
};

class head
{
	public:
	head(sf::Vector2f position = sf::Vector2f(0, 0));
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void move(float xOffset, float yOffset);

	void render(sf::RenderWindow& window, sf::Vector2f &);

	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;

	static const float Width;
	static const float Height;

private:
	sf::RectangleShape shape_;
	sf::Sprite sp;
	// sf::CircleShape shape_;
	sf::Vector2f position_;
	sf::Texture texture;
};
}

#endif