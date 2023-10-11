#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

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

	std::replace(vec01.begin(), vec01.end(), 0, 3);	// 기존 값 "0" -> 새로운 값 "3"

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 3 3
	}
	std::cout << '\n';

	std::cout << "#################\n";

	std::replace_if(vec01.begin(), vec01.end(), Predicate, 0);	// 조건(2이상 3이하)을 만족하면 새로운 값 "0"으로 변경

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 0 0 0
	}
	std::cout << '\n';

	return 0;
}