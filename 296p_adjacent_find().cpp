#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int lhs, int rhs)
{
	return (lhs == rhs) && (lhs % 2 == 0);
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";
	iter = std::adjacent_find(vec.begin(), vec.end());	// Default: 현재 원소와 다음 원소가 같은 첫 원소의 반복자 반환.

	for (; iter != vec.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";
	iter = std::adjacent_find(vec.begin(), vec.end(), Predicate);	// 조건자를 넣어준 버전.

	for (; iter != vec.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";

	std::vector<int>::iterator iterBegin = vec.begin();
	std::vector<int>::iterator iterEnd = vec.begin() + 2;

	iter = std::adjacent_find(iterBegin, iterEnd);
	if (iter != iterEnd)
	{
		std::cout << "iter != iterEnd: " << *iter << '\n';
	}

	if (iter != vec.end())	// Logical Error, std::adjacent_find() 함수의 수행 범위가 다름!!!
	{
		std::cout << "iter != vec.end(): " << *iter << '\n';
	}

	return 0;
}