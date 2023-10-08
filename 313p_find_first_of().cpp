#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)

bool Predicate(int lhs, int rhs)
{
	return lhs > rhs;
}

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);
	vec01.push_back(4);
	vec01.push_back(5);

	std::vector<int> vec02;
	vec02.push_back(4);
	vec02.push_back(8);
	vec02.push_back(2);

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

	std::cout << "#############################\n";

	std::vector<int>::iterator iter;

	// ��� ���� �� ���� ���Ұ� �ϳ��� �߰ߵǸ� ù ������ �ݺ��ڸ� ��ȯ�Ѵ�.
	iter = std::find_first_of(vec01.begin(), vec01.end(), vec02.begin(), vec02.end());
	if (iter != vec01.end())
	{
		std::cout << *iter << '\n';	// 2, ���� ���ҿ� 4�� ���ԵǾ� ������, ���� ��ġ�� ������ �ݺ��ڸ� ��ȯ�Ѵ�.
	}

	std::cout << "#############################\n";

	iter = std::find_first_of(vec01.begin(), vec01.end(), vec02.begin(), vec02.end(), Predicate);
	if (iter != vec01.end())
	{
		std::cout << *iter << '\n';	// 3, �� �����̳��� ���� ���Ҵ� [2, 4]���� ������ �����ϴ� ���� �ƴϴ�.
	}

	return 0;
}