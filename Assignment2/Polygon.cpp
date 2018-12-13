#include "pch.h"
#include "Functions.h"
#include "Shape.h"

class Polygon : public Shape {
private:
	
	float * coord;
	std::string type;
	float polyArea;

	bool isConv;
	int counter;
	int numOfSides;
	float centerCoord[2];
	float * xCoord;
	float  * yCoord;


public:

	~Polygon()
	{
		delete[] coord;
		delete[] xCoord;
		delete[] yCoord;
	}

	Polygon(float * floatArray, int counter) {
		this->counter = counter;
		type = "polygon";
		numOfSides = counter / 2;
		coord = floatArray;
		std::copy(floatArray, floatArray + counter, coord);
		this->xCoord = new float[numOfSides];
		this->yCoord = new float[numOfSides];
		
	}
	float area() {
		
		bool isInter;
		int j = 0;
		int k = 0;
		
		for (int i = 0; i < counter; i++)
		{

			if (i % 2 == 0)
			{
				xCoord[j] = coord[i];
		
				j++;

			}
			else if (i % 2 != 0)
			{

				yCoord[k] = coord[i];
			
				k++;

			}
			
			
		} 
		int l = numOfSides - 1;
		for (int n = 0; n < numOfSides; n++)
			{
				polyArea += (xCoord[l] + xCoord[n]) * (yCoord[l] - yCoord[n]);
				l = n;
			} 
		polyArea = abs(polyArea / 2);
		isConv = isConvex();
		isInter = isIntersect();
		if (polyArea == 0 || isConv == false || isInter== true)
		{
			return -1;
		}
		else
		return polyArea;
	}




	float circumference() const {
		float polyCircumference = 0;
		int l = numOfSides - 1;
		for (int n = 0; n < numOfSides; n++)
		{
			
			polyCircumference += sqrt(pow(xCoord[n] - xCoord[l], 2) + pow(yCoord[n] - yCoord[l], 2));
			l = n;
		}
		polyCircumference = polyCircumference;
		return polyCircumference;
	}



	float *position() {
		
		float centerX = 0;
		float centerY = 0;
		if (isConv == false)
		{
			
			float xHighest = xCoord[0];
			float yHighest = yCoord[0];
			float xLowest = xCoord[0];
			float yLowest = yCoord[0];
			for (int n = 0; n < numOfSides; n++)
			{
				if (xCoord[n] < xLowest)
					xLowest = xCoord[n];
				if (yCoord[n] < yLowest)
					yLowest = yCoord[n];
				if (yCoord[n] > yHighest)
					yHighest = yCoord[n];
				if (xCoord[n] > xHighest)
					xHighest = xCoord[n];
			}

			float dy = yHighest - yLowest;
			float dx = xHighest - xLowest;
			centerCoord[0] = dx / 2;
			centerCoord[1] = dy / 2;
		}
		else
		{
			for (int n = 0; n < numOfSides; n++)
			{
				centerY += yCoord[n];
				centerX += xCoord[n];
			}
			centerX /= 2;
			centerY /= 2;
			centerCoord[0] = centerX;
			centerCoord[1] = centerY;
		}
		return centerCoord;
	}



	bool isConvex() const{
		bool isConv = false;

		//Kolla vinkeln arctan dy/dx och spara den i en temporär variabel. Kolla arctan dy+1/dx+1 och kolla den är mindre än föregående, om den är större så är den konkav.
		float dy;
		float dx;
		float angle;
		float m = 0;

		//If convex it can not self intersect
		for (int n = 0; n < numOfSides; n++)
		{
		
			
				dx = xCoord[n + 2 % numOfSides] - xCoord[n + 1 % numOfSides];
				dy = yCoord[n + 2 % numOfSides] - yCoord[n + 1 % numOfSides];
				
				angle = abs(atan(dy / dx) * 100);

				if (angle > 180)
				{
					isConv = false;
					return isConv;
				}
				else
					isConv = true;
			}
			//dx = ;
			//
			//angle = abs(atan(dy / dx) * 100);


	
		return isConv;
	}


		
		
	
		

	bool isIntersect() const{
		float dy;
		float dx;
		float interiorAngle = 0;
		float exteriorAngle = 0;
	
		
		for (int n = 0; n < numOfSides-1; n++)
		{
			//dx = xCoord[n + 1 % numOfSides] - xCoord[n];
			//dy = yCoord[n + 1 % numOfSides] - yCoord[n];
		
			dx = xCoord[n + 2 % numOfSides] - xCoord[n + 1 % numOfSides];
			dy = yCoord[n + 2 % numOfSides] - yCoord[n + 1 % numOfSides];
			interiorAngle = atan(dy / dx) * 100;
			exteriorAngle += (180 - abs(interiorAngle));
		}
		if (exteriorAngle > 360)
		{
			return true;
		}
		else
			return false;
	}

	float distance(Shape *s) const {
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerCoord[0]) - (sCoord[1] * centerCoord[1]));
		
		//std::cout << "Distance is" << d << "\n";
		return d;
	}

	std::string getType() const
	{
		return type;
	}
};