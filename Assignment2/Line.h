#ifndef LINE_H
#define LINE_H
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
	~Line();

		Line(float * floatArray, int counter);



		std::string getType() const;


		float area() const;


		float circumference() const;


		float * position();


		bool isConvex() const;

		float distance(Shape *s) const;


};
#endif LINE_H