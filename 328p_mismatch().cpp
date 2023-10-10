#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int lhs, int rhs)
{
	return abs(rhs - lhs) <= 5;
}

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(4);

	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(2);
	vec02.push_back(3);
	vec02.push_back(4);

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

	// 두 순차열을 비교하여 원소의 값이 서로 다른 위치를 찾는 알고리즘.
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> iterPair;
	iterPair = std::mismatch(vec01.begin(), vec01.end(), vec02.begin());

	if (iterPair.first != vec01.end())
	{
		std::cout << "vec01: " << *(iterPair.first) << '\n';	// 4
	}
	else
	{
		std::cout << "vec01.end()\n";	// 순차열이 같거나 비교할 때 먼저 끝나면 end 반복자 반환!
	}

	if (iterPair.second != vec02.end())
	{
		std::cout << "vec02: " << *(iterPair.second) << '\n';	// 3
	}

	std::cout << "########################\n";

	std::vector<int> vec11;
	vec11.push_back(10);
	vec11.push_back(20);
	vec11.push_back(30);

	std::vector<int> vec12;
	vec12.push_back(11);
	vec12.push_back(25);
	vec12.push_back(37);
	vec12.push_back(40);

	for (size_t i = 0; i < vec11.size(); ++i)
	{
		std::cout << vec11[i] << ' ';
	}
	std::cout << '\n';
	for (size_t i = 0; i < vec12.size(); ++i)
	{
		std::cout << vec12[i] << ' ';
	}
	std::cout << '\n';

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> iterPair02;
	iterPair02 = std::mismatch(vec11.begin(), vec11.end(), vec12.begin(), Predicate);	// 5 차이 나면 다른 원소라는 조건

	if (iterPair02.first != vec11.end())
	{
		std::cout << "vec11: " << *(iterPair02.first) << '\n';	// 30
	}
	else
	{
		std::cout << "vec11.end()\n";	// 순차열이 같거나 비교할 때 먼저 끝나면 end 반복자 반환!
	}

	if (iterPair02.second != vec12.end())
	{
		std::cout << "vec12: " << *(iterPair02.second) << '\n';	// 37
	}

	return 0;
}