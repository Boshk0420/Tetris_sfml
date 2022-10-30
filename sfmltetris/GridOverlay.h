#pragma once 
#include <SFML/Graphics.hpp>
#include <list>

class GridOverlay
{
private:
	std::list<sf::VertexArray> horLines;
	std::list<sf::VertexArray> verLines;
	
public:
	GridOverlay();
	void drawGridOverlay(sf::RenderWindow &window);

};

