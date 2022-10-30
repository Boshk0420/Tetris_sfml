#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "Grid.h"
#include "Tetronimo.h"
#include "HighScore.h"

enum Rotation {zeroDeg,ninetyDeg};

class Grid
{
private:

	int grid[20][10]; // 0 for empty, 1 for moving block, 2 for static block,
	// 3 for ghost block
	Tetronimo tetronimo;

	ShapeType type;
	Rotation rotationVal;

	sf::RectangleShape rect;

	HighScore score;

	
	

	

	
				

public:

	Grid();
	void drawGrid(sf::RenderWindow &window);

	void updateGrid(); 
	void wipeOne();

	void move();
	void collision();

	void lANDr();

	void checkRows();

	void clearRow(int row);

	void dropDownRow(int row);

	void rotate();

	void updateGhost();

	void gameOver();


};

