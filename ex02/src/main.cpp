#include <iostream>
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int r = (rand() % 3);
	Base * ret;
	if (r == 0)
		ret = new A();
	if (r == 1)
		ret = new B();
	if (r == 2)
		ret = new C();
	if (!ret)
		std::cerr << "error : allocation of a new element failed." << std::endl;
	return (ret);
}

size_t	getType(Base *p)
{
	A *a;
	a = dynamic_cast<A*>(p);
	if (a)
		return (0);
	B *b;
	b = dynamic_cast<B*>(p);
	if (b)
		return (1);
	C *c;
	c = dynamic_cast<C*>(p);
	if (c)
		return (2);
	return (3);
}

void	identify(Base *p)
{
	std::string className[4] = {"A", "B", "C", "Unknown"};
	size_t 		type = getType(p);
	std::cout << "ptr Base's type is -> " << className[type] << std::endl;
}

void	identify(Base &p)
{
	std::string className[4] = {"A", "B", "C", "Unknown"};
	size_t 		type = getType(&p);
	std::cout << "ref Base's type is -> " << className[type] << std::endl;
}

int main ()
{
	srand(time(NULL));
	Base *base;
	for (size_t i = 0; i < 5; i++)
	{
		base = generate();
		if (!base)
			return (1);
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	base = 0;
	identify(base);
	identify(*base);
	return (0);
}
