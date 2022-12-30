#include <iostream>
#include <type_traits>

template<typename T, typename U>
class is_same_class
{
public:
	constexpr static bool value = false;
};

template<typename T>
class is_same_class<T, T>
{
public:
	constexpr static bool value = true;
};

//new style
template<typename T, typename U>
struct is_same :std::false_type {};

template<typename T>
struct is_same<T, T> :std::true_type {};

int main()
{
	std::cout << is_same_class<int, int&>::value;
	std::cout << is_same<int, int&>::value;
	return 0;
}