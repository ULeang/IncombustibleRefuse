#include <utility>
#include <vector>
#include <iterator>
#include <iostream>

template<typename Iter>
auto accum_v1(Iter begin, Iter end)
{
	std::remove_cvref_t<decltype(*begin)> res{};//�Ƴ�const��volatile��reference
	for (; begin != end; ++begin)
		res = res + *begin;
	return res;
}//�����汾����ʹ��traits��������bug

template<typename T>
struct accumulation_traits;//���ṩ����

template<>
struct accumulation_traits<int>
{
	using type = long;
	inline static const type zero = 0;
};

template<>
struct accumulation_traits<char>
{
	using type = int;
	inline static const type zero = 0;
};

template<>
struct accumulation_traits<short>
{
	using type = int;
	inline static const type zero = 0;
};

template<>
struct accumulation_traits<unsigned>
{
	using type = unsigned long;
	inline static const type zero = 0;
};

template<>
struct accumulation_traits<float>
{
	using type = double;
	inline static const type zero = 0.f;
};

template<typename Iter>
auto accum_v2(Iter begin, Iter end)
{
	//typename accumulate_traits<std::remove_cvref_t<decltype(*begin)>>::type res{};
	using type = accumulation_traits<std::remove_cvref_t<decltype(*begin)>>::type;
	type res{};
	for (; begin != end; ++begin)
		res = res + *begin;
	return res;
}//v2����ʹ��traits::type

template<typename Iter>
auto accum_v3(Iter begin, Iter end)
{
	using traits = accumulation_traits<std::remove_cvref_t<decltype(*begin)>>;
	auto res = traits::zero;
	for (; begin != end; ++begin)
		res = res + *begin;
	return res;
}//v3��ʹ��traits::type��traits::zero

/*************************************************************************/
//template<typename Iter>
//struct remove_cvrefiterator
//{
//private:
//	Iter* p = nullptr;
//public:
//	using type = std::remove_cvref_t<decltype(**p)>;
//};//��û�б�Ҫdelete���캯���أ�����
////ֻ���ܵ�������Ϊģ�������
//
//template<typename Iter, typename Traits = accumulation_traits<typename remove_cvrefiterator<Iter>::type>>
//auto accum_v4(Iter begin, Iter end)
//{
//	auto res = Traits::zero;
//	for (; begin != end; ++begin)
//		res = res + *begin;
//	return res;
//}//v4��ʹ�ò���������ȡ

template<typename Iter, typename Traits = accumulation_traits<typename std::iterator_traits<Iter>::value_type>>//Iter�ǵ���������sfinae,Ȼ����û����������
auto accum_v4(Iter begin, Iter end)
{
	auto res = Traits::zero;
	for (; begin != end; ++begin)
		res = res + *begin;
	return res;
}//v4��ʹ�ò���������ȡ

int main()
{
	int iarr[]{ 1,2,3,4,5 };
	std::vector viarr{ 7,2,36,14,49 };
	char carr[]{ 'a', 'b', 'c', 'd', 'e' };
	std::cout << accum_v1(iarr, iarr + 5) << std::endl;
	std::cout << accum_v1(viarr.cbegin(), viarr.cend()) << std::endl;
	std::cout << static_cast<int>(accum_v1(carr, carr + 5) / 5) << std::endl;//bug
	std::cout << accum_v2(iarr, iarr + 5) << std::endl;
	std::cout << accum_v2(viarr.cbegin(), viarr.cend()) << std::endl;
	std::cout << static_cast<char>(accum_v2(carr, carr + 5) / 5) << std::endl;//��ȷ
	std::cout << accum_v3(iarr, iarr + 5) << std::endl;
	std::cout << accum_v3(viarr.cbegin(), viarr.cend()) << std::endl;
	std::cout << static_cast<char>(accum_v3(carr, carr + 5) / 5) << std::endl;//��ȷ
	std::cout << accum_v4(iarr, iarr + 5) << std::endl;
	std::cout << accum_v4(viarr.cbegin(), viarr.cend()) << std::endl;
	std::cout << static_cast<char>(accum_v4(carr, carr + 5) / 5) << std::endl;//��ȷ

	return 0;
}