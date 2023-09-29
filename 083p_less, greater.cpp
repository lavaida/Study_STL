#include <functional>
#include <iostream>

template <typename T>
class Less
{
public:
	bool operator() (T lhs, T rhs)	// int �ڷ����� ���ؼ��� ������.
	{
		return lhs < rhs;
	}
};

int main(void)
{
	Less<int> less;

	std::cout << less(10, 20) << '\n';
	std::cout << Less<int>()(20, 10) << '\n';
	std::cout << "#######################################\n";

	std::cout << std::less<int>()(10, 20) << '\n';	// template���� ������ Functor, "<>"�� �ٷ�� �ڷ����� �ִ´�.
	std::cout << std::less<int>()(20, 10) << '\n';
	std::cout << "#######################################\n";

	std::cout << std::greater<int>()(10, 20) << '\n';
	std::cout << std::greater<int>()(20, 10) << '\n';
	std::cout << "#######################################\n";



	return 0;
}