#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

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

	// 모든 원소 중 같은 원소가 하나라도 발견되면 첫 원소의 반복자를 반환한다.
	iter = std::find_first_of(vec01.begin(), vec01.end(), vec02.begin(), vec02.end());
	if (iter != vec01.end())
	{
		std::cout << *iter << '\n';	// 2, 같은 원소에 4도 포함되어 있지만, 먼저 위치한 원소의 반복자를 반환한다.
	}

	std::cout << "#############################\n";

	iter = std::find_first_of(vec01.begin(), vec01.end(), vec02.begin(), vec02.end(), Predicate);
	if (iter != vec01.end())
	{
		std::cout << *iter << '\n';	// 3, 두 컨테이너의 같은 원소는 [2, 4]지만 조건을 만족하는 것은 아니다.
	}

	return 0;
}