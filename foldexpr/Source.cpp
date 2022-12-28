#include <iostream>

template<typename ... Ts>
auto sum_all(const Ts& ... ts)
{
	return (ts + ... + 0);
}

template<typename T, typename ... Ts>
auto sum_all_oldstyle(T arg, Ts ... left_args)
{
	if constexpr (sizeof...(left_args) == 0)
		return arg;
	else
		return arg + sum_all_oldstyle(left_args...);
}//返回auto的函数使用前必须定义

int main()
{
	const int x = 10;
	std::cout << sum_all(x, 3, 2.4, 99, 8.2f) << ' ' << sum_all() << ' ';
	std::cout << sum_all_oldstyle(3, 2.4, 99, 8.2f);
	return 0;
}