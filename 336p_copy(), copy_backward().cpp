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

	std::vector<int> vec02(10);	// "0"으로 초기화된 원소 10개(복사할 원소 개수 5개 보다 많아야 한다.)

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

	std::cout << "##################\n";

	// 목적지 순차열로 원소의 값을 복사하고 그 다음 원소를 가리키는 반복자 반환.
	//- 덮어쓰기 모드(overwrite), 삽입 모드(insert)
	//- 모든 알고리즘의 기본 동작은 덮어쓰기 모드이며,
	//반복자 어댑터(insert_iterator) 등을 사용하여 삽입 모드로 동작하게 할 수 있다.
	std::vector<int>::iterator iter;
	iter = std::copy(vec01.begin(), vec01.end(), vec02.begin());
	// [vec02.begin(), vec02.begin() + (vec01.end() - vec01.begin()))
	std::cout << "iter-1: " << *(iter - 1) << '\n';	// 5
	std::cout << "iter  : " << *iter << '\n';		// 0

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


	std::cout << "##################\n";

	std::vector<int> vec03(10);	// 복사할 원소의 개수보다 덮어쓸 공간이 더 커야한다!!!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "##################\n";

	// 순차열의 원소를 뒤쪽 위치에 맞춰 복사하고 원소를 복사하는 처음 위치의 반복자를 반환하는 알고리즘
	iter = std::copy_backward(vec01.begin(), vec01.end(), vec03.end());
	//ex) copy_backward(b, e, t)
	//- [b, e)의 모든 원소를 [t - (e - b), t)의 순차열로 마지막 원소부터 복사를 한다!!!
	//예제의 범위는 [iter, vec03.end())
	std::cout << "iter-1: " << *(iter - 1) << '\n';	// 0
	std::cout << "iter  : " << *iter << '\n';		// 1 
	
	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}