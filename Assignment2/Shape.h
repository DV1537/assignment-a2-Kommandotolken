#ifndef SHAPE_H
#define SHAPE_H
#include "Functions.h"

class Shape {
private:
	float * coord;
	std::string type;
	

public:
	
	
	 virtual float area() = 0;


	 virtual std::string getType () const = 0;

	 virtual float circumference() const = 0;



	virtual float *position() = 0;



	virtual bool isConvex() const = 0;



	virtual float distance(Shape *s) const = 0;


	

};

#endif SHAPE_H