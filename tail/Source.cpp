#include <iostream>

int fact(unsigned u, unsigned aaa = 1);

int main(void)
{
	unsigned a = fact(10);
	std::cout << a;
}

int fact(unsigned u, unsigned aaa)
{
	if (u == 0 || u == 1)
		return aaa;
	return fact(u - 1, aaa * u);
}