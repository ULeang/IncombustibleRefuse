#include <iostream>

class Base
{
public:
	void foo()
	{
		std::cout << "Base\n";
	}

	virtual void foo_2()
	{
		std::cout << "Base_2\n";
	}

	virtual void foo_3()
	{
		std::cout << "Base_3\n";
	}
};

class Derived :public Base
{
public:
	void foo()
	{
		std::cout << "Derived\n";
	}//覆盖了Base的foo

	virtual void foo_2()
	{
		std::cout << "Derived_2\n";
	}//正确的重写

	virtual void foo_3(int a)
	{
		std::cout << "Derived_3\n";
	}//错误的重写,覆盖了Base的foo_3
};

int main()
{
	Base b;
	Derived d;
	b.foo();
	b.foo_2();
	b.foo_3();
	d.foo();
	d.foo_2();
	d.foo_3(1);

	Base* pb = &d;
	pb->foo();//foo不是虚函数，因此调用Base::foo()
	pb->foo_2();//foo_2是虚函数且被重写了，因此调用Derived::foo_2()
	pb->foo_3();//foo_3是虚函数但没有被重写，因此表现如同Base::foo_3()

	return 0;
}