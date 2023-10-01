#include <functional>
#include <list>
#include <iostream>

int main(void)
{
	// merge(): 정렬된 두 개의 std::list 객체를 하나의 정렬된 객체로 합병하는 연산

	std::list<int> list01;
	list01.push_back(3);
	list01.push_back(7);
	list01.push_back(1);
	list01.push_back(5);

	std::list<int> list02;
	list02.push_back(4);
	list02.push_back(6);
	list02.push_back(2);

	list01.sort();
	list02.sort();

	std::cout << "###################\n";

	//list01.merge(list02);	// 정렬된 값의 위치에 맞춰서 원소를 끼워넣는다.
	list01.merge(list02, std::less<int>());
	//list01.merge(list02, std::greater<int>());	// 정렬 기준이 맞지 않으면 Runtime Error

	std::list<int>::iterator iter = list01.begin();
	for (; iter != list01.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	iter = list02.begin();
	for (; iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "###################\n";


	return 0;
}