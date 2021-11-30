#include "Interests.h"

Interests::Interests()
{
	thing = "";
}

Interests::Interests(string thing)
{
	this->thing = thing;
}

Interests::~Interests()
{
	cout << "Interests destriyed:\t" << this << endl;
}

string Interests::GetThing()
{
	return thing;
}

void Interests::SetThing(string thing)
{
	this->thing = thing;
}
