#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "pch.h"
#include "Functions.h"
#include "Shape.h"
class Triangle : public Shape {
private:
	float * coord;
	const std::string type = "Triangle";
	float centerCoord[2];
	int counter;

	float xCoord[3];
	float yCoord[3];

public:
	Triangle(float * floatArray, int counter);
	float area();
	float circumference() const;

	float * position();

	float distance(Shape *s) const;
	
	bool isConvex() const;

	std::string getType() const;
};

#endif TRIANGLE_H