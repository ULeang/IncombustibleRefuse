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
	int& xxxxx = x;
	print(x);
	print(xx);
	print(xxx);
	print(std::forward<int>(xxxxx));//左值引用->右值引用
	print(std::forward<int>(xxx));//右值引用->右值引用
	print(std::forward<int>(x));//非引用左值->右值引用
	print(std::forward<int>(1));//非引用右值->右值引用
	//实际上，forward的结果仅由其模板参数（这里即int）确定（T->T&&,T&->T&），在不需要转发的地方使用forward非常意义不明
	print(13);
	return 0;
}