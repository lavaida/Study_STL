#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int num)
{
	return num > 1;
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	// std::count(): 조건에 맞는 원소의 개수를 세는 기능
	int count = (int)std::count(vec.begin(), vec.end(), 2);	// conversion: __int64 -> int 
	std::cout << "count: " << count << '\n';

	std::cout << "########################\n";

	count = (int)std::count_if(vec.begin(), vec.end(), Predicate);
	std::cout << "count: " << count << "\n\n\n";


	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);

	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(2);
	vec02.push_back(3);
	vec02.push_back(4);
	vec02.push_back(5);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";

	bool bEqual = std::equal(vec01.begin(), vec01.end(), vec02.begin());	// 같은 원소 개수에 대해서 같은지 판단을 한다!
	if (bEqual == true)
	{
		std::cout << "bEqual: " << bEqual << '\n';
	}

	std::cout << "######################\n";


	return 0;
}