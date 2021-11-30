#include "Student.h"

Student::Student() { // Constructor default
	_id = 0;
	_firstName = "";
	_secondName = "";
	_floor = 0;
	_age = 18;
}
Student::Student(int id, string firstName, string secondName, bool floor, int age) { // Constructor with parameters
	_id = id;
	_firstName = firstName;
	_secondName = secondName;
	_floor = floor;
	_age = age;
}

Student::~Student() // Destructor
{
	cout << "The Student destroyed: " << GetFirstName() << endl;
}

string Student::ToString() // Get Format string
{
	stringstream ss; 
	ss <<
		"-------------------------------\n" <<
		"Id: " << to_string(_id) << "\n" <<
		"First name: " << _firstName << "\n" <<
		"Second name: " << _secondName << '\n' <<
		"Floor: " << to_string(_floor) << "\n" <<
		"Age: " << to_string(_age) << "\n" <<
		"-------------------------------\n";
	return ss.str();
}

int Student::GetId()
{
	return _id;
}

string Student::GetFirstName()
{
	return _firstName;
}

string Student::GetSecondName()
{
	return _secondName;
}

bool Student::GetFloor()
{
	return _floor;
}

int Student::GetAge()
{
	return _age;
}

void Student::SetFirstName(string firstName)
{
	_firstName = firstName;
}

void Student::SetSecondName(string secondName)
{
	_secondName = secondName;
}

void Student::SetFloor(bool floor)
{
	_floor = floor;
}

void Student::SetAge(int age)
{
	_age = age;
}
