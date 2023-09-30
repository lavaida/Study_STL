#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::size_type i = 0;
	for (; i < vec.size(); ++i)	// 배열의 인덱스로 주로 int 형을 사용했지만, 자료형을 맞춰주는 것이 좋음.
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	std::cout << sizeof(std::vector<int>::size_type) << '\n';	// 8(in x64)
	std::cout << sizeof(size_t) << '\n';						// 8
	std::cout << sizeof(unsigned __int64) << '\n';				// 8

	std::cout << sizeof(unsigned int) << '\n';					// 4(표현 범위가 다르다.)


	return 0;
}