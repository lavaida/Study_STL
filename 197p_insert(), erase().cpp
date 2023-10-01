#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 4);
	if (iter != vec.end())
	{
		vec.insert(iter, 3);	// �ݺ��ڰ� ����Ű�� ��ġ�� ����(��)�� �߰��ϰ�, �� ĭ�� �ڷ� �δ�.
	}

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << ' ';
	}
	std::cout << '\n';

	std::cout << "################################\n";

	iter = vec.begin();
	for (; iter != vec.end();)
	{
		if ((*iter) % 2 == 0)
		{
			iter = vec.erase(iter);	// �������� ������ ���� ������ ��ġ�� �ش��ϴ� �ݺ��ڰ� ��ȯ�ȴ�.
		}
		else
		{
			++iter;
		}
	}

	iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';

	return 0;
}