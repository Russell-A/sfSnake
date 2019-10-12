#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
class Fruit
{
public:
	Fruit(sf::Vector2f position = sf::Vector2f(0, 0));

	Fruit(sf::Vector2f position , sf::Color);

	void render(sf::RenderWindow& window);
	sf::Color getcolor(){ return fruitcolor;}
	sf::FloatRect getBounds() const;

private:
	sf::CircleShape shape_;
    sf:: Color fruitcolor;    //新增 用来记录颜色
	static const float Radius;
};
}

#endif