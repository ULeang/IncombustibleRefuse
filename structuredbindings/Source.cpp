#include <utility>
#include <iostream>

using std::pair;

pair<int, int> divide_remainder(int dividend, int divisor);

int main()
{
	auto [fraction, remainder] = divide_remainder(16, -3);//结构化绑定
	std::cout << fraction << ' ' << remainder << '\n';
	fraction = 10;
	remainder = 5;
	std::cout << fraction << ' ' << remainder << '\n';
	return 0;
}

pair<int, int> divide_remainder(int dividend, int divisor)
{
	return { dividend / divisor, dividend % divisor };
}