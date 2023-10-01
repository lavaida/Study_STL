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
	//*cIter = 10; // Compile Error, �ݺ��ڸ� ���ؼ� ���� ������ �� ����.

	for (; cIter != vec.end(); ++cIter)	// �ݺ��� ��ü�� ���� ������ �� ����.
	{
		std::cout << *cIter << ' ';
	}
	std::cout << '\n';


	const std::vector<int>::iterator iter = vec.begin();
	//++iter;	// Compile Error, �ݺ��� ��ü�� ���ȭ�� ���̶� ������ �� ����.

	return 0;
}