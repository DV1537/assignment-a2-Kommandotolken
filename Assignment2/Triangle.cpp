#include "pch.h"
#include "Functions.h"
#include "Shape.h"
#include "Triangle.h"

	Triangle::Triangle(float * floatArray, int counter) {
		this->counter = counter;
		coord = floatArray;
		
		std::copy(floatArray, floatArray + counter, coord);
		
		
		
	}

	float Triangle::area() {

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
		float triArea = 0;

		
		triArea = abs((xCoord[0] * (yCoord[1] - yCoord[2]) + xCoord[1] * (yCoord[2] - yCoord[0]) + xCoord[2] * (yCoord[1] - yCoord[0])))/2;
	
		
			if (triArea == 0 )
			{
				return -1;
			}
			else
		return triArea;

	}


	float Triangle::circumference() const{
		float triCircumference = 0;
		int l = 2;
		for (int n = 0; n < 3; n++)
		{

			triCircumference += sqrt(pow(xCoord[l] - xCoord[n], 2) + pow(yCoord[l] - yCoord[n], 2));
			l = n;
		}
		
		std::cout << "Circumference of the triangle is: " << triCircumference << "\n";
		return triCircumference;
	}

	float * Triangle::position() {
		float centerX;
		float centerY;
		
		centerX = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
		centerY = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;
		centerCoord[0] = centerX;
		centerCoord[1] = centerY;
		
		return centerCoord;
	}

	float Triangle::distance(Shape *s) const
	{
		
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerCoord[0]) - (sCoord[1] * centerCoord[1]));
		std::cout << "Distance is" << d << "\n";
		return d;
	}

	bool Triangle::isConvex() const{
		return true;
	}

	std::string Triangle::getType() const {
		return type;
	}
