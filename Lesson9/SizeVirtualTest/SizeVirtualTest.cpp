#include <iostream>

class AbstractVirtual {
public:
	virtual void AbstractVirtualMethod() = 0;
};

class DerivedAbstractVirtual : public AbstractVirtual {
public:
	virtual void AbstractVirtualMethod() override {}
};

class Parent {
public:
	void ParentMethod() {}
};

class Derived : public Parent {
public:
	void ParentMethod() {}
};

class Simple {
public:
	void SimpleMEthod() {}
};

class SimpleParent {
public:
	virtual void SimpleMEthod() {}
};

int main()
{
	std::cout << "AbstractVirtual:\t" << sizeof(AbstractVirtual) << std::endl;
	std::cout << "DerivedAbstractVirtual:\t" << sizeof(DerivedAbstractVirtual) << std::endl;
	std::cout << "Parent:\t" << sizeof(Parent) << std::endl;
	std::cout << "Derived:\t" << sizeof(Derived) << std::endl;
	std::cout << "Simple:\t" << sizeof(Simple) << std::endl;
	std::cout << "SimpleParent:\t" << sizeof(SimpleParent) << std::endl;
	return 0;
}
