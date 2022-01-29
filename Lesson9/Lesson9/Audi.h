#pragma once
#include "Car.h"

template<class T>
class Audi : public Car<T>
{
public:
	Audi();
	virtual ~Audi() override;
	virtual void SetParams(T, string) override;
	virtual string ToString() override;
};
