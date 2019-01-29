#include "pch.h"
#include "Functions.h"
#include "Point.h"

	
	 Point::Point(float * floatArray, int counter) {
		
		this->counter = counter;
		coord = floatArray;
		
		std::copy(floatArray, floatArray + counter, coord);
	}


	std::string Point::getType() const {
		return type;
	}


	float Point::area() const {
		return -1;
	}




	float Point::circumference() const {
		return 0;
	}



	float * Point::position() const{
		std::cout << "Center x is: " << coord[0] << " Center y is: " << coord[1] << "\n";
		return coord;
	}



	bool Point::isConvex() const {
		return true;
	}


	float Point::distance(Shape *s) const {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * coord[0]) - (sCoord[1] * coord[1]));
		return d;
	}
	