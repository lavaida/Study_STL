#include <iostream>
#include <vector>

// Modifying Algorithms (원소를 수정하는 알고리즘)

int main(void)
{
	int a = 1;
	int b = 2;
	std::cout << "a: " << a << ", b: " << b << '\n';	// 1 2

	std::swap(a, b);	// 매개변수가 reference!!!
	std::cout << "a: " << a << ", b: " << b << '\n';	// 2 1

	std::cout << "###########################\n";

	std::vector<int> vec01;
	vec01.push_back(10);
	vec01.push_back(15);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 10 15
	}
	std::cout << '\n';

	std::iter_swap(vec01.begin(), vec01.begin() + 1);	// 반복자가 가리키는 원소의 값을 교환한다.

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 15 10
	}
	std::cout << '\n';

	return 0;
}