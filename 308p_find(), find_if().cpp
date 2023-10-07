#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)

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
	iter = std::find(vec.begin(), vec.end(), 1);	// �տ������� �ش� ���Ұ� �ִ��� �Ǵ�.
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