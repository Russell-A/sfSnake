#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <math.h>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;

Snake::Snake() : direction_(0 ,-1), hitSelf_(false)
{
	initNodes();

	pickupBuffer_.loadFromFile("Sounds/pickup.wav");
	pickupSound_.setBuffer(pickupBuffer_);
	pickupSound_.setVolume(30);

	dieBuffer_.loadFromFile("Sounds/die.wav");
	dieSound_.setBuffer(dieBuffer_);
	dieSound_.setVolume(50);
}

void Snake::initNodes()
{
    head = sfSnake::head(sf::Vector2f(
			Game::Width / 2 - SnakeNode::Width / 2,
			Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * 0)));
	for (int i = 1; i < Snake::InitialSize; ++i)
	{
		
		nodes_.push_back(SnakeNode(sf::Vector2f(
			Game::Width / 2 - SnakeNode::Width / 2,
			Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * i))));
		

	}
}

void Snake::handleInput(sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		direction_ = sf::Vector2f(0,-1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		direction_ = sf::Vector2f(0,1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction_ = sf::Vector2f(-1,0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		direction_ = sf::Vector2f(1,0);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		// get global mouse position
        sf::Vector2f mouseposition_ = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		// for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
		// {
		// 	nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
		// }
		sf::Vector2f position = nodes_[0].getPosition();
		auto differx = mouseposition_.x -position.x;
		auto differy = mouseposition_.y -position.y;
		auto differx2y2 = differx*differx + differy*differy;
		if(differx2y2!=0){
		differx /= sqrt(differx2y2);
		differy /= sqrt(differx2y2);
		direction_ = sf::Vector2f(differx, differy);
		}
	}
}

void Snake::update(sf::Time delta)
{
	move();
	checkEdgeCollisions();
	checkSelfCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit>& fruits)
{
	decltype(fruits.begin()) toRemove = fruits.end();

	for (auto it = fruits.begin(); it != fruits.end(); ++it)
	{
		if (it->getBounds().intersects(nodes_[0].getBounds()))
			toRemove = it;
	}

	if (toRemove != fruits.end())
	{
		pickupSound_.play();
		if((fruits.end())->getcolor() ==sf::Color::Black);
		else if((fruits.end()-1)->getcolor() ==sf::Color(128,42,42));
		else if((fruits.end()-1)->getcolor() ==sf::Color::Red) {grow(); grow(); grow();}
		else if((fruits.end()-1)->getcolor() ==sf::Color::Blue) {grow(); grow(); }
		else if((fruits.end()-1)->getcolor() ==sf::Color::Green) {grow(); }
		fruits.erase(toRemove);
	}
}

void Snake::grow()
{
	float a = nodes_[nodes_.size() - 2].getPosition().x*2 - nodes_[nodes_.size() - 1].getPosition().x;
	float b = nodes_[nodes_.size() - 2].getPosition().y*2 - nodes_[nodes_.size() - 1].getPosition().y;
		nodes_.push_back(SnakeNode(sf::Vector2f(a,b)));
}

unsigned Snake::getSize() const
{
	return nodes_.size();
}

bool Snake::hitSelf() const
{
	return hitSelf_;
}

void Snake::checkSelfCollisions()
{
	SnakeNode& headNode = nodes_[0];

	for (decltype(nodes_.size()) i = 2; i < nodes_.size(); ++i)
	{
		if (headNode.getBounds().intersects(nodes_[i].getBounds()))
		{
			dieSound_.play();
			sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
			hitSelf_ = true;
		}
	}
}

void Snake::checkEdgeCollisions()
{
	sfSnake::head& headNode = head;

	if (headNode.getPosition().x <= 0)
		headNode.setPosition(Game::Width, headNode.getPosition().y);
	else if (headNode.getPosition().x >= Game::Width)
		headNode.setPosition(0, headNode.getPosition().y);
	else if (headNode.getPosition().y <= 0)
		headNode.setPosition(headNode.getPosition().x, Game::Height);
	else if (headNode.getPosition().y >= Game::Height)
		headNode.setPosition(headNode.getPosition().x, 0);
}

void Snake::move()
{

	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
	}

	nodes_[0].setPosition(head.getPosition());
	head.move(direction_.x*SnakeNode::Width,direction_.y*SnakeNode::Height);
		
	}


void Snake::render(sf::RenderWindow& window)
{
	head.render(window, direction_);
	for (auto node : nodes_)
		node.render(window);
}