#include <list>
#include <iostream>

int main(void)
{
	std::list<int> list01;
	list01.push_back(1);
	list01.push_back(2);
	list01.push_back(3);

	std::list<int> list02;
	list02.push_back(10);
	list02.push_back(20);
	list02.push_back(30);

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

	std::cout << "#############################\n";

	iter = list01.begin();
	++iter;

	list01.splice(iter, list02, list02.begin(), --list02.end());	// �ش� �����̳��� range�� �ش��ϴ� ���Ҹ� �ݺ��� ��ġ�� �̵�

	iter = list01.begin();
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

	std::cout << "#############################\n";

	std::list<int> list03;
	list03.push_back(1);
	list03.push_back(2);
	list03.push_back(3);
	list03.push_back(4);
	list03.push_back(5);

	iter = list03.begin();
	for (; iter != list03.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	list03.reverse();	// �������� �ݴ�� ������.

	iter = list03.begin();
	for (; iter != list03.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';


	return 0;
}