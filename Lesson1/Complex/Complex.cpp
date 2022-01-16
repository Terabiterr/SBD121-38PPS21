#include <iostream>
#include <sstream>
using namespace std;

class Complex
{
public:
	Complex() // Constructor default
	{
		cout << "Constructor default:\t" << this << endl;
		x = 0;
		y = 0;
	}
	Complex(int x, int y) : x(x), y(y) // Constructor with parametrs
	{
		cout << "Constructor:\t" << this << endl;
	}
	~Complex() // Destructor
	{
		cout << "Destructor:\t" << this << endl;
	}
	string ToString() {
		stringstream ss;
		ss <<
			"-------------------------------\n" <<
			"x:\t" << x << "\n" <<
			"y:\t" << y << "\n" <<
			"-------------------------------\n";
		return ss.str();
	}
private:
	int x, y;
};

int main()
{
	Complex complex(52, 55);
	Complex complex2;
	cout << complex.ToString() << endl;
	cout << complex2.ToString() << endl;
	return 0;
}
