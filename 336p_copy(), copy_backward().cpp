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

	std::vector<int> vec02(5);

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




	return 0;
}