#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int lhs, int rhs)
{
	return lhs <= rhs;
}

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);
	vec01.push_back(4);
	vec01.push_back(2);	// iter
	vec01.push_back(3);
	vec01.push_back(5);

	std::vector<int> vec02;
	vec02.push_back(2);
	vec02.push_back(3);

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
	
	// 일치하는 순차열 중 마지막 순차열의 시작 반복자를 반환!
	iter = std::find_end(vec01.begin(), vec01.end(), vec02.begin(), vec02.end());
	if (iter != vec01.end())
	{
		std::cout << *(iter - 1) << '\n';	// 4
		std::cout << *iter << '\n';			// 2
		std::cout << *(iter + 1) << '\n';	// 3
	}

	std::cout << "#############################\n";

	std::vector<int> vec11;
	vec11.push_back(10);
	vec11.push_back(15);
	vec11.push_back(20);
	vec11.push_back(40);
	vec11.push_back(50);
	vec11.push_back(60);
	vec11.push_back(10);	// iter
	vec11.push_back(11);
	vec11.push_back(12);
	vec11.push_back(80);

	std::vector<int> vec12;
	vec12.push_back(10);
	vec12.push_back(15);
	vec12.push_back(25);

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

	std::cout << "#############################\n";

	iter = std::find_end(vec11.begin(), vec11.end(), vec12.begin(), vec12.end(), Predicate);	// Predicate: lhs <= rhs
	if (iter != vec11.end())
	{
		std::cout << *(iter - 1) << '\n';	// 60
		std::cout << *iter << '\n';			// 10
		std::cout << *(iter + 1) << '\n';	// 11
	}

	return 0;
}