#ifndef SHAPE_H
#define SHAPE_H
#include "Functions.h"

class Shape {
private:
	float * coord;
	std::string type;
	

public:
	
	//Shape(float *,int );
	
	//virtual void operator=(const Shape &s) = 0;
	//virtual void operator+(const Shape &s) = 0 ;
	//virtual void operator<<(const Shape &s) = 0;
	 virtual float area() = 0;


	 virtual std::string getType() = 0;

	 virtual float circumference() = 0;



	virtual float *position() = 0;



	virtual bool isConvex() = 0;



	virtual float distance(Shape *s) = 0;


	

};

#endif SHAPE_H