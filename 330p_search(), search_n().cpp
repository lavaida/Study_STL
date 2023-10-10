#include <algorithm>
#include <iostream>
#include <vector>

// Non-modifying Algorithms (원소를 수정하지 않는 알고리즘)

bool Predicate(int lhs, int rhs)
{
	return abs(rhs - lhs) <= 10;
}

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);
	vec01.push_back(4);
	vec01.push_back(5);
	vec01.push_back(2);
	vec01.push_back(3);

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


	// find_end(): 일치하는 순차열 중 마지막 순차열의 반복자를 반환.
	// search(): 일치하는 순차열 중 첫 번째 순차열의 반복자를 반환.

	std::vector<int>::iterator iter;
	iter = std::find_end(vec01.begin(), vec01.end(), vec02.begin(), vec02.end());
	if (iter != vec01.end())
	{	
		std::cout << "std::find_end()\n";
		std::cout << "iter-1: " << *(iter - 1) << '\n';	// 5
		std::cout << "iter  : " << *iter << '\n';		// 2
		std::cout << "iter+1: " << *(iter + 1) << '\n';	// 3
	}

	std::cout << "###############\n";
	iter = std::search(vec01.begin(), vec01.end(), vec02.begin(), vec02.end());
	if (iter != vec01.end())
	{
		std::cout << "std::search()\n";
		std::cout << "iter-1: " << *(iter - 1) << '\n';	// 1
		std::cout << "iter  : " << *iter << '\n';		// 2
		std::cout << "iter+1: " << *(iter + 1) << '\n';	// 3
	}

	std::cout << "###############\n";

	std::vector<int> vec11;
	vec11.push_back(10);
	vec11.push_back(20);
	vec11.push_back(30);
	vec11.push_back(40);
	vec11.push_back(30);
	vec11.push_back(30);
	vec11.push_back(30);
	vec11.push_back(50);
	vec11.push_back(30);
	vec11.push_back(30);

	for (size_t i = 0; i < vec11.size(); ++i)
	{
		std::cout << vec11[i] << ' ';
	}
	std::cout << '\n';
	
	std::vector<int>::iterator iter02;
	iter02 = std::search_n(vec11.begin(), vec11.end(), 2, 30);	// 2번 이상 원소값 30이 나온 경우
	if (iter02 != vec11.end())
	{
		std::cout << "iter02-1: " << *(iter02 - 1) << '\n';	// 40
		std::cout << "iter02  : " << *iter02 << '\n';		// 30
		std::cout << "iter02+1: " << *(iter02 + 1) << '\n';	// 30
	}

	std::cout << "###############\n";

	iter02 = std::search_n(vec11.begin(), vec11.end(), 2, 30, Predicate);	// 30과 차가 10이하인 조건, rhs에 원소값 30이 들어감
	if (iter02 != vec11.end())
	{
		std::cout << "iter02-1: " << *(iter02 - 1) << '\n';	// 10
		std::cout << "iter02  : " << *iter02 << '\n';		// 20
		std::cout << "iter02+1: " << *(iter02 + 1) << '\n';	// 30
	}

	return 0;
}