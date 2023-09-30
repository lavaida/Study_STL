#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>


// 1. Container(컨테이너)
//- 같은 타입의 데이터를 저장/관리할 목적으로 만들어진 클래스 객체.
//
// case 01. Standard Sequence Container(표준 시퀀스 컨테이너)
//- 컨테이너의 원소가 자신만의 삽입 위치(순서)를 가지는 컨테이너
//ex) std::vector, std::deque, std::list - 선형적 
// case 02. Standard Associative Container(표준 연관 컨테이너)
//- 저장되는 원소가 삽입 순서와 다르게 특정 정렬 기준에 의해 자동 정렬되는 컨테이너
//ex) std::set, std::multiset, std::map, std::multimap - 비선형적
//
// case 03. Array-based Container(배열 기반 컨테이너)
//- 데이터 여러 개가 하나의 메모리 단위에 저장되는 컨테이너
//ex) std::vector, std::deque
// case 04. Node-based Container(노드 기반 컨테이너)
//- 데이터 하나를 하나의 메모리 단위에 저장하는 컨테이너
//ex) std::list, std::set, std::multiset, std::map, std::multimap

// ###################################################################################
// 2. Iterator(반복자)
//- 포인터와 비슷하게 동작하며, 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공한다.
//즉, 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할을 한다.
//cf) 컨테이너 원소의 집합을 Sequence(순차열)이라고 한다.
//원소의 순서 있는 집합을 의미하는데, 하나의 시작과 하나의 끝을 갖는다.
//여기서 반복자는 순차열의 한 원소를 가리킨다.
//- STL의 모든 컨테이너는 자신만의 반복자를 제공하는데, 멤버 함수 begin()과 end()가
//순차열의 시작과 끝을 가리키는 반복자를 반환한다.
//- 순차열의 시작과 끝에서 끝은 실제 원소가 아닌 끝을 표시(past-the-end)하는 원소를 의미한다.
//이 begin과 end를 range(구간)라고 하며, 수학에서 표기하는 방법을 사용해
// half-open range(반개 구간)을 [begin, end)처럼 표기한다.

// case 01. Input Iterator(입력 반복자)
//- 현 위치의 원소를 한 번만 읽을 수 있는 반복자. ex) istream
// case 02. Output Iterator(출력 반복자)
//- 현 위치의 원소를 한 번만 쓸 수 있는 반복자. ex) ostream
// case 03. Forward Iterator(순방향 반복자)
//- 입력, 출력 반복자 기능에 순방향으로 이동(++)이 가능한 재할당될 수 있는 반복자
// case 04. Bidirectional Iterator(양방향 반복자)
//- 순방향 반복자 기능에 역방향으로 이동(--)이 가능한 반복자. ex) std::list, std::set, std::multiset, std::map, std::multimap
// case 05. Random Access Iterator(임의 접근 반복자)
//- 양방향 반복자 기능에 +, -, +=, -=, [] 연산이 가능한 반복자 ex) std::vector, std::deque

// ###################################################################################
// 3. Algorithm(알고리즘)
//- STL은 순차열의 원소를 조사/변경/관리/처리할 목적으로 알고리즘이라는 구성 요소를 제공한다.
//한 쌍의 반복자([begin, end))를 필요로 하고, 대부분은 순방향 반복자를 요구하지만 몇몇은 임의 접근 반복자를 요구한다.

// case 01. Non-modifying Algorithms(원소를 수정하지 않는 알고리즘)
// case 02. Modifying Algorithms(원소를 수정하는 알고리즘)
// case 03. Removing Algorithms(제거 알고리즘)
// case 04. Mutating Algorithms(변경 알고리즘)
// case 05. Sorting Algorithms(정렬 알고리즘)
// case 06. Sorted Range Algorithms(정렬된 범위 알고리즘)
// case 07. Numeric Algorithms(수치 알고리즘)

// ###################################################################################
// 4. Function Object(함수 객체), Functor
//- 클라이언트가 정의한 동작을 다른 구성 요소에 반영하려 할 때 사용된다.
//(STL 알고리즘이 함수 객체, 함수, 함수 포인터 등을 인자로 받아 알고리즘을 유연하게 동작시킨다.)

// ###################################################################################
// 5. Adapter(어댑터)
//- STL 구성 요소의 인터페이스를 변경하는데 쓰인다.

// case 01. Container Adapter(컨테이너 어댑터)
//- std::stack, std::queue, std::priority_queue
// case 02. Iterator Adapter(반복자 어댑터)
//- std::reverse_iterator, std::back_insert_iterator, std::front_insert_iterator, std::insert_iterator
// case 03. Function Adapter(함수 어댑터)
//- binder(바인더), negator(부정자), adapter for pointers to functions(함수 포인터 어댑터)

//ex) stack
//- 일반 컨테이너를 LIFO(Last-In First-Out) 방식의 컨테이너로 변환한다.
//(empty, size, push_back, pop_back, back, 인터페이스(멤버 함수)를 지원하는 컨테이너를 대상으로 한다.
//So, Sequence 컨테이너를 대상으로 한다. Default 컨테이너는 std::deque 컨테이너.)

//ex) reverse_iterator
//- 일반 반복자의 동작 방식을 반대로 동작시키는 역방향 반복자로 변환한다.

//ex) not2
//- 이항 Predicate(조건자) 함수 객체를 NOT(반대)로 변환한다.

// ###################################################################################
// 6. Allocator(할당자)
//- 메모리 할당 정보와 정책(메모리 할당 모델)을 캡슐화한 STL 구성 요소.
//템플릿 클래스로 구현되어 있고, 모든 컨테이너는 기본 할당자를 사용한다.
//(new와 delete 연산을 오버로딩해서 사용할 수 있듯이 할당자도 직접 정의할 수 있다.
//So, 다중 쓰레드에 최적화되고 안전한 사용자 메모리 할당 모델이 필요하거나 사용자가 컨테이너에 맞는
// 메모리 할당 모델을 설계하거나 특정 구현 환경에서 최적화된 메모리 할당 모델을 구축하는 등에 사용된다.)


int main(void)
{
	// 임의 접근 반복자를 가진 std::vector 컨테이너

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::iterator iter = vec.begin();
	std::cout << iter[0] << ' ';	// [] 연산자
	std::cout << iter[1] << ' ';
	std::cout << iter[2] << '\n';

	iter += 2;	// += 연산자
	std::cout << *iter << '\n';

	iter = vec.begin();

	std::vector<int>::iterator iter2 = iter + 2;	// + 연산자
	std::cout << *iter2 << '\n';

	std::cout << "##################################\n";

	// find 알고리즘 - 순방향 반복자를 요구함.
	iter = find(vec.begin(), vec.end(), 2);
	if (iter != vec.end())
	{
		std::cout << *iter << '\n';
	}

	iter = find(vec.begin(), vec.end(), 5);
	if (iter == vec.end())
	{
		std::cout << "없는 원소\n";
	}

	std::cout << "##################################\n";

	// sort 알고리즘 - 임의 접근 반복자를 요구함.
	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(5);
	vec02.push_back(2);
	vec02.push_back(4);
	vec02.push_back(3);

	// 함수 객체 std::less, std::greater
	std::sort(vec02.begin(), vec02.end(), std::less<int>());	// 오름차순(Ascending Order)

	std::vector<int>::iterator iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	std::sort(vec02.begin(), vec02.end(), std::greater<int>());	// 내림차순(Descending Order)

	iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	std::cout << "##################################\n";

	// Container Adapter
	std::stack<int, std::vector<int>> stack;	// Default는 std::deque 컨테이너

	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.top() << '\n';
	stack.pop();
	std::cout << stack.top() << '\n';
	stack.pop();
	std::cout << stack.top() << '\n';
	stack.pop();

	if (stack.empty() == true)
	{
		std::cout << "stack.empty() == true\n";
	}
	else
	{
		stack.pop();	// 만약 원소가 없는데 pop() 함수 호출하면 Runtime Error 발생.
	}

	std::cout << "##################################\n";

	iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	// Iterater Adapter
	//- 역방향 반복자는 반복자가 가리키는 원소와 실제 가리키는 값이 다르다!
	//반복자가 가리키는 원소의 다음 원소의 값을 참조한다.
	//Because, 순차열의 구간(range)이 반개 구간([begin, end))이므로 알고리즘 수행 시
	//정방향 반복자와 호환이 되도록 설계되었기 때문에!!!
	//	begin(1) end(ㅁ)
	// ㅁ 1 2 3 4 5 ㅁ
	// rIterEnd(ㅁ) rIter(5)
	std::reverse_iterator<std::vector<int>::iterator> rIter(vec02.end());
	std::reverse_iterator<std::vector<int>::iterator> rIterEnd(vec02.begin());
	// 물론, 컨테이너 자체에서 역방향 반복자를 제공한다.
	std::vector<int>::reverse_iterator rIter02 = vec02.rbegin();
	std::vector<int>::reverse_iterator rIterEnd02 = vec02.rend();

	if (rIter == rIter02
		&& rIterEnd == rIterEnd02)
	{
		// Iterator Adapter를 기본적으로 제공하고 있음.
		std::cout << "rIter == rIter02\n";
		std::cout << "rIterEnd == rIterEnd02\n";
	}

	rIter = vec02.rbegin();
	for (; rIter != vec02.rend(); ++rIter)
	{
		std::cout << *rIter << ' ';
	}
	std::cout << '\n';

	std::cout << "##################################\n";

	std::vector<int> vec03;
	vec03.push_back(1);
	vec03.push_back(2);
	vec03.push_back(3);
	vec03.push_back(4);
	vec03.push_back(5);

	std::vector<int>::iterator normalIter = vec03.begin() + 3;
	std::vector<int>::reverse_iterator reverseIter(normalIter);

	// "--" 연산자를 사용하지 않고 "++" 연산자만으로 정방향, 역방향의 순회가 모두 가능하게 설계되어 있다.
	std::cout << "정방향 반복자: " << *normalIter << '\n';	// 4 가리킴
	std::cout << "역방향 반복자: " << *reverseIter << '\n';	// 3 가리킴!!!


	return 0;
}