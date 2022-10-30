#include "Grid.h"

// have to do: 
// add a ghost block
// maby add music and a mute button would be giga epicke

Grid::Grid() {

	std:: memset(grid, 0, sizeof(grid));
	type=tetronimo.newTetronimo();
	rotationVal = zeroDeg;
	
	rect.setSize(sf::Vector2f(18, 18));

	
	
	
}

void Grid::drawGrid(sf::RenderWindow& window)
{
 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (grid[j][i] == 1 || grid[j][i] == 2) {
				rect.setPosition(sf::Vector2f(100+18*i,50+18*j));
				window.draw(rect);
			}
		}
	}

	score.drawScore(window);

	

}

void Grid::updateGrid()
{
	grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x] = 1;
	grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x] = 1;
	grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x] = 1;
	grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x] = 1;
}

void Grid::wipeOne()
{
	grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x] = 0;
	grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x] = 0;
	grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x] = 0;
	grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x] = 0;
}

void Grid::move()
{

	tetronimo.setCord(1, tetronimo.getCord(1).x, tetronimo.getCord(1).y + 1);
	tetronimo.setCord(2, tetronimo.getCord(2).x, tetronimo.getCord(2).y + 1);
	tetronimo.setCord(3, tetronimo.getCord(3).x, tetronimo.getCord(3).y + 1);
	tetronimo.setCord(4, tetronimo.getCord(4).x, tetronimo.getCord(4).y + 1);
}

void Grid::collision() {


	if (tetronimo.getCord(1).y == 19 || tetronimo.getCord(2).y == 19
		|| tetronimo.getCord(3).y == 19 || tetronimo.getCord(4).y == 19) {

		grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x] = 2;
		grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x] = 2;
		grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x] = 2;
		grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x] = 2;

		type = tetronimo.newTetronimo();
		rotationVal = zeroDeg;

	}

	if (grid[tetronimo.getCord(1).y + 1][tetronimo.getCord(1).x] == 2 ||
		grid[tetronimo.getCord(2).y + 1][tetronimo.getCord(2).x] == 2 ||
		grid[tetronimo.getCord(3).y + 1][tetronimo.getCord(3).x] == 2 ||
		grid[tetronimo.getCord(4).y + 1][tetronimo.getCord(4).x] == 2) {

		grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x] = 2;
		grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x] = 2;
		grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x] = 2;
		grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x] = 2;

		type = tetronimo.newTetronimo();
		rotationVal = zeroDeg;
	}


}

void Grid::lANDr()
{


	if (!(tetronimo.getCord(1).x == 9 || tetronimo.getCord(2).x == 9
		|| tetronimo.getCord(3).x == 9 || tetronimo.getCord(4).x == 9)
		) {

		if (!(grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x+1] == 2 ||
			grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x+1] == 2 ||
			grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x+1] == 2 ||
			grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x+1] == 2)) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {

				tetronimo.setCord(1, tetronimo.getCord(1).x + 1, tetronimo.getCord(1).y);
				tetronimo.setCord(2, tetronimo.getCord(2).x + 1, tetronimo.getCord(2).y);
				tetronimo.setCord(3, tetronimo.getCord(3).x + 1, tetronimo.getCord(3).y);
				tetronimo.setCord(4, tetronimo.getCord(4).x + 1, tetronimo.getCord(4).y);

			}
		}
	}

	if (!(tetronimo.getCord(1).x == 0 || tetronimo.getCord(2).x == 0
		|| tetronimo.getCord(3).x == 0 || tetronimo.getCord(4).x == 0)) {

		if (!(grid[tetronimo.getCord(1).y][tetronimo.getCord(1).x - 1] == 2 ||
			grid[tetronimo.getCord(2).y][tetronimo.getCord(2).x - 1] == 2 ||
			grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x - 1] == 2 ||
			grid[tetronimo.getCord(4).y][tetronimo.getCord(4).x - 1] == 2)) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			tetronimo.setCord(1, tetronimo.getCord(1).x - 1, tetronimo.getCord(1).y);
			tetronimo.setCord(2, tetronimo.getCord(2).x - 1, tetronimo.getCord(2).y);
			tetronimo.setCord(3, tetronimo.getCord(3).x - 1, tetronimo.getCord(3).y);
			tetronimo.setCord(4, tetronimo.getCord(4).x - 1, tetronimo.getCord(4).y);
		}
	}
	}

	
}


void Grid::checkRows()
{
	bool clear = true;

	for (int i = 0; i < 20; i++) {
		clear = true;
		for (int j = 0; j < 10;j++) {
			if (grid[i][j] == 0) {
				clear = false;
			}
		}

		if (clear) {
			score.addScore(10);
			clearRow(i);
			dropDownRow(i);
		}
	}

}

void Grid::clearRow(int row)
{

	for (int i = 0; i < 10; i++) {
		grid[row][i] = 0;
	}

}

void Grid::dropDownRow(int row)
{

	for (int i = row-1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] == 2) {
				grid[i][j] = 0;
				grid[i + 1][j] = 2;
			}

		}
	
	}


}

void Grid::rotate()
{
	int kick = 1;

	if (type == I_SHAPE) {
		kick = 2;
	}

	if (tetronimo.getCord(3).x == 9) {

		tetronimo.setCord(1, tetronimo.getCord(1).x - kick, tetronimo.getCord(1).y);
		tetronimo.setCord(2, tetronimo.getCord(2).x - kick, tetronimo.getCord(2).y);
		tetronimo.setCord(3, tetronimo.getCord(3).x - kick, tetronimo.getCord(3).y);
		tetronimo.setCord(4, tetronimo.getCord(4).x - kick, tetronimo.getCord(4).y);


	}

	if (tetronimo.getCord(3).x == 0) {
		tetronimo.setCord(1, tetronimo.getCord(1).x + kick, tetronimo.getCord(1).y);
		tetronimo.setCord(2, tetronimo.getCord(2).x + kick, tetronimo.getCord(2).y);
		tetronimo.setCord(3, tetronimo.getCord(3).x + kick, tetronimo.getCord(3).y);
		tetronimo.setCord(4, tetronimo.getCord(4).x + kick, tetronimo.getCord(4).y);
	}


	if (!(grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x + 1] == 2
		|| grid[tetronimo.getCord(3).y][tetronimo.getCord(3).x - 1 ] == 2)) {
		tetronimo.rotateTetronimo();
	}
	

}

void Grid::updateGhost()
{
	
}

void Grid::gameOver()
{


}
