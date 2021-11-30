#include "Counter.h"

Counter::Counter()
{
	cout << "Created a new object:\t" << this << "\t" << Counter::counter++ << endl; // counter += 1
}

void Counter::SetCounter(int count)
{
	Counter::counter = count;
}
string Counter::ToString()
{
	stringstream ss;
	ss << "counter:\t" << counter;
	return ss.str();
}
int Counter::counter = 0; // init counter