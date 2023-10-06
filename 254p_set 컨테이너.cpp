#include <functional>
#include <iostream>
#include <set>

// std::set 컨테이너
//- Associative(연관) 컨테이너 중의 하나로, key라 불리는 중복되지 않은 원소(value)의 집합으로 구성된다.
//또한 Node 기반 컨테이너이며, 주로 AVL 중 Red-black tree로 구현된다.
//즉, Node 기반이기 때문에 back(), push_back(), pop_back()과 같은 함수를 제공하지 않는다.
//기본적인 Predicate은 std::less() 오름차순으로 정렬된다.
//- 중복을 허용하는 std::multiset 컨테이너도 있다.

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

	// std::set::insert() 함수에서 반환되는 std::pair 객체는 원소 추가 여부를 확인할 수 있다.
	std::pair<std::set<int>::iterator, bool> pair;
	pair = set03.insert(1);
	if (pair.second == true)
	{
		std::cout << *(pair.first) << " - 원소 추가 성공\n";
	}

	pair = set03.insert(1);
	if (pair.second == false)
	{
		std::cout << *(pair.first) << " - 원소 추가 실패\n";
	}

	return 0;
}