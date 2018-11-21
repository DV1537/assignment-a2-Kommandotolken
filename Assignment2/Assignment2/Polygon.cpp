#include "pch.h"
#include "Functions.h"
#include "Shape.cpp"

class Polygon : public Shape {
private:
	float * coord;
	std::string type = "polygon";
	float polyArea;
	int counter;
	int numOfSides;
	float xCoord[1];
	float yCoord[1];

public:
	Polygon(float * floatArray, int counter) {
		this->counter = counter;
		numOfSides = counter / 2;
		coord = floatArray;
		std::copy(floatArray, floatArray + counter, coord);

	}
	float area() {
		
		int j = 0;
		int k = 0;
		
		for (int i = 0; i < counter; i++)
		{

			if (i % 2 == 0)
			{
				xCoord[j] = coord[i];
				//std::cout << xCoord[j] << "x \n";
				j++;

			}
			else if (i % 2 != 0)
			{

				yCoord[k] = coord[i];
				//std::cout << yCoord[k] << "y \n";
				k++;

			}
			//((x1 * y2)-(y1 * x2 ) + (x2 * y3)-(y2 * x3)) (xn y1 - yn x1) osv /2
			for (int n = 0; n < counter; n++)
			{
				polyArea = abs((xCoord[n] * yCoord[n + 1]) - (yCoord[n] * xCoord[n + 1]))/2;
			}
		}
		
	}




	int circumference() {

	}



	int position() {

	}



	bool isConvex() {

	}



	int distance(Shape *s) {

	}


};