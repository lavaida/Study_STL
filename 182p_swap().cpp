#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';

	// 할당된 메모리를 의미하는 capacity를 의도적으로 초기화하려면, 임시 객체를 만들어서 교환하는 방법을 사용해야 한다.
	std::vector<int>().swap(vec);

	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';

	return 0;
}