#include <SFML/Graphics.hpp>
#include<iostream>
#include "SnakeNode.h"
#include <cmath>

using namespace sfSnake;

const float SnakeNode::Width = 10.f;
const float SnakeNode::Height = 10.f;

head::head(sf::Vector2f position)
: position_(position){
	sp.setPosition(position_);
	// shape_.setFillColor(sf::Color::Green);
	// shape_.setRadius(5.0f);
	// shape_.setOutlineColor(sf::Color::White);
	// shape_.setOutlineThickness(-1.f);
	// sf::Texture texture;
	 texture.loadFromFile("head.png");
	 texture.setSmooth(false);
	
	texture.loadFromFile("head.png"); //{std::cout << "load picture successfully" << std::endl;};
	sp.setTexture(texture);
	//sp.setScale(sf::Vector2f(SnakeNode::Width,SnakeNode::Height));
	
};

void head::setPosition(sf::Vector2f position)
{
	position_ = position;
	sp.setPosition(position_);
}

void head::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	sp.setPosition(position_);
}

void head::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	sp.setPosition(position_);
}

sf::FloatRect head::getBounds() const
{
	return sp.getGlobalBounds();
}

sf::Vector2f head::getPosition() const
{
	return position_;
}

void head::render(sf::RenderWindow& window , sf::Vector2f & direction_)
{
    texture.loadFromFile("head.png");
	 texture.setSmooth(false);
	
	texture.loadFromFile("head.png"); //{std::cout << "load picture successfully" << std::endl;};
	sp.setTexture(texture);
	//sp.setScale(sf::Vector2f(SnakeNode::Width,SnakeNode::Height));
	float angle = asinf(direction_.x);
	sp.setRotation(angle);


	window.draw(sp);

}

SnakeNode::SnakeNode(sf::Vector2f position)
: position_(position)
{
	shape_circle.setPosition(position_);
	shape_circle.setFillColor(sf::Color::Yellow);
	shape_circle.setRadius(0.5*SnakeNode::Width);
	shape_circle.setOutlineColor(sf::Color::White);
	shape_circle.setOutlineThickness(-1.f);

	shape_.setPosition(position_);
	shape_.setFillColor(sf::Color::Black);
	shape_.setScale(sf::Vector2f(SnakeNode::Width, SnakeNode::Height));
	shape_.setOutlineColor(sf::Color::Black);
	shape_.setOutlineThickness(-1.f);

	sp.setPosition(position_);
	texture.loadFromFile("body.bmp.png");
	sp.setTexture(texture);
}

void SnakeNode::setPosition(sf::Vector2f position)
{
	position_ = position;
	shape_circle.setPosition(position_);
	shape_.setPosition(position_);
}

void SnakeNode::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	shape_circle.setPosition(position_);
	shape_.setPosition(position_);
}

void SnakeNode::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	shape_circle.setPosition(position_);
	shape_.setPosition(position_);
}

sf::FloatRect SnakeNode::getBounds() const
{
	return shape_circle.getGlobalBounds();
	
}

sf::Vector2f SnakeNode::getPosition() const
{
	return position_;
}

void SnakeNode::render(sf::RenderWindow& window)
{

	// window.draw(shape_circle);
	// window.draw(shape_); 
	// std::cout <<  "black"<<std::endl;

	sp.setPosition(position_);
	texture.loadFromFile("body.bmp.png");
	sp.setTexture(texture);

	window.draw(sp);
	
}