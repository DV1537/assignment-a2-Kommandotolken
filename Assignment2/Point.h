#pragma once
#ifndef POINT_H
#define POINT_H
#include "pch.h"
#include "Shape.h"
class Point {
private:
	const std::string type = "Point";
	float * coord;
	int counter;
public:

	Point(float * floatArray, int counter);
		std::string getType() const;

		float area() const;
		float circumference() const;


		float * position() const;


		bool isConvex() const;
		float distance(Shape *s) const;
};

#endif POINT_H