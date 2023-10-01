#include <functional>
#include <list>
#include <iostream>

class Predicate
{
public:
	bool operator() (int lhs, int rhs)
	{
		return rhs - lhs <= 0;	// ������������ �ߺ��� �����ϱ� ���� ����.
	}
};

int main(void)
{
	// unique(): ������ ���Ҹ� �����ϰ� ����� ����
	std::list<int> list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);	// ������ ���� ���ҿ� �������� �ʱ� ������, �״�� ��������.
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
	list02.push_back(0);	// ���ǿ� �������� �ʾƼ� ���ŵ�.

	list02.unique(Predicate());	// Predicate�� ���̸� ���Ҹ� ����.

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