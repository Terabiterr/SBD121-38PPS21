#include "Point.h"

Point::Point(const Point &other) // Constructor copy
{
	this->count = other.count;
	cout << "Constructor copy: " << this << endl;
	this->points = new Point[this->count];
	for (int i = 0; i < other.count; i++)
	{
		this->points[i].x = other.points[i].x;
		this->points[i].y = other.points[i].y;
	}
}

Point::Point() // default
{
	x = 0;
	y = 0;
	points = NULL;
	count = 0;
	cout << "Constructor default:\t" << this << endl;
}

Point::Point(double x, double y) // constructor params
{
	this->x = x;
	this->y = y;
	points = NULL;
	count = 0;
	cout << "Constructor x, y:\t" << this << endl;
}

Point::Point(int count) // constructor array
{
	x = 0;
	y = 0;
	points = new Point[count];
	cout << "Constructor --->>> create dynamic array:\t" << this << endl;
}

Point::~Point()
{
	this_thread::sleep_for(chrono::milliseconds(500)); // 1 second block thread
	cout << "Point::~Point() {\t" << "x:\t" << x << "\ty:\t" << y << "\t" << this << "\a\t}" << endl;
	delete[] points;
}

double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;
}

int Point::GetCount()
{
	return 0;
}

Point * Point::GetPoints()
{
	return points;
}

void Point::SetX(double x)
{
	this->x = x;
}

void Point::SetY(double y)
{
	this->y = y;
}

string Point::ToString()
{
	stringstream ss;
	ss <<
		"-------------------------------\n" <<
		"x:\t" << x << "\n" <<
		"y:\t" << y << "\n" <<
		"-------------------------------\n";
	return ss.str();
}
