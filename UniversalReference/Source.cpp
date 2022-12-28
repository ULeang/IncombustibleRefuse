#include <utility>
#include <iostream>

template<typename T>
void _print(T& t)
{
	std::cout << "lvalue ref\n";
}

template<typename T>
void _print(T&& t)
{
	std::cout << "rvalue ref\n";
}//universal reference

template<typename T>
void print(T&& t)
{
	_print(std::forward<T>(t));
}//universal reference

int main()
{
	int x = 15;
	const int xx = x;
	auto&& xxx = 17;//universal reference
	auto&& xxxx = xxx;//universal reference
	print(x);
	print(xx);
	print(xxx);
	print(std::forward<int>(xxx));
	print(13);
	return 0;
}