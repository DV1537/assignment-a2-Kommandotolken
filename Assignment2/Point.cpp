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


	std::string getType() const {
		return type;
	}


	float area() const {
		return -1;
	}




	float circumference() const {
		return 0;
	}



	float * position() const{
		std::cout << "Center x is: " << coord[0] << " Center y is: " << coord[1] << "\n";
		return coord;
	}



	bool isConvex() const {
		return true;
	}


	float distance(Shape *s) const {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * coord[0]) - (sCoord[1] * coord[1]));
	}
};