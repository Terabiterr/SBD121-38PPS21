#pragma once
#include "Car.h"

template<class T>
class BMW : public Car<T>
{
public:
	BMW();
	virtual ~BMW() override;
	virtual void SetParams(T, string) override;
	virtual string ToString() override;
};

