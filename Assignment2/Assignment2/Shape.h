#ifndef SHAPE_H
#define SHAPE_H
#include "Functions.h"

class Shape {
private:
	float * coord;
	std::string type;
	

public:
	virtual std::string getType() = 0;


	float area();




	float circumference();



	float *position();



	bool isConvex();



	float distance(Shape *s);




};

#endif SHAPE_H