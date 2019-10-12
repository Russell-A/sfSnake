#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"



using namespace sfSnake;

int GameScreen::count_ = 0;
int GameScreen::wangge = 0;

GameScreen::GameScreen() : snake_()
{

}

void GameScreen::handleInput(sf::RenderWindow& window)
{

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
		count_++;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		wangge++;
	}
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta)
{
	if (fruit_.size() <= 15)
		generateFruit();

	snake_.update(delta);
	snake_.checkFruitCollisions(fruit_);

	if (snake_.hitSelf())
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize());
}

void GameScreen::render(sf::RenderWindow& window)
{
	  //创建一个 Image 对象
    // image.create(500, 500, sf::Color::Red);
	backpict = sf::RectangleShape(sf::Vector2f(Game::Width,Game::Height));
    
	switch(count_%3){
	
	case(0): texture.loadFromFile("white.jpg"); break;
	case(1): texture.loadFromFile("black.jpg"); break;
	case(2): texture.loadFromFile("brown.jpg"); break;

	}
	backpict.setTexture(&texture);
	window.draw(backpict);

	// 网格
	if (wangge % 2== 0){
		if(count_%3 == 0){
			sf::VertexArray lines(sf::Lines, 2*Game::Height);
			for( int i = 0 ; i< 2*Game::Height ; i++){
				if (i%2 == 0) lines[i].position = sf::Vector2f(0, 10.0f*(i/2));
				if (i%2 != 0) lines[i].position = sf::Vector2f(Game::Width, 10.f*(i/2));
				lines[i].color = sf::Color(96,96,96);
			}
			window.draw(lines);


			sf::VertexArray coloum(sf::Lines, 2*Game::Width);
			for( int i = 0 ; i< 2*Game::Width ; i++){
				if (i%2 == 0) coloum[i].position = sf::Vector2f( 10.0f*(i/2), 0);
				if (i%2 != 0) coloum[i].position = sf::Vector2f(10.f*(i/2),Game::Height);
				coloum[i].color = sf::Color(96,96,96);		
			}
			window.draw(coloum);
		}
		else
		{
			sf::VertexArray lines(sf::Lines, 2*Game::Height);
			for( int i = 0 ; i< 2*Game::Height ; i++){
				if (i%2 == 0) lines[i].position = sf::Vector2f(0, 10.0f*(i/2));
				if (i%2 != 0) lines[i].position = sf::Vector2f(Game::Width, 10.f*(i/2));
				lines[i].color = sf::Color::White;		
			}
			window.draw(lines);


			sf::VertexArray coloum(sf::Lines, 2*Game::Width);
			for( int i = 0 ; i< 2*Game::Width ; i++){
				if (i%2 == 0) coloum[i].position = sf::Vector2f( 10.0f*(i/2), 0);
				if (i%2 != 0) coloum[i].position = sf::Vector2f(10.f*(i/2),Game::Height);
				coloum[i].color = sf::Color::White;		
			}
			window.draw(coloum);			/* code */
		}
		

	}
	

	snake_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
	
}

void GameScreen::generateFruit()
{
	
	sf:: Color color(128 ,42 ,42 );
	static std::default_random_engine engine;
	// engine.seed(time(0));
	 static std::seed_seq seed{engine(), engine(),engine(),engine(),engine(),engine(),engine()};
	static std::mt19937 generator(seed);
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height);
	// srand(time(NULL));
	int random = rand();
	if(random % 4 == 1) {
		if(random % 8 == 1)
		color = sf::Color ::Black;
		else color = sf::Color(128,42,42);
	}
	else{
		if(random % 3 == 0) color = sf::Color ::Red;
		if(random % 3 == 1) color = sf::Color ::Blue;
		if(random % 3 == 2) color = sf::Color ::Green;
	}

	sf::Vector2f position{(float)xDistribution(generator), (float)yDistribution(generator)};

	fruit_.push_back(Fruit(position , color));
}

// backgroundpicture::backgroundpicture(sf::Vector2f position)
// : position_(position)
// {
// 	rectshape.setPosition(sf::Vector2f(0,0));
// 	rectshape.setFillColor(sf::Color::White);
// 	rectshape.setScale(sf::Vector2f(Game::Width, Game::Height));
// 	std::cout<<"rectshape construct"<<std::endl;

// }

// void backgroundpicture::setPosition(sf::Vector2f position)
// {
// 	position_ = position;
	
// 	rectshape.setPosition(position_);
// }

// void backgroundpicture::setPosition(float x, float y)
// {
// 	position_.x = x;
// 	position_.y = y;
	
// 	rectshape.setPosition(position_);
// }


// sf::Vector2f backgroundpicture::getPosition() const
// {
// 	return position_;
// }

// void backgroundpicture::render(sf::RenderWindow& window)
// {
// 	window.draw(rectshape);
// 	std::cout << "rectshape"<<std::endl;
// }