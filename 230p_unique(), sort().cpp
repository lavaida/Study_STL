#include <functional>
#include <list>
#include <iostream>

class Predicate
{
public:
	bool operator() (int lhs, int rhs)
	{
		return rhs - lhs <= 0;	// 오름차순으로 중복을 제거하기 위한 조건.
	}
};

int main(void)
{
	// unique(): 인접한 원소를 유일하게 만드는 연산
	std::list<int> list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);	// 동일한 값의 원소와 인접하지 않기 때문에, 그대로 남아있음.
	list.push_back(3);
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);
	list.push_back(5);

	list.unique();

	std::list<int>::iterator iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	std::list<int> list02;
	list02.push_back(1);
	list02.push_back(1);
	list02.push_back(2);
	list02.push_back(1);
	list02.push_back(3);
	list02.push_back(3);
	list02.push_back(4);
	list02.push_back(4);
	list02.push_back(5);
	list02.push_back(0);	// 조건에 만족하지 않아서 제거됨.

	list02.unique(Predicate());	// Predicate이 참이면 원소를 지움.

	iter = list02.begin();
	for (; iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";
	std::list<int> list03;
	list03.push_back(1);
	list03.push_back(2);
	list03.push_back(3);
	list03.push_front(3);
	list03.push_front(4);
	list03.push_front(5);

	iter = list03.begin();
	for (; iter != list03.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	list03.sort();	// Default: Ascending Order

	iter = list03.begin();
	for (; iter != list03.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';


	list03.sort(std::greater<int>());	// std::greater(): Descending Order

	iter = list03.begin();
	for (; iter != list03.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	return 0;
}