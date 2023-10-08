#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int num)
{
	return num > 2;
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator iter;
	iter = std::find(vec.begin(), vec.end(), 1);	// 앞에서부터 해당 원소가 있는지 판단.
	if (iter != vec.end())
	{
		std::cout << "*iter: " << *iter << '\n';
	}

	std::cout << "#####################\n";

	iter = std::find(vec.begin(), vec.end(), 10);
	if (iter != vec.end())
	{
		std::cout << "*iter: " << *iter << '\n';
	}
	
	std::cout << "#####################\n";

	iter = std::find_if(vec.begin(), vec.end(), Predicate);
	if (iter != vec.end())
	{
		std::cout << "*iter: " << *iter << '\n';
	}


	return 0;
}