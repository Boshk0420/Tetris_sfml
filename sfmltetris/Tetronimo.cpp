#include "Tetronimo.h"

Tetronimo::Tetronimo() {

	/* tetronimo.shapeCord[1] = sf::Vector2i(5, 0);
	tetronimo.shapeCord[2] = sf::Vector2i(5, 1);
	tetronimo.shapeCord[3] = sf::Vector2i(5, 2);
	tetronimo.shapeCord[4] = sf::Vector2i(5, 3);
	tetronimo.type = I_SHAPE;
	*/

	 newTetronimo();

}

void Tetronimo::setCord(int i, int x, int y)
{
	tetronimo.shapeCord[i] = sf::Vector2i(x,y);
}

sf::Vector2i Tetronimo::getCord(int i) {
	return tetronimo.shapeCord[i];
}

ShapeType Tetronimo::newTetronimo()
{

	std::uniform_int_distribution<int> range(0, 6);
	eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
	
	

	int shTp = range(eng);


	switch (shTp) {
	
	case 0:
		tetronimo.shapeCord[1] = sf::Vector2i(4, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(5, 0);
		tetronimo.shapeCord[3] = sf::Vector2i(6, 0);
		tetronimo.shapeCord[4] = sf::Vector2i(7, 0);
		tetronimo.type = I_SHAPE;
		return I_SHAPE;

	case 1:
		tetronimo.shapeCord[1] = sf::Vector2i(5, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(6, 0);
		tetronimo.shapeCord[3] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(6, 1);
		tetronimo.type = CUBE_SHAPE;
		return CUBE_SHAPE;

	case 2:
		tetronimo.shapeCord[1] = sf::Vector2i(5, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(6, 1);
		tetronimo.shapeCord[3] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(4, 1);
		tetronimo.type = T_SHAPE;
		return T_SHAPE;

	case 3:
		tetronimo.shapeCord[1] = sf::Vector2i(6, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(6, 1);
		tetronimo.shapeCord[3] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(4, 1);
		tetronimo.type = L_SHAPE;
		return L_SHAPE;

	case 4:
		tetronimo.shapeCord[1] = sf::Vector2i(4, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(4, 1);
		tetronimo.shapeCord[3] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(6, 1);
		tetronimo.type = L_SHAPE_INVERSE;
		return L_SHAPE_INVERSE;

	case 5:
		tetronimo.shapeCord[1] = sf::Vector2i(5, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[3] = sf::Vector2i(6, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(6, 2);
		tetronimo.type = S_SHAPE;
		return S_SHAPE;

	case 6:
		tetronimo.shapeCord[1] = sf::Vector2i(5, 0);
		tetronimo.shapeCord[2] = sf::Vector2i(4, 1);
		tetronimo.shapeCord[3] = sf::Vector2i(5, 1);
		tetronimo.shapeCord[4] = sf::Vector2i(4, 2);
		tetronimo.type = S_SHAPE_INVERSE;
		return S_SHAPE_INVERSE;
		
	
	
	}

	

}

void Tetronimo::rotateTetronimo() {
	


// just need to translate pieces 1 2 and 4, 3 will be the center 

	int x_t = tetronimo.shapeCord[3].x; // the amount we have to trnslate for x
	int y_t = tetronimo.shapeCord[3].y; // the amount we have to translate for y 


	tetronimo.shapeCord[1].x = (tetronimo.shapeCord[1].x - x_t);
	tetronimo.shapeCord[1].y = (tetronimo.shapeCord[1].y - y_t)*(-1);

	// x_new = -y_old and y_new = x_old

	tetronimo.shapeCord[1] =
		sf::Vector2i(-tetronimo.shapeCord[1].y,tetronimo.shapeCord[1].x);

	tetronimo.shapeCord[1].y *= -1;

	tetronimo.shapeCord[1].x = tetronimo.shapeCord[1].x + x_t;
	tetronimo.shapeCord[1].y = tetronimo.shapeCord[1].y + y_t;


	///////////////

	tetronimo.shapeCord[2].x = (tetronimo.shapeCord[2].x - x_t);
	tetronimo.shapeCord[2].y = (tetronimo.shapeCord[2].y - y_t) * (-1);


	tetronimo.shapeCord[2] =
		sf::Vector2i(-tetronimo.shapeCord[2].y, tetronimo.shapeCord[2].x);

	tetronimo.shapeCord[2].y *= -1;

	tetronimo.shapeCord[2].x = tetronimo.shapeCord[2].x + x_t;
	tetronimo.shapeCord[2].y = tetronimo.shapeCord[2].y + y_t;

	///////////////////

	tetronimo.shapeCord[4].x = (tetronimo.shapeCord[4].x - x_t);
	tetronimo.shapeCord[4].y = (tetronimo.shapeCord[4].y - y_t) * (-1);


	tetronimo.shapeCord[4] =
		sf::Vector2i(-tetronimo.shapeCord[4].y, tetronimo.shapeCord[4].x);

	tetronimo.shapeCord[4].y *= -1;

	tetronimo.shapeCord[4].x = tetronimo.shapeCord[4].x + x_t;
	tetronimo.shapeCord[4].y = tetronimo.shapeCord[4].y + y_t;







}
