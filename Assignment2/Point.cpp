#include "pch.h"
#include "Shape.h"
class Point {
private:
	std::string type;
	float * coord;
	int counter;
public:
	
	 Point(float * floatArray, int counter) {
		
		this->counter = counter;
		coord = floatArray;
		type = "point";
		std::copy(floatArray, floatArray + counter, coord);
	}

	 void operator=(const Point &p)
	 {
		 this->coord = p.coord;
		 this->counter = p.counter;
		

	 }
	std::string getType() {
		return type;
	}


	float area() {
		return -1;
	}




	float circumference() {
		return 0;
	}



	float * position() {
		std::cout << "Center x is: " << coord[0] << " Center y is: " << coord[1] << "\n";
		return coord;
	}



	bool isConvex() {
		return true;
	}


	float distance(Shape *s) {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * coord[0]) - (sCoord[1] * coord[1]));
	}
};