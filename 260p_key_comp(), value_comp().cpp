#include <functional>
#include <iostream>
#include <set>

int main(void)
{
	std::set<int, std::less<int>> setLess;
	std::set<int, std::greater<int>> setGreater;

	// Predicate을 반환하는 함수들
	// key_comp(), value_comp()

	std::set<int, std::less<int>>::key_compare lessCompare = setLess.key_comp();
	std::cout << lessCompare(10, 20) << '\n';

	std::set<int, std::greater<int>>::key_compare greaterCompare = setGreater.key_comp();
	std::cout << greaterCompare(10, 20) << '\n';

	std::cout << "#######################\n";

	std::cout << typeid(setLess.key_comp()).name() << '\n';
	std::cout << typeid(setLess.value_comp()).name() << '\n';	// std::set 컨테이너는 key가 곧 value이기 때문에 같은 값을 가짐.

	std::cout << typeid(setGreater.key_comp()).name() << '\n';
	std::cout << typeid(setGreater.value_comp()).name() << '\n';

	return 0;
}