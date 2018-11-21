#include "pch.h"
#include "Functions.h"
#include "Triangle.cpp"


int main(int argc, const char * argv[])
{
	
	
	int startingSize = 100;
	int capacity = startingSize;
	float * floatArray = new float[startingSize];
	float * floatArray2;
	float a;
	int counter = 0;
	if (argc < 2)
	{
		std::cout << "You forgot to enter a filename.";
		return 1;
	}
	std::ifstream myInputFile;
	char fileName[30];
	strcpy_s(fileName, argv[1]);
	myInputFile.open(fileName);

	if (myInputFile.fail())
	{
		std::cout << "There was an error opening the file.";
		return 1;
	}
	while (myInputFile >> a)
	{
		if (counter >= capacity)
		{
			
			floatArray2 =  new float[capacity * 2];
			std::copy(floatArray, floatArray + capacity, floatArray2);

			delete[] floatArray;

			
			floatArray = floatArray2;
			capacity *= 2;
			
		}
		floatArray[counter] = a;
		

		counter++;
	}

	if (counter == 6)
	{
		Triangle triangle(floatArray, counter);
		std::cout << "This is a: " << triangle.getType() << "\n";
		triangle.area();
		triangle.circumference();
		triangle.position();

	}

	/*
	for (int i = 0; i < counter; i++)
	{
		if (i % 2 == 0)
		{
			x = floatArray[i];
			std::cout << "x is " << x;
		}
		else if (i % 2 != 0)
		{
			y = floatArray[i];
			std::cout << "y is " << y;
		}
	}
	*/
	
	
}
