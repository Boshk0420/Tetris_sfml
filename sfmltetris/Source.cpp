#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "Grid.h"
#include "Tetronimo.h"
#include "GridOverlay.h"
#include <chrono>


int main() {

	sf::RenderWindow window(sf::VideoMode(100+18*10+100, 50+18*20+50), "Tetris");

	sf::Event event;

	sf::Clock clock;
	sf::Clock rotaClo;


	sf::Texture backround_texture;
	sf::Sprite backround;

	if (!backround_texture.loadFromFile("tetris_backround3.png")) {
		std::cout << "failed to load texture" << std::endl;
	}
	else {
		std::cout << "texture loaded in" << std::endl;
	}

	backround.setTexture(backround_texture);
	backround.setPosition(sf::Vector2f(0, 0));
	
	double fallSpeed = 0.75;
	
	Grid gr;
	gr.updateGrid();

	GridOverlay gro;

	window.setFramerateLimit(30);

	while (window.isOpen())
	{

		while (window.pollEvent(event)) {
		
			if (event.type == sf::Event::Closed) {
					window.close();
			}
		
		}

	
		window.clear();
		window.draw(backround);
		gro.drawGridOverlay(window);
		gr.drawGrid(window);
		
		window.display();

		gr.wipeOne();
		
		gr.collision();
		//gr.lANDr();
		
		
		
		fallSpeed = 0.75;


		if (rotaClo.getElapsedTime().asSeconds() >= 0.1) {

			gr.lANDr();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				gr.rotate();
			}
			rotaClo.restart();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			fallSpeed = 0.01;
		}

		if (clock.getElapsedTime().asSeconds()>= fallSpeed ) {
			
			
			gr.move();
			gr.checkRows();

			clock.restart();
		}

		gr.updateGrid();

		
		


	}
	return 0;
}