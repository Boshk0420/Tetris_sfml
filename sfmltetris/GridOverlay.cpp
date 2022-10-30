#include "GridOverlay.h"


GridOverlay::GridOverlay() {

	for (int i = 0; i < 21; i++) {
	
		horLines.push_back(sf::VertexArray());

		horLines.front().append(sf::Vector2f(100,50+18*i));
		horLines.front().append(sf::Vector2f(100+18*10,50+18*i));

		horLines.front().setPrimitiveType(sf::Lines);

	}


	for (int i = 0; i < 11; i++) {
	
		verLines.push_back(sf::VertexArray());

		verLines.front().append(sf::Vector2f(100+18*i,50));
		verLines.front().append(sf::Vector2f(100+18*i,50+18*20));

		verLines.front().setPrimitiveType(sf::Lines);
	
	
	}



}

void GridOverlay::drawGridOverlay(sf::RenderWindow& window)
{

	auto it_hor = horLines.begin();

	while (it_hor != horLines.end()) {
	
		window.draw(*it_hor);
		it_hor++;
	}

	auto it_ver = verLines.begin();

	while (it_ver != verLines.end()) {
	
		window.draw(*it_ver);
		it_ver++;
	
	}


}
