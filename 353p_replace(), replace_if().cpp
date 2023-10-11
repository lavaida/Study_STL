#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

bool Predicate(int num)
{
	return num >= 2 && num <= 3;
}

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(0);
	vec01.push_back(0);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 0 0
	}
	std::cout << '\n';

	std::replace(vec01.begin(), vec01.end(), 0, 3);	// ���� �� "0" -> ���ο� �� "3"

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 3 3
	}
	std::cout << '\n';

	std::cout << "#################\n";

	std::replace_if(vec01.begin(), vec01.end(), Predicate, 0);	// ����(2�̻� 3����)�� �����ϸ� ���ο� �� "0"���� ����

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 0 0 0
	}
	std::cout << '\n';

	return 0;
}