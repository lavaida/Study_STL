#include <iostream>
#include <vector>

// Non-modifying Algorithms (���Ҹ� �������� �ʴ� �˰���)

struct Data
{
	int num;
};

bool Compare(const Data &lhs, const Data &rhs)
{
	return lhs.num < rhs.num;
}

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);

	int min = vec[0];
	int max = vec[0];
	for (size_t i = 0; i < vec.size(); ++i)
	{
		min = std::min(min, vec[i]);
		max = std::max(max, vec[i]);
	}

	std::cout << "min: " << min << '\n';
	std::cout << "max: " << max << '\n';

	std::cout << "####################\n";

	max = std::max({10, 20, 30, 40});	// initializer list�� �̿��� ���, ��� ���̴��� �� �𸣰���.
	std::cout << "max: " << max << '\n';

	std::cout << "####################\n";

	Data data01 = { 10 };
	Data data02 = { 20 };

	Data data03 = std::min(data01, data02, Compare);	// std::less�� ���� ������ �ϵ���!
	Data data04 = std::max(data01, data02, Compare);

	std::cout << "data03.num: " << data03.num << '\n';
	std::cout << "data04.num: " << data04.num << '\n';

	return 0;
}