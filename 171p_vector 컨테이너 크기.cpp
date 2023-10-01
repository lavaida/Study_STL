#include <iostream>
#include <vector>

// std::vector �����̳�
//- �迭 ��� �����̳ʶ� ���Ұ� �ϳ��� �޸� ��Ͽ� ���ӵǰ� ����ȴ�.
//So, ���Ұ� �߰��ǰų� ���Ե� �� �޸� ���Ҵ��� �߻��� �� �ְ� ����� ����� �����ϰ� �ȴ�.
//�޸� �Ҵ� ũ�⸦ �� �� �ְ� capacity() �Լ��� �����ϸ�,
//�� ���� �޸𸮸� ����(�Ҵ�)�ϰ� ����� �� �ִ� reserve() �Լ��� �����Ѵ�.

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
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 2 2(�ּ� 1 ����)
	vec.push_back(3);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 3 3
	vec.push_back(4);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 4 4
	vec.push_back(5);
	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';	// 5 6 - [4 + 4/2], �����Ϸ����� �޸� Ȯ�� ��å�� �ٸ��⵵ ��.
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

	vec02.reserve(10);	// capacity�� �ø�.
	std::cout << "size(): " << vec02.size() << ", capacity(): " << vec02.capacity() << '\n';

	std::cout << "######################################\n";
	std::vector<int> vec03;
	vec03.push_back(1);
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';

	vec03.resize(10);	// capacity�� �ø��� �� �Ӹ� �ƴ϶� Default Constructor�� ȣ���ؼ� element�� ä��.
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';

	vec03.push_back(2);
	std::cout << "size(): " << vec03.size() << ", capacity(): " << vec03.capacity() << '\n';	// 11 15 - [10 + 10/2]


	return 0;
}