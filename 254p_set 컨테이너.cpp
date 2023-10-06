#include <functional>
#include <iostream>
#include <set>

// std::set �����̳�
//- Associative(����) �����̳� ���� �ϳ���, key�� �Ҹ��� �ߺ����� ���� ����(value)�� �������� �����ȴ�.
//���� Node ��� �����̳��̸�, �ַ� AVL �� Red-black tree�� �����ȴ�.
//��, Node ����̱� ������ back(), push_back(), pop_back()�� ���� �Լ��� �������� �ʴ´�.
//�⺻���� Predicate�� std::less() ������������ ���ĵȴ�.
//- �ߺ��� ����ϴ� std::multiset �����̳ʵ� �ִ�.

int main(void)
{
	std::set<int> set;	// Default: Ascending Order
	set.insert(1);
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(3);
	set.insert(4);
	set.insert(5);

	std::set<int>::iterator iter = set.begin();
	for (; iter != set.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "####################\n";

	std::set<int, std::greater<int>> set02;	// Descending Order
	set02.insert(1);
	set02.insert(2);
	set02.insert(3);

	iter = set02.begin();
	for (; iter != set02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "####################\n";

	std::set<int> set03;

	// std::set::insert() �Լ����� ��ȯ�Ǵ� std::pair ��ü�� ���� �߰� ���θ� Ȯ���� �� �ִ�.
	std::pair<std::set<int>::iterator, bool> pair;
	pair = set03.insert(1);
	if (pair.second == true)
	{
		std::cout << *(pair.first) << " - ���� �߰� ����\n";
	}

	pair = set03.insert(1);
	if (pair.second == false)
	{
		std::cout << *(pair.first) << " - ���� �߰� ����\n";
	}

	return 0;
}