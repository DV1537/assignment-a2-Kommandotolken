
#include "pch.h"
#include "Functions.h"
#include "Line.h"
#include "Point.h"
#include "Polygon.h"
#include "Triangle.h"

int main(int argc, const char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	float centerCoordinates[2];
	const int startingSize = 100;
	int capacity = startingSize;
	
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
	char c;
	while (myInputFile >> c)
	{
		if (!(isdigit(c)))
		{
			std::cout << "Wrong data";
			return 1;
		}
	}

	float * floatArray = new float[startingSize];
	float * floatArray2 = nullptr;
	myInputFile.clear();
	myInputFile.seekg(0, std::ios::beg);
	while (myInputFile >> a)
	{

	
		if (counter >= capacity)
		{

			floatArray2 = new float[capacity * 2];
			std::copy(floatArray, floatArray + capacity, floatArray2);

			delete[] floatArray;


			floatArray = floatArray2;
			capacity *= 2;

		}
		floatArray[counter] = a;


		counter++;
	}
	if (counter % 2 != 0)
	{
		std::cout << "You missed a coordinate";
		return 1;
	}
	if (counter == 2)
	{
		Point point(floatArray, counter);
		std::cout.precision(4);
		std::cout << "The type is: " << point.getType() << "\n";
		std::cout << "The area is: " << point.area() << "\n";
		std::cout << "The circumference is: " << point.circumference() << "\n";
		std::cout << "The center coordinate is: " << point.position()[0] << " And " << point.position()[1] << "\n";
	}
	if (counter == 4)
	{
		Line line(floatArray, counter);
		std::cout.precision(3);
		std::cout << "The type is: " << line.getType() << "\n";
		std::cout << "The area is: " << line.area() << "\n";
		std::cout << "The circumference is: " << line.circumference() << "\n";
		std::cout << "The center coordinate is: " << line.position()[0] << " And " << line.position()[1] << "\n";

		//Implement distance
	}
	if (counter == 6)
	{

		Triangle triangle(floatArray, counter);
		std::cout.precision(4);
		std::cout << "The type is: " << triangle.getType() << "\n";
		std::cout << "The area is: " << triangle.area() << "\n";
		std::cout << "The circumference is: " << triangle.circumference() << "\n";
		std::cout << "The center coordinate is: " << triangle.position()[0] << " And " << triangle.position()[1] << "\n";


	}
	if (counter >= 8)
	{
		
		Polygon poly(floatArray, counter);
		
		std::cout.precision(4);
		std::cout << "The type is: " << poly.getType() << "\n";
		std::cout << "The area is: " << poly.area() << "\n";
		std::cout << "The circumference is: " << poly.circumference() << "\n";
		std::cout << "The center coordinate is: " << poly.position()[0] << " and " << poly.position()[1] << "\n";
		std::cout << "Distance : " << poly.distance(&poly);
	}

	delete[] floatArray;

}
