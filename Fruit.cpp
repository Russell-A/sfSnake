#include <SFML/Graphics.hpp>

#include "Fruit.h"

using namespace sfSnake;

const float Fruit::Radius = 5.f;

//Fruit::Fruit(sf::Vector2f position)
//{
//	shape_.setPosition(position);
//	shape_.setRadius(Fruit::Radius);
//	shape_.setFillColor(sf::Color::Red);
//}

Fruit::Fruit(sf::Vector2f position, sf::Color color)
{
	shape_.setPosition(position);
	shape_.setRadius(Fruit::Radius);
	shape_.setFillColor(color);

	fruitcolor = color;
}

void Fruit::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
	return shape_.getGlobalBounds();
}