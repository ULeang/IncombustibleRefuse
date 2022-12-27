#include <iostream>

template<typename T, typename U>
class is_same_class
{
public:
	constexpr static bool value = false;
};

template<typename T>
class is_same_class<T,T>
{
public:
	constexpr static bool value = true;
};

int main()
{
	std::cout << is_same_class<int, int&>::value;
	return 0;
}