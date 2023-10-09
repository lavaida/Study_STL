#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);

	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(3);

	std::vector<int> vec03;
	vec03.push_back(1);
	vec03.push_back(2);

	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';
	}
	std::cout << '\n';

	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	// ���ڿ� ��ó�� �������� ������ ��(less: <)�� �ʿ��� �� ����ϴ� �˰���

	//if (std::lexicographical_compare(vec01.begin(), vec01.end(), vec02.begin(), vec02.end(), std::less<int>()))
	if (std::lexicographical_compare(vec01.begin(), vec01.end(), vec02.begin(), vec02.end()))	// Default: std::less
	{
		std::cout << "vec01 < vec02\n";	// 2 < 3
	}

	if (std::lexicographical_compare(vec01.begin(), vec01.end(), vec03.begin(), vec03.end()) == false)
	{
		std::cout << "vec01 >= vec03\n";	// �������� �����Ƿ� false ��ȯ.
	}

	return 0;
}