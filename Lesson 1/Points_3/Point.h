#pragma once
#include <iostream>
#include <sstream>
#include <chrono> // Sleep
#include <thread> // Sleep
using namespace std;
class Point
{
private:
	double x = 0;
	double y = 0;
	int count = 0;
	Point * points;
public:
	Point(const Point& other);
	Point();
	Point(double x, double y);
	Point(int count);
	~Point();
	double GetX();
	double GetY();
	int GetCount();
	Point * GetPoints();
	void SetX(double x);
	void SetY(double y);
	string ToString();
};