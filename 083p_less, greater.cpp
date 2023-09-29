#include <functional>
#include <iostream>

template <typename T>
class Less
{
public:
	bool operator() (T lhs, T rhs)	// int 자료형에 대해서만 가능함.
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

	std::cout << std::less<int>()(10, 20) << '\n';	// template으로 구현된 Functor, "<>"에 다루는 자료형을 넣는다.
	std::cout << std::less<int>()(20, 10) << '\n';
	std::cout << "#######################################\n";

	std::cout << std::greater<int>()(10, 20) << '\n';
	std::cout << std::greater<int>()(20, 10) << '\n';
	std::cout << "#######################################\n";



	return 0;
}