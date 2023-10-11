#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

bool Predicate(int num)
{
	return num < 5;
}

int main(void)
{
	// replace() �˰����� �����̳� �ڽ��� ���Ҹ� ����.
	// replace_copy() �˰����� �����̳� �ڽ��� ���Ҹ� ������ �� �� ������ �ٸ� �����̳��� ���Ҹ� ������.

	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(0);
	vec01.push_back(0);
	vec01.push_back(5);

	std::vector<int> vec02(10);	// �����ؼ� ������ ������ �������� ���� �Ҵ�޾ƾ� �Ѵ�!!!
	std::vector<int> vec03(10);


	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 0 0 5
	}
	std::cout << '\n';
	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 0 0 0 0 0 / 0 0 0 0 0
	}
	std::cout << '\n';
	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';	// 0 0 0 0 0 / 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "#########################################\n";

	std::vector<int>::iterator iterEnd;
	iterEnd = std::replace_copy(vec01.begin(), vec01.end(), vec02.begin(), 0, 3);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 0 0 5
	}
	std::cout << '\n';
	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 1 2 3 3 5 / 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "������ ����: ";

	std::vector<int>::iterator iter;
	iter = vec02.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';	// 1 2 3 3 5
	}
	std::cout << '\n';

	std::cout << "#########################################\n";

	iterEnd = std::replace_copy_if(vec01.begin(), vec01.end(), vec03.begin(), Predicate, 3);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 0 0 5
	}
	std::cout << '\n';
	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';	// 3 3 3 3 5 / 0 0 0 0 0
	}
	std::cout << '\n';

	std::cout << "������ ����: ";

	iter = vec03.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';	// 3 3 3 3 5
	}
	std::cout << '\n';

	return 0;
}