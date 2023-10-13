#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

bool Predicate(int num)
{
	return num < 5;
}

int main(void)
{
	// replace() 알고리즘은 컨테이너 자신의 원소를 변경.
	// replace_copy() 알고리즘은 컨테이너 자신의 원소를 변경한 뒤 그 값으로 다른 컨테이너의 원소를 수정함.

	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(0);
	vec01.push_back(0);
	vec01.push_back(5);

	std::vector<int> vec02(10);	// 수정해서 복사할 원소의 개수보다 많이 할당받아야 한다!!!
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

	std::cout << "수정된 원소: ";

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

	std::cout << "수정된 원소: ";

	iter = vec03.begin();
	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << ' ';	// 3 3 3 3 5
	}
	std::cout << '\n';

	return 0;
}