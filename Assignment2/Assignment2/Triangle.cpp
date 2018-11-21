#include "pch.h"
#include "Functions.h"
#include "shape.cpp"

class Triangle : public Shape {
private:
	float * coord;
	std::string type = "triangle";
	float * centerCoord;
	int counter;
	
	float xCoord[3];
	float yCoord[3];
	
public:
	Triangle(float * floatArray, int counter) {
		this->counter = counter;
		coord = floatArray;
		
		std::copy(floatArray, floatArray + counter, coord);
		
		
		
	}

	float area() {
		int j = 0;
		int k = 0;
		
		for (int i = 0; i < counter; i++)
		{
			
			if (i % 2 == 0)
			{
				xCoord[j] = coord[i];
				//std::cout << xCoord[j] << "x \n";
				j++;
				
			}
			else if (i % 2 != 0)
			{

				yCoord[k] = coord[i];
				//std::cout << yCoord[k] << "y \n";
				k++;
				
			}
		}
		float triArea = 0;
		triArea = abs((xCoord[0] * (yCoord[1] - yCoord[2]) + xCoord[1] * (yCoord[2] - yCoord[0]) + xCoord[2] * (yCoord[1] - yCoord[0])))/2;
	
			std::cout << "Area of the triangle is: " << triArea << "\n";
	
		return triArea;

	}


	float circumference() {
		float triCircumference = 0;
		triCircumference = xCoord[0] + xCoord[2] + yCoord[0] + yCoord[1];
		std::cout << "Circumference of the triangle is: " << triCircumference << "\n";
		return triCircumference;
	}

	float * position() {
		float centerX;
		float centerY;
		
		centerX = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
		centerY = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;
		centerCoord[0] = centerX;
		centerCoord[1] = centerY;
		std::cout << "Center x is : " << centerCoord[0] << " And center y is: " << centerCoord[1] << "\n";
		return centerCoord;
	}

	float distance(Shape *s)
	{
		
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerCoord[0]) - (sCoord[1] * centerCoord[1]));
		return d;
	}

	std::string getType() {
		return type;
	}
};