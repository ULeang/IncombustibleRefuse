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
	}//������Base��foo

	virtual void foo_2()
	{
		std::cout << "Derived_2\n";
	}//��ȷ����д

	virtual void foo_3(int a)
	{
		std::cout << "Derived_3\n";
	}//�������д,������Base��foo_3
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
	pb->foo();//foo�����麯������˵���Base::foo()
	pb->foo_2();//foo_2���麯���ұ���д�ˣ���˵���Derived::foo_2()
	pb->foo_3();//foo_3���麯����û�б���д����˱�����ͬBase::foo_3()

	return 0;
}