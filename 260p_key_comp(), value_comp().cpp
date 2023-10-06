#include <functional>
#include <iostream>
#include <set>

int main(void)
{
	std::set<int, std::less<int>> setLess;
	std::set<int, std::greater<int>> setGreater;

	// Predicate�� ��ȯ�ϴ� �Լ���
	// key_comp(), value_comp()

	std::set<int, std::less<int>>::key_compare lessCompare = setLess.key_comp();
	std::cout << lessCompare(10, 20) << '\n';

	std::set<int, std::greater<int>>::key_compare greaterCompare = setGreater.key_comp();
	std::cout << greaterCompare(10, 20) << '\n';

	std::cout << "#######################\n";

	std::cout << typeid(setLess.key_comp()).name() << '\n';
	std::cout << typeid(setLess.value_comp()).name() << '\n';	// std::set �����̳ʴ� key�� �� value�̱� ������ ���� ���� ����.

	std::cout << typeid(setGreater.key_comp()).name() << '\n';
	std::cout << typeid(setGreater.value_comp()).name() << '\n';

	return 0;
}