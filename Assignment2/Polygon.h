#include "pch.h"
#include "Functions.h"
#include "Shape.h"
#ifndef POLYGON_H
#define POLYGON_H
class Polygon : public Shape {
private:

	float * coord;
	const std::string type = "Polygon";
	float polyArea;

	bool isConv;
	int counter;
	int numOfSides;
	float centerCoord[2];
	float * xCoord;
	float  * yCoord;


public:

	~Polygon();

		Polygon(float * floatArray, int counter);
		float area();

		float circumference() const;



		float *position();
		bool isConvex() const;



		bool isIntersect() const;
		float distance(Shape *s) const;

		std::string getType() const;
	
}; 

#endif POLYGON_H