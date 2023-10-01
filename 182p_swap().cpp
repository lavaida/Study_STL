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

	// �Ҵ�� �޸𸮸� �ǹ��ϴ� capacity�� �ǵ������� �ʱ�ȭ�Ϸ���, �ӽ� ��ü�� ���� ��ȯ�ϴ� ����� ����ؾ� �Ѵ�.
	std::vector<int>().swap(vec);

	std::cout << "size(): " << vec.size() << ", capacity(): " << vec.capacity() << '\n';

	return 0;
}