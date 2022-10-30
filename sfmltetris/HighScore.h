#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class HighScore
{

private:

	
	std::string score;
	sf::Text txtScore;
	sf::Font font;
	int score_num;
	

public:

	HighScore();

	void drawScore(sf::RenderWindow &win);

	void addScore(int scr);


};

