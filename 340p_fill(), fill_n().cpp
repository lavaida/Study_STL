#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);
	vec01.push_back(4);
	vec01.push_back(5);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 3 4 5
	}
	std::cout << '\n';

	std::fill(vec01.begin(), vec01.end(), 0);	// 해당 반복자 범위의 원소의 값을 "0"으로 채움

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 0 0 0 0 0
	}
	std::cout << '\n';

	std::fill_n(vec01.begin(), 3, 1);	// vec01.begin()부터 "3"개의 원소의 값을 "1"로 채움

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 1 1 0 0
	}
	std::cout << '\n';

	return 0;
}