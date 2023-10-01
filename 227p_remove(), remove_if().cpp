#include <list>
#include <iostream>

bool Predicate(int n)
{
	return n % 2 == 0;
}

class Pred
{
public:
	bool operator() (int n)
	{
		return n > 1;
	}
};

int main(void)
{
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);

	std::list<int>::iterator iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	list.remove(7);	// element ���� ã�Ƽ� ����
	list.remove(8);

	iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	list.remove_if(Predicate);	// �Լ� ������

	iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	list.remove_if(Pred());	// Functor�� �ӽð�ü

	iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "########################\n";

	return 0;
}