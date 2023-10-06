#include <functional>
#include <iostream>
#include <map>

// std::map �����̳�
//- Associative �����̳ʷ�, ���Ҹ� key(std::pair.first)�� value(std::pair.second)�� ���� pair ��ü�� ����Ͽ� �����Ѵ�.
//�׸��� �ߺ����� ���� key�� ������� Predicate�� �̿��� �����Ѵ�.
//- "[]" �����ڸ� �̿��Ͽ� key�� �ش��ϴ� ������ value�� ������ �� �ִ�.

int main(void)
{
	std::map<int, int, std::less<int>> map;	// Default Predicate: std::less(), Ascending Order

	map.insert(std::pair<int, int>(1, 100));
	map.insert(std::pair<int, int>(2, 200));
	map.insert(std::pair<int, int>(3, 300));
	map.insert(std::pair<int, int>(4, 400));
	map.insert(std::pair<int, int>(5, 500));

	std::map<int, int>::iterator iter = map.begin();
	for (; iter != map.end(); ++iter)
	{
		std::cout << (*iter).first << ", " << iter->second << '\n';
	}

	std::cout << "######################\n";

	std::pair<std::map<int, int>::iterator, bool> pair;
	pair = map.insert(std::pair<int, int>(1, 500));	// std::map �����̳ʴ� �ߺ����� ���� key�� ���� ����Ѵ�.
	if (pair.second == false)
	{
		// key ���� ��ġ�ϴ� ������ iterator�� ��ȯ�Ѵ�.
		std::cout << pair.first->first << ", " << pair.first->second << " - �߰� ����\n";	// (1, 100)
	}

	std::cout << "######################\n";

	iter = map.begin();
	for (; iter != map.end();)
	{
		if ((iter->first % 2) == 0)
		{
			iter = map.erase(iter);	// erase(): ���� ������ �ݺ��ڸ� ��ȯ�Ѵ�.
		}
		else
		{
			++iter;
		}
	}

	iter = map.begin();
	for (; iter != map.end(); ++iter)
	{
		std::cout << (*iter).first << ", " << iter->second << '\n';
	}

	return 0;
}