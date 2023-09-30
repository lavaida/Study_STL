#include <iostream>
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

int main(void)
{
	// 임의 접근 반복자를 가진 std::vector 컨테이너

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::iterator iter = vec.begin();
	std::cout << iter[0] << ' ';
	std::cout << iter[1] << ' ';
	std::cout << iter[2] << '\n';

	iter += 2;
	std::cout << *iter << '\n';

	iter = vec.begin();

	std::vector<int>::iterator iter2 = iter + 2;
	std::cout << *iter2 << '\n';


	return 0;
}