#include "pch.h"
#include "Functions.h"
#include "shape.h"

class Triangle : public Shape {
private:
	float * coord;
	std::string type = "triangle";
	float centerCoord[2];
	int counter;
	
	float xCoord[3];
	float yCoord[3];
	
public:
	Triangle(float * floatArray, int counter) {
		this->counter = counter;
		coord = floatArray;
		
		std::copy(floatArray, floatArray + counter, coord);
		
		
		
	}

	void operator=(const Triangle &t)
	{
		this->coord = t.coord;
		this->counter = t.counter;
		
	}
	
	void operator+(float points[2])
	{
		float * extraCoords = new float[counter + 2];
		std::copy(coord, coord + (counter + 2), extraCoords);
		//Hämta float * med coords. Hitta slutet på den. Mata in points efter den
		counter += 2;
		delete[] coord;
		coord = extraCoords;
	}
	void operator<<(const Triangle &t) {
		//
	}
	float area() {

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


	float circumference() {
		float triCircumference = 0;
		triCircumference = (xCoord[2] - xCoord[0]) + (yCoord[2] - yCoord[0]) + (sqrt(pow(xCoord[2] - xCoord[0], 2) - pow(yCoord[2] - yCoord[0], 2)));
		
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
		
		return centerCoord;
	}

	float distance(Shape *s)
	{
		
		float * sCoord = s->position() + 0;
		float d = sqrt((sCoord[0] * centerCoord[0]) - (sCoord[1] * centerCoord[1]));
		std::cout << "Distance is" << d << "\n";
		return d;
	}

	bool isConvex() {
		return true;
	}

	std::string getType() {
		return type;
	}
};