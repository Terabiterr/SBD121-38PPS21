#include <iostream>
#include <string>
using namespace std;

template<class T>
void ShowStudent(T& name)
{
	cout << "name:\t" << name << endl;
}

void ShowStudent(string name, string lastName)
{
	cout << "name:\t" << name + "\t" << "lastName:\t" << lastName << endl;
}

void ShowStudent(int id, string name, string lastName)
{
	cout << "id:\t" << to_string(id) + "\t" << "name:\t" << name + "\t" << "lastName:\t" << lastName << endl;
}

void main()
{
	ShowStudent("Bob");
	ShowStudent("Bob", "Bobexes");
	ShowStudent(1, "Bob", "Bobexes");
}
