#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student {
private:
	int _id;
	string _firstName;
	string _secondName;
	bool _floor;
	int _age;
public:
	string ToString();
	int GetId();
	string GetFirstName();
	string GetSecondName();
	bool GetFloor();
	int GetAge();
	Student();
	Student(int id, string firstName, string secondName, bool floor, int age);
	~Student();
	void SetFirstName(string firstName);
	void SetSecondName(string secondName);
	void SetFloor(bool floor);
	void SetAge(int age);
};
