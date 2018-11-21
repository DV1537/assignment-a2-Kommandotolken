#include "pch.h"
#include "Functions.h"

class Shape{
private:
	float * coord;
	std::string type;
	
public:

	Shape() {
		type = "N/A";
		
	}

	Shape( std::string type) {
		this->type = type;
	
	}
	
	
	float area() {


	}

	float circumference() {

	}

	float *position() {

	}

	bool isConvex() {

	}

	float distance(Shape *s) {
		

	}


};