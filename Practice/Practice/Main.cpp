#include<SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"
using namespace std;

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Practice", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("penguin.png");

	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	  
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;

			}
		}

		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		} 

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);
		} */
		player.Update(deltaTime);
		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		player.Draw(window);
		window.display();
	}

	return 0;
}