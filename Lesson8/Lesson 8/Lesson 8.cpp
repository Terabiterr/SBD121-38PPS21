#include <iostream>
#include "Figure.h"
#include "Figure.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Square.h"
#include "Square.cpp"
#include "Triangle.h"
#include "Triangle.cpp"

using namespace std;

void main()
{
	cout << "-------------------------------------" << endl;
	cout << "-------------Rectangle---------------" << endl;
	cout << "-------------------------------------" << endl;
	Rectangle<double> rectangle(5.0, 10.0);
	cout << "Area:\t" << rectangle.Area() << endl;
	cout << "-------------------------------------" << endl;
	cout << "---------------square----------------" << endl;
	cout << "-------------------------------------" << endl;
	Square<float> square(15, 15);
	cout << "Area:\t" << square.Area() << endl;
	cout << "-------------------------------------" << endl;
	cout << "---------------triangle--------------" << endl;
	cout << "-------------------------------------" << endl;
	Triangle<float> triangle(15, 25);
	cout << "Area:\t" << triangle.Area() << endl;
}