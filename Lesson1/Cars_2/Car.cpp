#include "Car.h"

Car::Car()
{
	model = "";
	color = "";
	speed = 0;
}

Car::Car(string model, string color, int speed) {
	this->model = model;
	this->color = color;
	this->speed = speed;
}
Car::~Car() {
	cout << "The car destroyed:\t" << GetModel() << "\t" << this << endl;
}

string Car::GetModel()
{
    return model;
}

string Car::GetColor()
{
    return color;
}

int Car::GetSpeed()
{
    return speed;
}

void Car::SetModel(string model)
{
    this->model = model;
}

void Car::SetColor(string color)
{
    this->color = color;
}

void Car::SetSpeed(int speed)
{
    this->speed = speed;
}

bool Car::Equal(Car car)
{
	if (this->model == car.model && this->color == car.color && this->speed == car.speed) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Car::ToString()
{
	stringstream ss;
	ss <<
		"-------------------------------\n" <<
		"model:\t" << model << "\n" <<
		"color:\t" << color << "\n" <<
		"speed:\t" << to_string(speed) << "\n" <<
		"-------------------------------\n";
	return ss.str();
}
