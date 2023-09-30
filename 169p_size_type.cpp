#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::size_type i = 0;
	for (; i < vec.size(); ++i)	// �迭�� �ε����� �ַ� int ���� ���������, �ڷ����� �����ִ� ���� ����.
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	std::cout << sizeof(std::vector<int>::size_type) << '\n';	// 8(in x64)
	std::cout << sizeof(size_t) << '\n';						// 8
	std::cout << sizeof(unsigned __int64) << '\n';				// 8

	std::cout << sizeof(unsigned int) << '\n';					// 4(ǥ�� ������ �ٸ���.)


	return 0;
}