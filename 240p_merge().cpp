#include <functional>
#include <list>
#include <iostream>

int main(void)
{
	// merge(): ���ĵ� �� ���� std::list ��ü�� �ϳ��� ���ĵ� ��ü�� �պ��ϴ� ����

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

	//list01.merge(list02);	// ���ĵ� ���� ��ġ�� ���缭 ���Ҹ� �����ִ´�.
	list01.merge(list02, std::less<int>());
	//list01.merge(list02, std::greater<int>());	// ���� ������ ���� ������ Runtime Error

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