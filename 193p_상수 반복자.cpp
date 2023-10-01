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

	std::vector<int>::const_iterator cIter = vec.begin();
	//*cIter = 10; // Compile Error, 반복자를 통해서 값을 변경할 수 없음.

	for (; cIter != vec.end(); ++cIter)	// 반복자 자체의 값은 변경할 수 있음.
	{
		std::cout << *cIter << ' ';
	}
	std::cout << '\n';


	const std::vector<int>::iterator iter = vec.begin();
	//++iter;	// Compile Error, 반복자 자체를 상수화한 것이라서 변경할 수 없음.

	return 0;
}