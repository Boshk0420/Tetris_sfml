#include "HighScore.h"


HighScore::HighScore() {
	
	
	score = "0";
	score_num = 0;
	
	if (!font.loadFromFile("Pixeled.ttf")){
	std::cout << "failed to load font" << std::endl;
	}else{
	std::cout << "font loaded in" << std::endl;
	txtScore.setFont(font);
	}

	txtScore.setPosition(sf::Vector2f(13,115));
	txtScore.setCharacterSize(15);
	txtScore.setString(score);


}
	

void HighScore::drawScore(sf::RenderWindow& win)
{

	score = std::to_string(score_num);
	txtScore.setString(score);
	win.draw(txtScore);


}

void HighScore::addScore(int scr)
{
	score_num += scr;

}
