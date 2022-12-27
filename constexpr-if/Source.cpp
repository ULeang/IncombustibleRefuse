#include <vector>
#include <iostream>

template<typename T>
class adda
{
public:
	T var;

	adda(T v) :var(v) {}

	template<typename U>
	T add(const U& to_add)const
	{
		return 1;
	}

	template<>
	T add<std::vector<T>>(const std::vector<T>& to_add)const
	{
		/*auto copy(to_add);
		for (auto& x : copy)
			x += var;
		return copy;*/
		return 2;
	}
};

int main()
{
	int i = 10;
	adda a(i);
	std::cout << a.add(30);
	std::vector vvv{ 10,20,30 };
	std::vector<int>& vvvr=vvv;
	std::cout << a.add(vvv);
	return 0;
}