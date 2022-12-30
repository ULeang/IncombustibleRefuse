#include <type_traits>
#include <iostream>

template<typename T>
struct is_pointer :std::false_type {};

template<typename T>
struct is_pointer<T*> :std::true_type {};

template<typename T>
void foo(const T& t)
{
	if constexpr (is_pointer<T>::value)
		std::cout << *t;
	else
		std::cout << t;
}

int main()
{
	int* ip;
	int i;
	const int* cip;
	const int ci = 10;
	std::cout << is_pointer<decltype(ip)>::value;
	std::cout << is_pointer<decltype(i)>::value;
	std::cout << is_pointer<decltype(cip)>::value;
	std::cout << is_pointer<decltype(ci)>::value;

	char c[2] = "a";
	foo(c);
	foo(1);

	return 0;
}