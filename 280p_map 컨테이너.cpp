#include <functional>
#include <iostream>
#include <map>

// std::map 컨테이너
//- Associative 컨테이너로, 원소를 key(std::pair.first)와 value(std::pair.second)의 쌍인 pair 객체를 사용하여 저장한다.
//그리고 중복되지 않은 key를 대상으로 Predicate을 이용해 정렬한다.
//- "[]" 연산자를 이용하여 key에 해당하는 원소의 value에 접근할 수 있다.

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
	pair = map.insert(std::pair<int, int>(1, 500));	// std::map 컨테이너는 중복되지 않은 key의 값을 사용한다.
	if (pair.second == false)
	{
		// key 값이 일치하는 원소의 iterator를 반환한다.
		std::cout << pair.first->first << ", " << pair.first->second << " - 추가 실패\n";	// (1, 100)
	}

	std::cout << "######################\n";

	iter = map.begin();
	for (; iter != map.end();)
	{
		if ((iter->first % 2) == 0)
		{
			iter = map.erase(iter);	// erase(): 다음 원소의 반복자를 반환한다.
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