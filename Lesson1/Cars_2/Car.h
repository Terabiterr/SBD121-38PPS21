#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Car
{
private:
	string model;
	string color;
	int speed;
public:
	Car();
	Car(string model, string color, int speed);
	~Car();
	string ToString();
	string GetModel();
	string GetColor();
	int GetSpeed();
	void SetModel(string model);
	void SetColor(string color);
	void SetSpeed(int speed);
	bool Equal(Car car);
};

