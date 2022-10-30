#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

enum ShapeType{I_SHAPE,CUBE_SHAPE,T_SHAPE,L_SHAPE,L_SHAPE_INVERSE,S_SHAPE,S_SHAPE_INVERSE};

struct Shape {
	std::map<int, sf::Vector2i> shapeCord;
	ShapeType type;
};


class Tetronimo
{
private:
	Shape tetronimo;
	std::default_random_engine eng;

public:

	Tetronimo();

	void setCord(int i, int x, int y);

	sf::Vector2i getCord(int i);

	ShapeType newTetronimo();

	void rotateTetronimo();

};

