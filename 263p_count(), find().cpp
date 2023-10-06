#include <iostream>
#include <set>

int main(void)
{
	std::multiset<int> multiSet;	// ������ �ߺ� ���
	multiSet.insert(1);
	multiSet.insert(2);
	multiSet.insert(1);
	multiSet.insert(1);

	std::multiset<int>::iterator iter = multiSet.begin();
	for (; iter != multiSet.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';


	std::cout << "count(1): " << multiSet.count(1) << '\n';
	std::cout << "count(2): " << multiSet.count(2) << '\n';
	std::cout << "count(3): " << multiSet.count(3) << '\n';

	std::cout << "######################\n";

	std::set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);

	std::set<int>::iterator iter02 = set.find(2);
	if (iter02 != set.end())
	{
		std::cout << *iter02 << '\n';
	}

	std::cout << "######################\n";

	// std::set �����̳��� ���Ұ� ���ٴ� ����
	//- Associative �����̳ʴ� ���Ҹ� ã�� �� "==" ������ ������� �ʴ´�.
	//So, !set.key_comp()(a, b) && !set.key_comp()(b, a) == true�� ��츦 ���ٰ� �Ǵ��Ѵ�.

	std::cout << (!(set.key_comp()(1, 2)) && !(set.key_comp()(2, 1))) << '\n';	// false
	std::cout << (!(set.key_comp()(2, 2)) && !(set.key_comp()(2, 2))) << '\n';	// true

	return 0;
}