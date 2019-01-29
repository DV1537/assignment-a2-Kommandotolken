#include "pch.h"
#include "Functions.h"
#include "Shape.h"
class Line {
private:
	int counter;
	float * coord;
	const std::string type = "Line";
	float centerPos[2];
public:
	~Line() {
		delete[] coord;
		
	}

	Line(float * floatArray, int counter)
	{
		
		this->counter = counter;
		coord = new float[counter];
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



	float * position() {
		
		float centerX = (coord[2] - coord[0]) / 2;
		float centerY = (coord[3] - coord[1]) / 2;
		
		centerPos[0] = centerX;
		centerPos[1] = centerY;
		return centerPos;

	}



	bool isConvex() const {
		return false;
	}



	float distance(Shape *s) const {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerPos[0]) - (sCoord[1] * centerPos[1]));
		std::cout << "Distance is" << d << "\n";
		delete sCoord;
		return d;
	}


};