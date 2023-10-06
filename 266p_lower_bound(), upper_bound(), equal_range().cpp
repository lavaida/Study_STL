#include <iostream>
#include <set>

int main(void)
{
	// lower_bound(): ã�� ������ ���� �ݺ��ڸ� ��ȯ
	// upper_bound(): ã�� ������ ���� ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
	//So, ã�� ���Ҵ� [lower_bound(), upper_bound()) range�� ���Ѵ�.
	//�׸��� lower_bound() == upper_bound()��� ã�� ���Ұ� ���ٴ� ���� �ǹ��Ѵ�.

	std::multiset<int> multiSet;
	multiSet.insert(1);
	multiSet.insert(2);
	multiSet.insert(2);
	multiSet.insert(3);
	multiSet.insert(3);
	multiSet.insert(3);
	multiSet.insert(4);
	multiSet.insert(5);

	std::multiset<int>::iterator iter = multiSet.begin();
	for (; iter != multiSet.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "####################\n";

	std::multiset<int>::iterator iterLower = multiSet.lower_bound(3);
	std::multiset<int>::iterator iterUpper = multiSet.upper_bound(3);
	if (iterLower != multiSet.end()
		&& iterUpper != multiSet.end())
	{
		std::cout << *iterLower << '\n';
		std::cout << *iterUpper << '\n';

		for (iter = iterLower; iter != iterUpper; ++iter)
		{
			std::cout << *iter << ' ';
		}
		std::cout << '\n';
	}

	std::cout << "####################\n";

	iterLower = multiSet.lower_bound(4);
	iterUpper = multiSet.upper_bound(4);
	if (iterLower != iterUpper)
	{
		std::cout << "�ش� ���� ����\n";
	}

	iterLower = multiSet.lower_bound(6);
	iterUpper = multiSet.upper_bound(6);
	if (iterLower == iterUpper)
	{
		std::cout << "�ش� ���� ����\n";
	}

	std::cout << "####################\n";

	std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> iterPair;
	iterPair = multiSet.equal_range(3);

	if (iterPair.first != multiSet.end()
		&& iterPair.second != multiSet.end())
	{
		std::cout << *(iterPair.first) << '\n';		// first - lower_bound()
		std::cout << *(iterPair.second) << '\n';	// second - upper_bound()

		for (iter = iterPair.first; iter != iterPair.second; ++iter)
		{
			std::cout << *iter << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}