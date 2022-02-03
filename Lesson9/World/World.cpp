#include <iostream>
#include <string>

class World
{
public:
	virtual std::string Print() = 0;
};

class Australia : public World { virtual std::string Print() override { return typeid(this).name(); } };
class Africa : public World { virtual std::string Print() override { return typeid(this).name(); } };
class Antarctica : public World { virtual std::string Print() override { return typeid(this).name(); } };
class NorthAmerica : public World { virtual std::string Print() override { return typeid(this).name(); } };
class SouthAmerica : public World { virtual std::string Print() override { return typeid(this).name(); } };
class Eurasia : public World { virtual std::string Print() override { return typeid(this).name(); } };
class Europe : public World { virtual std::string Print() override { return typeid(this).name(); } };
class Asia : public World { virtual std::string Print() override { return typeid(this).name(); } };

void Print(World* world) noexcept
{
	std::cout << world->Print() << std::endl;
}

int main()
{
	Print(new Australia);
	Print(new Africa);
	Print(new Antarctica);
	Print(new NorthAmerica);
	Print(new SouthAmerica);
	Print(new Eurasia);
	Print(new Europe);
	Print(new Asia);
	return 0;
}

