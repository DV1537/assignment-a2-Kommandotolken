#include "pch.h"
#include "Functions.h"
#include "Line.h"

	Line::~Line() {
		delete[] coord;
		
	}

	Line::Line(float * floatArray, int counter)
	{
		
		this->counter = counter;
		coord = new float[counter];
		std::copy(floatArray, floatArray + counter, coord);
	}

	
	std::string Line::getType() const {
		return type;
	}


	float Line::area() const {
		return -1;
	}




	float Line::circumference() const {
		return 0;
	}



	float * Line::position() {
		
		float centerX = (coord[2] - coord[0]) / 2;
		float centerY = (coord[3] - coord[1]) / 2;
		
		centerPos[0] = centerX;
		centerPos[1] = centerY;
		return centerPos;

	}



	bool Line::isConvex() const {
		return false;
	}



	float Line::distance(Shape *s) const {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerPos[0]) - (sCoord[1] * centerPos[1]));
		std::cout << "Distance is" << d << "\n";
		delete sCoord;
		return d;
	}

