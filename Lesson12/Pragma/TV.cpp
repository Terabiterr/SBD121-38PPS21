#include "TV.h"

TV::TV() : _supply(false)
{
	cout << typeid(this).name() << this << endl;
}
void TV::TurnOn()
{
	_supply = true;
}

void TV::TurnOff()
{
	_supply = false;
}

void TV::Display()
{
	if (_supply)
		cout << "Show TV:\t" << endl;
	else
		cout << "TV turn off:\t" << this << endl;
}
