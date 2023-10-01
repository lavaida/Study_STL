#include <iostream>
#include <vector>

// std::vector 컨테이너
//- 배열 기반 컨테이너라서 원소가 하나의 메모리 블록에 연속되게 저장된다.
//So, 원소가 추가되거나 삽입될 때 메모리 재할당이 발생할 수 있고 상당한 비용을 지불하게 된다.
//메모리 할당 크기를 알 수 있게 capacity() 함수를 제공하며,
//한 번에 메모리를 예약(할당)하고 사용할 수 있는 reserve() 함수를 제공한다.

int main(void)
{
	std::vector<int> vec;
	std::cout << "size(): " << vec.size() << '\n';
	std::cout << "capacity(): " << vec.capacity() << '\n';
	std::cout << "max_size(): " << vec.max_size() << '\n';

	std::cout << "######################################\n";

	vec.push_back(1);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 1 1
	vec.push_back(2);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 2 2(최소 1 증가)
	vec.push_back(3);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 3 3
	vec.push_back(4);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 4 4
	vec.push_back(5);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 5 6 - [4 + 4/2], 컴파일러마다 메모리 확장 정책이 다르기도 함.
	vec.push_back(6);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 6 6
	vec.push_back(7);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 7 9 - [6 + 6/2]
	vec.push_back(8);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 8 9
	vec.push_back(9);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 9 9
	vec.push_back(10);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 10 13 - [9 + 9/2]

	std::cout << "######################################\n";

	std::vector<int> vec02;
	std::cout << "size(): " << vec02.size() << ", capacity(): " << vec02.capacity() << '\n';

	vec02.reserve(10);	// capacity만 늘림.
	std::cout << "size(): " << vec02.size() << ", capacity(): " << vec02.capacity() << '\n';

	std::cout << "######################################\n";
	std::vector<int> vec03;
	vec03.push_back(1);
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';

	vec03.resize(10);	// capacity를 늘리는 것 뿐만 아니라 Default Constructor를 호출해서 element도 채움.
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';

	vec03.push_back(2);
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';	// 11 15 - [10 + 10/2]


	return 0;
}