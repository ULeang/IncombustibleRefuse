int not_a_constexpr();

constexpr int a_constexpr(int a)
{
	return a * 2;
}//constexpr����ʹ��ǰ���붨��

int main()
{
	const int i = 10;
	//int arr1[not_a_constexpr()];   //error
	int arr2[a_constexpr(i)];
}

int not_a_constexpr()
{
	return 40;
}