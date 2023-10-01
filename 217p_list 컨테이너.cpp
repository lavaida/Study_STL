#include <iostream>
#include <list>

// std::list 컨테이너
//- std::vector, std::deque 컨테이너처럼 Sequence 컨테이너이기 때문에 원소가 상대적인 순서를 유지하고 있다.
//But, Node 기반 컨테이너라서 원소가 노드 단위로 저장되어 있으며, Doubly linked List로 구현되어 있다.
//그리고 Node 기반 컨테이너라서 Random Access Iterator가 아닌 Bidirectional Iterator를 제공한다.

int main(void)
{
	std::list<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);

	std::list<int>::iterator iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";

	// std::vector, std::deque 컨테이너는 새로운 원소를 추가하는 데 원소를 밀어내는 연산이 필요한 경우가 있지만,
	//std::list 컨테이너는 Sequence 중간에 원소를 Insert/Erase 하더라도 상수 시간 복잡도의 수행 성능을 보여준다.

	std::list<int> list02;
	list02.push_back(1);
	list02.push_back(2);

	std::list<int>::iterator iter021 = list02.begin();
	++iter021;	// 양방향 반복자라서 "+=" 연산을 사용할 수 없음.

	std::list<int>::iterator iter022 = list02.insert(iter021, 3);	// 마지막 위치에 원소 추가는 push_back() 함수를 사용할 것.
	std::cout << "*iter021: " << *iter021 << '\n';
	std::cout << "*iter022: " << *iter022 << '\n';
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	iter022 = list02.insert(iter021, 4);
	std::cout << "*iter021: " << *iter021 << '\n';
	std::cout << "*iter022: " << *iter022 << '\n';
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";
	iter021 = list02.begin();
	++iter021;

	iter022 = list02.end();
	--iter022;

	std::cout << "*iter021: " << *iter021 << '\n';
	iter021 = list02.erase(iter021);
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "*iter021: " << *iter021 << '\n';
	iter021 = list02.erase(iter021);
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	// Array 기반 컨테이너가 아닌 Node 기반 컨테이너라서,
	//원소의 삽입/제거 연산을 수행할 때 메모리가 재할당되거나 원소의 위치가 변경되지 않으므로, 반복자가 유효하다!
	std::cout << "*iter022: " << *iter022 << '\n';

	return 0;
}